// NOTE: dummy type
using int8x8_t    = int;
using int16x4_t   = int;
using int32x2_t   = int;
using int64x1_t   = int;
using float16x4_t = int;
using float32x2_t = int;
using poly8x8_t   = int;
using poly16x4_t  = int;
using uint8x8_t   = int;
using uint16x4_t  = int;
using uint32x2_t  = int;
using float64x1_t = int;
using uint64x1_t  = int;
using int8x16_t   = int;
using int16x8_t   = int;
using int32x4_t   = int;
using int64x2_t   = int;
using float16x8_t = int;
using float32x4_t = int;
using float64x2_t = int;
using poly8x16_t  = int;
using poly16x8_t  = int;
using poly64x2_t  = int;
using poly64x1_t  = int;
using uint8x16_t  = int;
using uint16x8_t  = int;
using uint32x4_t  = int;
using uint64x2_t  = int;
using poly8_t     = int;
using poly16_t    = int;
using poly64_t    = int;
using poly128_t   = int;
using float16_t   = int;
using float32_t   = float;
using float64_t   = double;

#define __STRUCTN(t, sz, nelem)        \
  typedef struct t##sz##x##nelem##_t { \
    t##sz##_t val[nelem];              \
  } t##sz##x##nelem##_t;

/* 2-element structs.  */
__STRUCTN(int, 8, 2)
__STRUCTN(int, 16, 2)
__STRUCTN(uint, 8, 2)
__STRUCTN(uint, 16, 2)
__STRUCTN(float, 16, 2)
__STRUCTN(poly, 8, 2)
__STRUCTN(poly, 16, 2)
/* 3-element structs.  */
__STRUCTN(int, 8, 3)
__STRUCTN(int, 16, 3)
__STRUCTN(int, 32, 3)
__STRUCTN(int, 64, 3)
__STRUCTN(uint, 8, 3)
__STRUCTN(uint, 16, 3)
__STRUCTN(uint, 32, 3)
__STRUCTN(uint, 64, 3)
__STRUCTN(float, 16, 3)
__STRUCTN(float, 32, 3)
__STRUCTN(float, 64, 3)
__STRUCTN(poly, 8, 3)
__STRUCTN(poly, 16, 3)
/* 4-element structs.  */
__STRUCTN(int, 8, 4)
__STRUCTN(int, 64, 4)
__STRUCTN(uint, 8, 4)
__STRUCTN(uint, 64, 4)
__STRUCTN(poly, 8, 4)
__STRUCTN(float, 64, 4)
#undef __STRUCTN

typedef struct int8x8x2_t {
  int8x8_t val[2];
} int8x8x2_t;

typedef struct int8x16x2_t {
  int8x16_t val[2];
} int8x16x2_t;

typedef struct int16x4x2_t {
  int16x4_t val[2];
} int16x4x2_t;

typedef struct int16x8x2_t {
  int16x8_t val[2];
} int16x8x2_t;

typedef struct int32x2x2_t {
  int32x2_t val[2];
} int32x2x2_t;

typedef struct int32x4x2_t {
  int32x4_t val[2];
} int32x4x2_t;

typedef struct int64x1x2_t {
  int64x1_t val[2];
} int64x1x2_t;

typedef struct int64x2x2_t {
  int64x2_t val[2];
} int64x2x2_t;

typedef struct uint8x8x2_t {
  uint8x8_t val[2];
} uint8x8x2_t;

typedef struct uint8x16x2_t {
  uint8x16_t val[2];
} uint8x16x2_t;

typedef struct uint16x4x2_t {
  uint16x4_t val[2];
} uint16x4x2_t;

typedef struct uint16x8x2_t {
  uint16x8_t val[2];
} uint16x8x2_t;

typedef struct uint32x2x2_t {
  uint32x2_t val[2];
} uint32x2x2_t;

typedef struct uint32x4x2_t {
  uint32x4_t val[2];
} uint32x4x2_t;

typedef struct uint64x1x2_t {
  uint64x1_t val[2];
} uint64x1x2_t;

typedef struct uint64x2x2_t {
  uint64x2_t val[2];
} uint64x2x2_t;

typedef struct float16x4x2_t {
  float16x4_t val[2];
} float16x4x2_t;

typedef struct float16x8x2_t {
  float16x8_t val[2];
} float16x8x2_t;

typedef struct float32x2x2_t {
  float32x2_t val[2];
} float32x2x2_t;

typedef struct float32x4x2_t {
  float32x4_t val[2];
} float32x4x2_t;

typedef struct float64x2x2_t {
  float64x2_t val[2];
} float64x2x2_t;

typedef struct float64x1x2_t {
  float64x1_t val[2];
} float64x1x2_t;

typedef struct poly8x8x2_t {
  poly8x8_t val[2];
} poly8x8x2_t;

typedef struct poly8x16x2_t {
  poly8x16_t val[2];
} poly8x16x2_t;

typedef struct poly16x4x2_t {
  poly16x4_t val[2];
} poly16x4x2_t;

typedef struct poly16x8x2_t {
  poly16x8_t val[2];
} poly16x8x2_t;

typedef struct poly64x1x2_t {
  poly64x1_t val[2];
} poly64x1x2_t;

typedef struct poly64x1x3_t {
  poly64x1_t val[3];
} poly64x1x3_t;

typedef struct poly64x1x4_t {
  poly64x1_t val[4];
} poly64x1x4_t;

typedef struct poly64x2x2_t {
  poly64x2_t val[2];
} poly64x2x2_t;

typedef struct poly64x2x3_t {
  poly64x2_t val[3];
} poly64x2x3_t;

typedef struct poly64x2x4_t {
  poly64x2_t val[4];
} poly64x2x4_t;

typedef struct int8x8x3_t {
  int8x8_t val[3];
} int8x8x3_t;

typedef struct int8x16x3_t {
  int8x16_t val[3];
} int8x16x3_t;

typedef struct int16x4x3_t {
  int16x4_t val[3];
} int16x4x3_t;

typedef struct int16x8x3_t {
  int16x8_t val[3];
} int16x8x3_t;

typedef struct int32x2x3_t {
  int32x2_t val[3];
} int32x2x3_t;

typedef struct int32x4x3_t {
  int32x4_t val[3];
} int32x4x3_t;

typedef struct int64x1x3_t {
  int64x1_t val[3];
} int64x1x3_t;

typedef struct int64x2x3_t {
  int64x2_t val[3];
} int64x2x3_t;

typedef struct uint8x8x3_t {
  uint8x8_t val[3];
} uint8x8x3_t;

typedef struct uint8x16x3_t {
  uint8x16_t val[3];
} uint8x16x3_t;

typedef struct uint16x4x3_t {
  uint16x4_t val[3];
} uint16x4x3_t;

typedef struct uint16x8x3_t {
  uint16x8_t val[3];
} uint16x8x3_t;

typedef struct uint32x2x3_t {
  uint32x2_t val[3];
} uint32x2x3_t;

typedef struct uint32x4x3_t {
  uint32x4_t val[3];
} uint32x4x3_t;

typedef struct uint64x1x3_t {
  uint64x1_t val[3];
} uint64x1x3_t;

typedef struct uint64x2x3_t {
  uint64x2_t val[3];
} uint64x2x3_t;

typedef struct float16x4x3_t {
  float16x4_t val[3];
} float16x4x3_t;

typedef struct float16x8x3_t {
  float16x8_t val[3];
} float16x8x3_t;

typedef struct float32x2x3_t {
  float32x2_t val[3];
} float32x2x3_t;

typedef struct float32x4x3_t {
  float32x4_t val[3];
} float32x4x3_t;

typedef struct float64x2x3_t {
  float64x2_t val[3];
} float64x2x3_t;

typedef struct float64x1x3_t {
  float64x1_t val[3];
} float64x1x3_t;

typedef struct poly8x8x3_t {
  poly8x8_t val[3];
} poly8x8x3_t;

typedef struct poly8x16x3_t {
  poly8x16_t val[3];
} poly8x16x3_t;

typedef struct poly16x4x3_t {
  poly16x4_t val[3];
} poly16x4x3_t;

typedef struct poly16x8x3_t {
  poly16x8_t val[3];
} poly16x8x3_t;

typedef struct int8x8x4_t {
  int8x8_t val[4];
} int8x8x4_t;

typedef struct int8x16x4_t {
  int8x16_t val[4];
} int8x16x4_t;

typedef struct int16x4x4_t {
  int16x4_t val[4];
} int16x4x4_t;

typedef struct int16x8x4_t {
  int16x8_t val[4];
} int16x8x4_t;

typedef struct int32x2x4_t {
  int32x2_t val[4];
} int32x2x4_t;

typedef struct int32x4x4_t {
  int32x4_t val[4];
} int32x4x4_t;

typedef struct int64x1x4_t {
  int64x1_t val[4];
} int64x1x4_t;

typedef struct int64x2x4_t {
  int64x2_t val[4];
} int64x2x4_t;

typedef struct uint8x8x4_t {
  uint8x8_t val[4];
} uint8x8x4_t;

typedef struct uint8x16x4_t {
  uint8x16_t val[4];
} uint8x16x4_t;

typedef struct uint16x4x4_t {
  uint16x4_t val[4];
} uint16x4x4_t;

typedef struct uint16x8x4_t {
  uint16x8_t val[4];
} uint16x8x4_t;

typedef struct uint32x2x4_t {
  uint32x2_t val[4];
} uint32x2x4_t;

typedef struct uint32x4x4_t {
  uint32x4_t val[4];
} uint32x4x4_t;

typedef struct uint64x1x4_t {
  uint64x1_t val[4];
} uint64x1x4_t;

typedef struct uint64x2x4_t {
  uint64x2_t val[4];
} uint64x2x4_t;

typedef struct float16x4x4_t {
  float16x4_t val[4];
} float16x4x4_t;

typedef struct float16x8x4_t {
  float16x8_t val[4];
} float16x8x4_t;

typedef struct float32x2x4_t {
  float32x2_t val[4];
} float32x2x4_t;

typedef struct float32x4x4_t {
  float32x4_t val[4];
} float32x4x4_t;

typedef struct float64x2x4_t {
  float64x2_t val[4];
} float64x2x4_t;

typedef struct float64x1x4_t {
  float64x1_t val[4];
} float64x1x4_t;

typedef struct poly8x8x4_t {
  poly8x8_t val[4];
} poly8x8x4_t;

typedef struct poly8x16x4_t {
  poly8x16_t val[4];
} poly8x16x4_t;

typedef struct poly16x4x4_t {
  poly16x4_t val[4];
} poly16x4x4_t;

typedef struct poly16x8x4_t {
  poly16x8_t val[4];
} poly16x8x4_t;
