/* Autogenerated: 'src/ExtractionOCaml/unsaturated_solinas' --static --use-value-barrier poly1305 32 '(auto)' '2^130 - 5' carry_mul carry_square carry add sub opp selectznz to_bytes from_bytes */
/* curve description: poly1305 */
/* machine_wordsize = 32 (from "32") */
/* requested operations: carry_mul, carry_square, carry, add, sub, opp, selectznz, to_bytes, from_bytes */
/* n = 5 (from "(auto)") */
/* s-c = 2^130 - [(1, 5)] (from "2^130 - 5") */
/* tight_bounds_multiplier = 1 (from "") */
/*  */
/* Computed values: */
/* carry_chain = [0, 1, 2, 3, 4, 0, 1] */
/* eval z = z[0] + (z[1] << 26) + (z[2] << 52) + (z[3] << 78) + (z[4] << 104) */
/* bytes_eval z = z[0] + (z[1] << 8) + (z[2] << 16) + (z[3] << 24) + (z[4] << 32) + (z[5] << 40) + (z[6] << 48) + (z[7] << 56) + (z[8] << 64) + (z[9] << 72) + (z[10] << 80) + (z[11] << 88) + (z[12] << 96) + (z[13] << 104) + (z[14] << 112) + (z[15] << 120) + (z[16] << 128) */
/* balance = [0x7fffff6, 0x7fffffe, 0x7fffffe, 0x7fffffe, 0x7fffffe] */

#include <stdint.h>
typedef unsigned char fiat_poly1305_uint1;
typedef signed char fiat_poly1305_int1;

#if (-1 & 3) != 3
#error "This code only works on a two's complement system"
#endif

#if !defined(FIAT_POLY1305_NO_ASM) && (defined(__GNUC__) || defined(__clang__))
static __inline__ uint32_t fiat_poly1305_value_barrier_u32(uint32_t a) {
  __asm__("" : "+r"(a) : /* no inputs */);
  return a;
}
#else
#  define fiat_poly1305_value_barrier_u32(x) (x)
#endif


/*
 * The function fiat_poly1305_addcarryx_u26 is an addition with carry.
 * Postconditions:
 *   out1 = (arg1 + arg2 + arg3) mod 2^26
 *   out2 = ⌊(arg1 + arg2 + arg3) / 2^26⌋
 *
 * Input Bounds:
 *   arg1: [0x0 ~> 0x1]
 *   arg2: [0x0 ~> 0x3ffffff]
 *   arg3: [0x0 ~> 0x3ffffff]
 * Output Bounds:
 *   out1: [0x0 ~> 0x3ffffff]
 *   out2: [0x0 ~> 0x1]
 */
static void fiat_poly1305_addcarryx_u26(uint32_t* out1, fiat_poly1305_uint1* out2, fiat_poly1305_uint1 arg1, uint32_t arg2, uint32_t arg3) {
  uint32_t x1;
  uint32_t x2;
  fiat_poly1305_uint1 x3;
  x1 = ((arg1 + arg2) + arg3);
  x2 = (x1 & UINT32_C(0x3ffffff));
  x3 = (fiat_poly1305_uint1)(x1 >> 26);
  *out1 = x2;
  *out2 = x3;
}

/*
 * The function fiat_poly1305_subborrowx_u26 is a subtraction with borrow.
 * Postconditions:
 *   out1 = (-arg1 + arg2 + -arg3) mod 2^26
 *   out2 = -⌊(-arg1 + arg2 + -arg3) / 2^26⌋
 *
 * Input Bounds:
 *   arg1: [0x0 ~> 0x1]
 *   arg2: [0x0 ~> 0x3ffffff]
 *   arg3: [0x0 ~> 0x3ffffff]
 * Output Bounds:
 *   out1: [0x0 ~> 0x3ffffff]
 *   out2: [0x0 ~> 0x1]
 */
static void fiat_poly1305_subborrowx_u26(uint32_t* out1, fiat_poly1305_uint1* out2, fiat_poly1305_uint1 arg1, uint32_t arg2, uint32_t arg3) {
  int32_t x1;
  fiat_poly1305_int1 x2;
  uint32_t x3;
  x1 = ((int32_t)(arg2 - arg1) - (int32_t)arg3);
  x2 = (fiat_poly1305_int1)(x1 >> 26);
  x3 = (x1 & UINT32_C(0x3ffffff));
  *out1 = x3;
  *out2 = (fiat_poly1305_uint1)(0x0 - x2);
}

/*
 * The function fiat_poly1305_cmovznz_u32 is a single-word conditional move.
 * Postconditions:
 *   out1 = (if arg1 = 0 then arg2 else arg3)
 *
 * Input Bounds:
 *   arg1: [0x0 ~> 0x1]
 *   arg2: [0x0 ~> 0xffffffff]
 *   arg3: [0x0 ~> 0xffffffff]
 * Output Bounds:
 *   out1: [0x0 ~> 0xffffffff]
 */
static void fiat_poly1305_cmovznz_u32(uint32_t* out1, fiat_poly1305_uint1 arg1, uint32_t arg2, uint32_t arg3) {
  fiat_poly1305_uint1 x1;
  uint32_t x2;
  uint32_t x3;
  x1 = (!(!arg1));
  x2 = ((fiat_poly1305_int1)(0x0 - x1) & UINT32_C(0xffffffff));
  x3 = ((fiat_poly1305_value_barrier_u32(x2) & arg3) | (fiat_poly1305_value_barrier_u32((~x2)) & arg2));
  *out1 = x3;
}

/*
 * The function fiat_poly1305_carry_mul multiplies two field elements and reduces the result.
 * Postconditions:
 *   eval out1 mod m = (eval arg1 * eval arg2) mod m
 *
 * Input Bounds:
 *   arg1: [[0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000]]
 *   arg2: [[0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000]]
 * Output Bounds:
 *   out1: [[0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000]]
 */
static void fiat_poly1305_carry_mul(uint32_t out1[5], const uint32_t arg1[5], const uint32_t arg2[5]) {
  uint64_t x1;
  uint64_t x2;
  uint64_t x3;
  uint64_t x4;
  uint64_t x5;
  uint64_t x6;
  uint64_t x7;
  uint64_t x8;
  uint64_t x9;
  uint64_t x10;
  uint64_t x11;
  uint64_t x12;
  uint64_t x13;
  uint64_t x14;
  uint64_t x15;
  uint64_t x16;
  uint64_t x17;
  uint64_t x18;
  uint64_t x19;
  uint64_t x20;
  uint64_t x21;
  uint64_t x22;
  uint64_t x23;
  uint64_t x24;
  uint64_t x25;
  uint64_t x26;
  uint64_t x27;
  uint32_t x28;
  uint64_t x29;
  uint64_t x30;
  uint64_t x31;
  uint64_t x32;
  uint64_t x33;
  uint64_t x34;
  uint32_t x35;
  uint64_t x36;
  uint64_t x37;
  uint32_t x38;
  uint64_t x39;
  uint64_t x40;
  uint32_t x41;
  uint64_t x42;
  uint32_t x43;
  uint32_t x44;
  uint64_t x45;
  uint64_t x46;
  uint32_t x47;
  uint32_t x48;
  uint32_t x49;
  fiat_poly1305_uint1 x50;
  uint32_t x51;
  uint32_t x52;
  x1 = ((uint64_t)(arg1[4]) * ((arg2[4]) * 0x5));
  x2 = ((uint64_t)(arg1[4]) * ((arg2[3]) * 0x5));
  x3 = ((uint64_t)(arg1[4]) * ((arg2[2]) * 0x5));
  x4 = ((uint64_t)(arg1[4]) * ((arg2[1]) * 0x5));
  x5 = ((uint64_t)(arg1[3]) * ((arg2[4]) * 0x5));
  x6 = ((uint64_t)(arg1[3]) * ((arg2[3]) * 0x5));
  x7 = ((uint64_t)(arg1[3]) * ((arg2[2]) * 0x5));
  x8 = ((uint64_t)(arg1[2]) * ((arg2[4]) * 0x5));
  x9 = ((uint64_t)(arg1[2]) * ((arg2[3]) * 0x5));
  x10 = ((uint64_t)(arg1[1]) * ((arg2[4]) * 0x5));
  x11 = ((uint64_t)(arg1[4]) * (arg2[0]));
  x12 = ((uint64_t)(arg1[3]) * (arg2[1]));
  x13 = ((uint64_t)(arg1[3]) * (arg2[0]));
  x14 = ((uint64_t)(arg1[2]) * (arg2[2]));
  x15 = ((uint64_t)(arg1[2]) * (arg2[1]));
  x16 = ((uint64_t)(arg1[2]) * (arg2[0]));
  x17 = ((uint64_t)(arg1[1]) * (arg2[3]));
  x18 = ((uint64_t)(arg1[1]) * (arg2[2]));
  x19 = ((uint64_t)(arg1[1]) * (arg2[1]));
  x20 = ((uint64_t)(arg1[1]) * (arg2[0]));
  x21 = ((uint64_t)(arg1[0]) * (arg2[4]));
  x22 = ((uint64_t)(arg1[0]) * (arg2[3]));
  x23 = ((uint64_t)(arg1[0]) * (arg2[2]));
  x24 = ((uint64_t)(arg1[0]) * (arg2[1]));
  x25 = ((uint64_t)(arg1[0]) * (arg2[0]));
  x26 = (x25 + (x10 + (x9 + (x7 + x4))));
  x27 = (x26 >> 26);
  x28 = (uint32_t)(x26 & UINT32_C(0x3ffffff));
  x29 = (x21 + (x17 + (x14 + (x12 + x11))));
  x30 = (x22 + (x18 + (x15 + (x13 + x1))));
  x31 = (x23 + (x19 + (x16 + (x5 + x2))));
  x32 = (x24 + (x20 + (x8 + (x6 + x3))));
  x33 = (x27 + x32);
  x34 = (x33 >> 26);
  x35 = (uint32_t)(x33 & UINT32_C(0x3ffffff));
  x36 = (x34 + x31);
  x37 = (x36 >> 26);
  x38 = (uint32_t)(x36 & UINT32_C(0x3ffffff));
  x39 = (x37 + x30);
  x40 = (x39 >> 26);
  x41 = (uint32_t)(x39 & UINT32_C(0x3ffffff));
  x42 = (x40 + x29);
  x43 = (uint32_t)(x42 >> 26);
  x44 = (uint32_t)(x42 & UINT32_C(0x3ffffff));
  x45 = ((uint64_t)x43 * 0x5);
  x46 = (x28 + x45);
  x47 = (uint32_t)(x46 >> 26);
  x48 = (uint32_t)(x46 & UINT32_C(0x3ffffff));
  x49 = (x47 + x35);
  x50 = (fiat_poly1305_uint1)(x49 >> 26);
  x51 = (x49 & UINT32_C(0x3ffffff));
  x52 = (x50 + x38);
  out1[0] = x48;
  out1[1] = x51;
  out1[2] = x52;
  out1[3] = x41;
  out1[4] = x44;
}

/*
 * The function fiat_poly1305_carry_square squares a field element and reduces the result.
 * Postconditions:
 *   eval out1 mod m = (eval arg1 * eval arg1) mod m
 *
 * Input Bounds:
 *   arg1: [[0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000]]
 * Output Bounds:
 *   out1: [[0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000]]
 */
static void fiat_poly1305_carry_square(uint32_t out1[5], const uint32_t arg1[5]) {
  uint32_t x1;
  uint32_t x2;
  uint32_t x3;
  uint32_t x4;
  uint32_t x5;
  uint32_t x6;
  uint32_t x7;
  uint32_t x8;
  uint64_t x9;
  uint64_t x10;
  uint64_t x11;
  uint64_t x12;
  uint64_t x13;
  uint64_t x14;
  uint64_t x15;
  uint64_t x16;
  uint64_t x17;
  uint64_t x18;
  uint64_t x19;
  uint64_t x20;
  uint64_t x21;
  uint64_t x22;
  uint64_t x23;
  uint64_t x24;
  uint64_t x25;
  uint32_t x26;
  uint64_t x27;
  uint64_t x28;
  uint64_t x29;
  uint64_t x30;
  uint64_t x31;
  uint64_t x32;
  uint32_t x33;
  uint64_t x34;
  uint64_t x35;
  uint32_t x36;
  uint64_t x37;
  uint64_t x38;
  uint32_t x39;
  uint64_t x40;
  uint32_t x41;
  uint32_t x42;
  uint64_t x43;
  uint64_t x44;
  uint32_t x45;
  uint32_t x46;
  uint32_t x47;
  fiat_poly1305_uint1 x48;
  uint32_t x49;
  uint32_t x50;
  x1 = ((arg1[4]) * 0x5);
  x2 = (x1 * 0x2);
  x3 = ((arg1[4]) * 0x2);
  x4 = ((arg1[3]) * 0x5);
  x5 = (x4 * 0x2);
  x6 = ((arg1[3]) * 0x2);
  x7 = ((arg1[2]) * 0x2);
  x8 = ((arg1[1]) * 0x2);
  x9 = ((uint64_t)(arg1[4]) * x1);
  x10 = ((uint64_t)(arg1[3]) * x2);
  x11 = ((uint64_t)(arg1[3]) * x4);
  x12 = ((uint64_t)(arg1[2]) * x2);
  x13 = ((uint64_t)(arg1[2]) * x5);
  x14 = ((uint64_t)(arg1[2]) * (arg1[2]));
  x15 = ((uint64_t)(arg1[1]) * x2);
  x16 = ((uint64_t)(arg1[1]) * x6);
  x17 = ((uint64_t)(arg1[1]) * x7);
  x18 = ((uint64_t)(arg1[1]) * (arg1[1]));
  x19 = ((uint64_t)(arg1[0]) * x3);
  x20 = ((uint64_t)(arg1[0]) * x6);
  x21 = ((uint64_t)(arg1[0]) * x7);
  x22 = ((uint64_t)(arg1[0]) * x8);
  x23 = ((uint64_t)(arg1[0]) * (arg1[0]));
  x24 = (x23 + (x15 + x13));
  x25 = (x24 >> 26);
  x26 = (uint32_t)(x24 & UINT32_C(0x3ffffff));
  x27 = (x19 + (x16 + x14));
  x28 = (x20 + (x17 + x9));
  x29 = (x21 + (x18 + x10));
  x30 = (x22 + (x12 + x11));
  x31 = (x25 + x30);
  x32 = (x31 >> 26);
  x33 = (uint32_t)(x31 & UINT32_C(0x3ffffff));
  x34 = (x32 + x29);
  x35 = (x34 >> 26);
  x36 = (uint32_t)(x34 & UINT32_C(0x3ffffff));
  x37 = (x35 + x28);
  x38 = (x37 >> 26);
  x39 = (uint32_t)(x37 & UINT32_C(0x3ffffff));
  x40 = (x38 + x27);
  x41 = (uint32_t)(x40 >> 26);
  x42 = (uint32_t)(x40 & UINT32_C(0x3ffffff));
  x43 = ((uint64_t)x41 * 0x5);
  x44 = (x26 + x43);
  x45 = (uint32_t)(x44 >> 26);
  x46 = (uint32_t)(x44 & UINT32_C(0x3ffffff));
  x47 = (x45 + x33);
  x48 = (fiat_poly1305_uint1)(x47 >> 26);
  x49 = (x47 & UINT32_C(0x3ffffff));
  x50 = (x48 + x36);
  out1[0] = x46;
  out1[1] = x49;
  out1[2] = x50;
  out1[3] = x39;
  out1[4] = x42;
}

/*
 * The function fiat_poly1305_carry reduces a field element.
 * Postconditions:
 *   eval out1 mod m = eval arg1 mod m
 *
 * Input Bounds:
 *   arg1: [[0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000]]
 * Output Bounds:
 *   out1: [[0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000]]
 */
static void fiat_poly1305_carry(uint32_t out1[5], const uint32_t arg1[5]) {
  uint32_t x1;
  uint32_t x2;
  uint32_t x3;
  uint32_t x4;
  uint32_t x5;
  uint32_t x6;
  uint32_t x7;
  uint32_t x8;
  uint32_t x9;
  uint32_t x10;
  uint32_t x11;
  uint32_t x12;
  x1 = (arg1[0]);
  x2 = ((x1 >> 26) + (arg1[1]));
  x3 = ((x2 >> 26) + (arg1[2]));
  x4 = ((x3 >> 26) + (arg1[3]));
  x5 = ((x4 >> 26) + (arg1[4]));
  x6 = ((x1 & UINT32_C(0x3ffffff)) + ((x5 >> 26) * 0x5));
  x7 = ((fiat_poly1305_uint1)(x6 >> 26) + (x2 & UINT32_C(0x3ffffff)));
  x8 = (x6 & UINT32_C(0x3ffffff));
  x9 = (x7 & UINT32_C(0x3ffffff));
  x10 = ((fiat_poly1305_uint1)(x7 >> 26) + (x3 & UINT32_C(0x3ffffff)));
  x11 = (x4 & UINT32_C(0x3ffffff));
  x12 = (x5 & UINT32_C(0x3ffffff));
  out1[0] = x8;
  out1[1] = x9;
  out1[2] = x10;
  out1[3] = x11;
  out1[4] = x12;
}

/*
 * The function fiat_poly1305_add adds two field elements.
 * Postconditions:
 *   eval out1 mod m = (eval arg1 + eval arg2) mod m
 *
 * Input Bounds:
 *   arg1: [[0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000]]
 *   arg2: [[0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000]]
 * Output Bounds:
 *   out1: [[0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000]]
 */
static void fiat_poly1305_add(uint32_t out1[5], const uint32_t arg1[5], const uint32_t arg2[5]) {
  uint32_t x1;
  uint32_t x2;
  uint32_t x3;
  uint32_t x4;
  uint32_t x5;
  x1 = ((arg1[0]) + (arg2[0]));
  x2 = ((arg1[1]) + (arg2[1]));
  x3 = ((arg1[2]) + (arg2[2]));
  x4 = ((arg1[3]) + (arg2[3]));
  x5 = ((arg1[4]) + (arg2[4]));
  out1[0] = x1;
  out1[1] = x2;
  out1[2] = x3;
  out1[3] = x4;
  out1[4] = x5;
}

/*
 * The function fiat_poly1305_sub subtracts two field elements.
 * Postconditions:
 *   eval out1 mod m = (eval arg1 - eval arg2) mod m
 *
 * Input Bounds:
 *   arg1: [[0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000]]
 *   arg2: [[0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000]]
 * Output Bounds:
 *   out1: [[0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000]]
 */
static void fiat_poly1305_sub(uint32_t out1[5], const uint32_t arg1[5], const uint32_t arg2[5]) {
  uint32_t x1;
  uint32_t x2;
  uint32_t x3;
  uint32_t x4;
  uint32_t x5;
  x1 = ((UINT32_C(0x7fffff6) + (arg1[0])) - (arg2[0]));
  x2 = ((UINT32_C(0x7fffffe) + (arg1[1])) - (arg2[1]));
  x3 = ((UINT32_C(0x7fffffe) + (arg1[2])) - (arg2[2]));
  x4 = ((UINT32_C(0x7fffffe) + (arg1[3])) - (arg2[3]));
  x5 = ((UINT32_C(0x7fffffe) + (arg1[4])) - (arg2[4]));
  out1[0] = x1;
  out1[1] = x2;
  out1[2] = x3;
  out1[3] = x4;
  out1[4] = x5;
}

/*
 * The function fiat_poly1305_opp negates a field element.
 * Postconditions:
 *   eval out1 mod m = -eval arg1 mod m
 *
 * Input Bounds:
 *   arg1: [[0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000]]
 * Output Bounds:
 *   out1: [[0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000]]
 */
static void fiat_poly1305_opp(uint32_t out1[5], const uint32_t arg1[5]) {
  uint32_t x1;
  uint32_t x2;
  uint32_t x3;
  uint32_t x4;
  uint32_t x5;
  x1 = (UINT32_C(0x7fffff6) - (arg1[0]));
  x2 = (UINT32_C(0x7fffffe) - (arg1[1]));
  x3 = (UINT32_C(0x7fffffe) - (arg1[2]));
  x4 = (UINT32_C(0x7fffffe) - (arg1[3]));
  x5 = (UINT32_C(0x7fffffe) - (arg1[4]));
  out1[0] = x1;
  out1[1] = x2;
  out1[2] = x3;
  out1[3] = x4;
  out1[4] = x5;
}

/*
 * The function fiat_poly1305_selectznz is a multi-limb conditional select.
 * Postconditions:
 *   eval out1 = (if arg1 = 0 then eval arg2 else eval arg3)
 *
 * Input Bounds:
 *   arg1: [0x0 ~> 0x1]
 *   arg2: [[0x0 ~> 0xffffffff], [0x0 ~> 0xffffffff], [0x0 ~> 0xffffffff], [0x0 ~> 0xffffffff], [0x0 ~> 0xffffffff]]
 *   arg3: [[0x0 ~> 0xffffffff], [0x0 ~> 0xffffffff], [0x0 ~> 0xffffffff], [0x0 ~> 0xffffffff], [0x0 ~> 0xffffffff]]
 * Output Bounds:
 *   out1: [[0x0 ~> 0xffffffff], [0x0 ~> 0xffffffff], [0x0 ~> 0xffffffff], [0x0 ~> 0xffffffff], [0x0 ~> 0xffffffff]]
 */
static void fiat_poly1305_selectznz(uint32_t out1[5], fiat_poly1305_uint1 arg1, const uint32_t arg2[5], const uint32_t arg3[5]) {
  uint32_t x1;
  uint32_t x2;
  uint32_t x3;
  uint32_t x4;
  uint32_t x5;
  fiat_poly1305_cmovznz_u32(&x1, arg1, (arg2[0]), (arg3[0]));
  fiat_poly1305_cmovznz_u32(&x2, arg1, (arg2[1]), (arg3[1]));
  fiat_poly1305_cmovznz_u32(&x3, arg1, (arg2[2]), (arg3[2]));
  fiat_poly1305_cmovznz_u32(&x4, arg1, (arg2[3]), (arg3[3]));
  fiat_poly1305_cmovznz_u32(&x5, arg1, (arg2[4]), (arg3[4]));
  out1[0] = x1;
  out1[1] = x2;
  out1[2] = x3;
  out1[3] = x4;
  out1[4] = x5;
}

/*
 * The function fiat_poly1305_to_bytes serializes a field element to bytes in little-endian order.
 * Postconditions:
 *   out1 = map (λ x, ⌊((eval arg1 mod m) mod 2^(8 * (x + 1))) / 2^(8 * x)⌋) [0..16]
 *
 * Input Bounds:
 *   arg1: [[0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000]]
 * Output Bounds:
 *   out1: [[0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0x3]]
 */
static void fiat_poly1305_to_bytes(uint8_t out1[17], const uint32_t arg1[5]) {
  uint32_t x1;
  fiat_poly1305_uint1 x2;
  uint32_t x3;
  fiat_poly1305_uint1 x4;
  uint32_t x5;
  fiat_poly1305_uint1 x6;
  uint32_t x7;
  fiat_poly1305_uint1 x8;
  uint32_t x9;
  fiat_poly1305_uint1 x10;
  uint32_t x11;
  uint32_t x12;
  fiat_poly1305_uint1 x13;
  uint32_t x14;
  fiat_poly1305_uint1 x15;
  uint32_t x16;
  fiat_poly1305_uint1 x17;
  uint32_t x18;
  fiat_poly1305_uint1 x19;
  uint32_t x20;
  fiat_poly1305_uint1 x21;
  uint32_t x22;
  uint32_t x23;
  uint32_t x24;
  uint8_t x25;
  uint32_t x26;
  uint8_t x27;
  uint32_t x28;
  uint8_t x29;
  uint8_t x30;
  uint32_t x31;
  uint8_t x32;
  uint32_t x33;
  uint8_t x34;
  uint32_t x35;
  uint8_t x36;
  uint8_t x37;
  uint32_t x38;
  uint8_t x39;
  uint32_t x40;
  uint8_t x41;
  uint32_t x42;
  uint8_t x43;
  uint8_t x44;
  uint32_t x45;
  uint8_t x46;
  uint32_t x47;
  uint8_t x48;
  uint32_t x49;
  uint8_t x50;
  uint8_t x51;
  uint8_t x52;
  uint32_t x53;
  uint8_t x54;
  uint32_t x55;
  uint8_t x56;
  uint8_t x57;
  fiat_poly1305_subborrowx_u26(&x1, &x2, 0x0, (arg1[0]), UINT32_C(0x3fffffb));
  fiat_poly1305_subborrowx_u26(&x3, &x4, x2, (arg1[1]), UINT32_C(0x3ffffff));
  fiat_poly1305_subborrowx_u26(&x5, &x6, x4, (arg1[2]), UINT32_C(0x3ffffff));
  fiat_poly1305_subborrowx_u26(&x7, &x8, x6, (arg1[3]), UINT32_C(0x3ffffff));
  fiat_poly1305_subborrowx_u26(&x9, &x10, x8, (arg1[4]), UINT32_C(0x3ffffff));
  fiat_poly1305_cmovznz_u32(&x11, x10, 0x0, UINT32_C(0xffffffff));
  fiat_poly1305_addcarryx_u26(&x12, &x13, 0x0, x1, (x11 & UINT32_C(0x3fffffb)));
  fiat_poly1305_addcarryx_u26(&x14, &x15, x13, x3, (x11 & UINT32_C(0x3ffffff)));
  fiat_poly1305_addcarryx_u26(&x16, &x17, x15, x5, (x11 & UINT32_C(0x3ffffff)));
  fiat_poly1305_addcarryx_u26(&x18, &x19, x17, x7, (x11 & UINT32_C(0x3ffffff)));
  fiat_poly1305_addcarryx_u26(&x20, &x21, x19, x9, (x11 & UINT32_C(0x3ffffff)));
  x22 = (x18 << 6);
  x23 = (x16 << 4);
  x24 = (x14 << 2);
  x25 = (uint8_t)(x12 & UINT8_C(0xff));
  x26 = (x12 >> 8);
  x27 = (uint8_t)(x26 & UINT8_C(0xff));
  x28 = (x26 >> 8);
  x29 = (uint8_t)(x28 & UINT8_C(0xff));
  x30 = (uint8_t)(x28 >> 8);
  x31 = (x24 + (uint32_t)x30);
  x32 = (uint8_t)(x31 & UINT8_C(0xff));
  x33 = (x31 >> 8);
  x34 = (uint8_t)(x33 & UINT8_C(0xff));
  x35 = (x33 >> 8);
  x36 = (uint8_t)(x35 & UINT8_C(0xff));
  x37 = (uint8_t)(x35 >> 8);
  x38 = (x23 + (uint32_t)x37);
  x39 = (uint8_t)(x38 & UINT8_C(0xff));
  x40 = (x38 >> 8);
  x41 = (uint8_t)(x40 & UINT8_C(0xff));
  x42 = (x40 >> 8);
  x43 = (uint8_t)(x42 & UINT8_C(0xff));
  x44 = (uint8_t)(x42 >> 8);
  x45 = (x22 + (uint32_t)x44);
  x46 = (uint8_t)(x45 & UINT8_C(0xff));
  x47 = (x45 >> 8);
  x48 = (uint8_t)(x47 & UINT8_C(0xff));
  x49 = (x47 >> 8);
  x50 = (uint8_t)(x49 & UINT8_C(0xff));
  x51 = (uint8_t)(x49 >> 8);
  x52 = (uint8_t)(x20 & UINT8_C(0xff));
  x53 = (x20 >> 8);
  x54 = (uint8_t)(x53 & UINT8_C(0xff));
  x55 = (x53 >> 8);
  x56 = (uint8_t)(x55 & UINT8_C(0xff));
  x57 = (uint8_t)(x55 >> 8);
  out1[0] = x25;
  out1[1] = x27;
  out1[2] = x29;
  out1[3] = x32;
  out1[4] = x34;
  out1[5] = x36;
  out1[6] = x39;
  out1[7] = x41;
  out1[8] = x43;
  out1[9] = x46;
  out1[10] = x48;
  out1[11] = x50;
  out1[12] = x51;
  out1[13] = x52;
  out1[14] = x54;
  out1[15] = x56;
  out1[16] = x57;
}

/*
 * The function fiat_poly1305_from_bytes deserializes a field element from bytes in little-endian order.
 * Postconditions:
 *   eval out1 mod m = bytes_eval arg1 mod m
 *
 * Input Bounds:
 *   arg1: [[0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0x3]]
 * Output Bounds:
 *   out1: [[0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000]]
 */
static void fiat_poly1305_from_bytes(uint32_t out1[5], const uint8_t arg1[17]) {
  uint32_t x1;
  uint32_t x2;
  uint32_t x3;
  uint8_t x4;
  uint32_t x5;
  uint32_t x6;
  uint32_t x7;
  uint32_t x8;
  uint32_t x9;
  uint32_t x10;
  uint32_t x11;
  uint32_t x12;
  uint32_t x13;
  uint32_t x14;
  uint32_t x15;
  uint32_t x16;
  uint8_t x17;
  uint32_t x18;
  uint32_t x19;
  uint32_t x20;
  uint32_t x21;
  uint8_t x22;
  uint32_t x23;
  uint32_t x24;
  uint32_t x25;
  uint32_t x26;
  uint8_t x27;
  uint32_t x28;
  uint32_t x29;
  uint32_t x30;
  uint32_t x31;
  uint8_t x32;
  uint32_t x33;
  uint32_t x34;
  uint32_t x35;
  uint32_t x36;
  uint32_t x37;
  uint32_t x38;
  x1 = ((uint32_t)(arg1[16]) << 24);
  x2 = ((uint32_t)(arg1[15]) << 16);
  x3 = ((uint32_t)(arg1[14]) << 8);
  x4 = (arg1[13]);
  x5 = ((uint32_t)(arg1[12]) << 18);
  x6 = ((uint32_t)(arg1[11]) << 10);
  x7 = ((uint32_t)(arg1[10]) << 2);
  x8 = ((uint32_t)(arg1[9]) << 20);
  x9 = ((uint32_t)(arg1[8]) << 12);
  x10 = ((uint32_t)(arg1[7]) << 4);
  x11 = ((uint32_t)(arg1[6]) << 22);
  x12 = ((uint32_t)(arg1[5]) << 14);
  x13 = ((uint32_t)(arg1[4]) << 6);
  x14 = ((uint32_t)(arg1[3]) << 24);
  x15 = ((uint32_t)(arg1[2]) << 16);
  x16 = ((uint32_t)(arg1[1]) << 8);
  x17 = (arg1[0]);
  x18 = (x16 + (uint32_t)x17);
  x19 = (x15 + x18);
  x20 = (x14 + x19);
  x21 = (x20 & UINT32_C(0x3ffffff));
  x22 = (uint8_t)(x20 >> 26);
  x23 = (x13 + (uint32_t)x22);
  x24 = (x12 + x23);
  x25 = (x11 + x24);
  x26 = (x25 & UINT32_C(0x3ffffff));
  x27 = (uint8_t)(x25 >> 26);
  x28 = (x10 + (uint32_t)x27);
  x29 = (x9 + x28);
  x30 = (x8 + x29);
  x31 = (x30 & UINT32_C(0x3ffffff));
  x32 = (uint8_t)(x30 >> 26);
  x33 = (x7 + (uint32_t)x32);
  x34 = (x6 + x33);
  x35 = (x5 + x34);
  x36 = (x3 + (uint32_t)x4);
  x37 = (x2 + x36);
  x38 = (x1 + x37);
  out1[0] = x21;
  out1[1] = x26;
  out1[2] = x31;
  out1[3] = x35;
  out1[4] = x38;
}

