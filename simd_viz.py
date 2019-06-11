#!/usr/bin/env python3

import random
import re
import argparse

import clang.cindex
from clang.cindex import Index
from clang.cindex import Config

from graphviz import Digraph

ARM_NEON_TYPE_PATTERN = r'(int|uint|float|poly)(\d+)x(\d+)_t'


def arm_neon_match(var_type):
    return re.match(ARM_NEON_TYPE_PATTERN, var_type)


def add_var_node(graph, node_id, var_name, var_type):
    style = "solid"
    # NOTE: tmp lane
    if var_name == "":
        style = "dotted"
    arm_neon_type_result = arm_neon_match(var_type)
    if arm_neon_type_result:
        base_type = arm_neon_type_result.group(1)
        base_bits = int(arm_neon_type_result.group(2))
        base_num = int(arm_neon_type_result.group(3))
        # NOTE: first element stands for type
        # label = (base_type + base_bits) + ("|" * (int(base_num) - 1))
        # NOTE: sequence of "　" stands for type size
        label = "|".join(["　" * int(base_bits / 8)] * base_num)
        xlabel = "{0} {1}".format(var_type, var_name)
        graph.node(node_id, shape="record", color="black", style=style, label=label, xlabel=xlabel)
    else:
        graph.node(node_id, shape="circle", color="black", style=style, label=var_name)


class ClangSIMDVizParser:
    def __init__(self, filepath, main_graph, verbose=False):
        self.filepath = filepath
        self.graph_list = list()
        self.graph_list.append(main_graph)
        self.verbose = verbose
        self.index = Index.create()
        args = ['-nobuiltininc']
        self.tu = self.index.parse("", [filepath, *args])
        if not self.tu:
            parser.error("unable to load input")

    def parse_simd_code(self):
        def _lambda(parent, node, top_id):
            if (str(node.extent.start.file) != self.filepath):
                return top_id
            # NOTE: new subgraph for function
            if node.kind.name == "COMPOUND_STMT" and parent and parent.kind.name == "FUNCTION_DECL":
                func_name = parent.spelling
                graph = Digraph(name='cluster_' + func_name)
                graph.attr(label=func_name)
                self.graph_list.append(graph)
            graph = self.graph_list[-1]
            # NOTE: for debug only
            if node.kind.name not in ["TYPE_REF", "PARM_DECL", "FUNCTION_DECL", "FIELD_DECL", "TYPEDEF_DECL", "TYPE_ALIAS_DECL", "STRUCT_DECL", "INTEGER_LITERAL"]:
                if self.verbose:
                    print(node, node.spelling, node.type.kind, node.type.spelling, node.kind.name)
            if node.kind.name == "VAR_DECL":
                var_name = node.spelling
                var_type = node.type.spelling
                # TODO: use list or regexp
                arm_neon_type_result = arm_neon_match(var_type)
                current_id = var_name
                if top_id != "":
                    graph.edge(top_id, current_id, label="")
                add_var_node(graph, current_id, var_name, var_type)
                return current_id
            if node.kind.name == "DECL_REF_EXPR":
                if str(node.type.kind) == "TypeKind.FUNCTIONPROTO":
                    func_name = node.spelling
                    var_type = node.type.spelling
                # NOTE: 引数の変数もここに引っかかる
                if str(node.type.kind) in ["TypeKind.TYPEDEF", "TypeKind.POINTER", "TypeKind.CONSTANTARRAY"]:
                    var_name = node.spelling
                    var_type = node.type.spelling
                    current_id = var_name
                    if top_id != "":
                        # NOTE: top_id includes function name
                        # NOTE: vst*** is store function, so reverse arrow
                        arm_neon_type_result = arm_neon_match(var_type)
                        if "vst" in top_id and not arm_neon_type_result:
                            graph.edge(top_id, current_id, label="")
                        else:
                            graph.edge(current_id, top_id, label="")
            if node.kind.name == "CALL_EXPR":
                var_name = ""
                func_name = node.spelling
                # NOTE: this function return value
                ret_type = node.type.spelling
                current_id = func_name + str(random.random())

                # NOTE: for non decl assign
                # NOTE: e.g. lane_a = vld1_u8(a);
                if parent:
                    if parent.kind.name == "BINARY_OPERATOR":
                        # FYI: [pycparserを使ってみた/libclang\+sealangでPythonでC\+\+をパースする \- 何らかのブログ]( http://censored.hateblo.jp/entry/2016/06/13/003650 )
                        # TODO add if condition when binrary operator is '='
                        # TODO: how about a = b = vld1_u8(a); pattren?
                        for child in parent.get_children():
                            if child.kind.name == "DECL_REF_EXPR":
                                if str(child.type.kind) == "TypeKind.TYPEDEF":
                                    var_name = child.spelling
                                    break
                # NOTE: for decl assign
                # NOTE: e.g. uint8x8_t lane_a = vld1_u8(a);
                if node.semantic_parent is None:
                    arm_neon_type_result = arm_neon_match(ret_type)
                    if arm_neon_type_result:
                        tmp_lane_id = var_name
                        if var_name == "":
                            tmp_lane_id = str(random.random())
                        # NOTE: create tmp lane and insert to graph
                        add_var_node(graph, tmp_lane_id, var_name, ret_type)
                        if top_id != "":
                            graph.edge(tmp_lane_id, top_id, label="")
                        # NOTE: insert to graph (update top_id) since next ref is this inserted node
                        top_id = tmp_lane_id
                if top_id != "":
                    graph.edge(current_id, top_id, label="")
                graph.node(current_id, shape="diamond", color="black", label=func_name)
                return current_id
            return top_id

        self.traverse(_lambda)
        self.combine_subgraphs()

    # NOTE: combine subgraphs to main graph
    def combine_subgraphs(self):
        main_graph = self.graph_list[0]
        for graph in self.graph_list[1:]:
            main_graph.subgraph(graph)

    def traverse(self, f):
        top_id = ""
        self.traverse_body(None, self.tu.cursor, f, top_id)

    def traverse_body(self, parent, node, f, top_id):
        top_id = f(parent, node, top_id)
        for child in node.get_children():
            self.traverse_body(node, child, f, top_id)


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('-o', '--output', required=True, type=str)
    parser.add_argument('--format', default="svg", type=str, help="svg,png,dot,jpg,pdf,bmp")
    parser.add_argument('--nodesep', default=1.0, type=float)
    parser.add_argument('--ranksep', default=1.0, type=float)
    parser.add_argument('--verbose', default=False, type=bool)
    parser.add_argument('filepath')
    args, extra_args = parser.parse_known_args()

    main_graph = Digraph(format=args.format)
    main_graph.attr("graph", nodesep=str(args.nodesep), ranksep=str(args.ranksep))
    ClangSIMDVizParser(args.filepath, main_graph, verbose=args.verbose).parse_simd_code()
    main_graph.render(args.output)
