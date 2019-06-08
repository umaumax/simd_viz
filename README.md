# simd_viz

cpp simd src to graphviz dot file

## support list
* arm neon
* ~~intel sse, avx~~

## TODO
* add support of pip install
* add support of non-neon variable
* 異なるスコープの同一の変数名に対して，同じ参照となる問題
* 同一スコープの同一の変数名に新規代入された場合に，同じ参照となる問題
* add test case

## how to install
```
WIP
```

## hot to run
```
# Mac OS X
LD_LIBRARY_PATH="/usr/local/opt/llvm/lib:$LD_LIBRARY_PATH" ./simd_viz.py example.cpp -o example
# Ubuntu
LD_LIBRARY_PATH="/usr/lib/llvm-5.0/lib:$LD_LIBRARY_PATH" ./simd_viz.py example.cpp -o example
```

## how to see ast
```
clang-check example.cpp -ast-dump -ast-dump-filter=neon -- -c
```

## FYI
* [umaumax/gccparser]( https://github.com/umaumax/gccparser )
