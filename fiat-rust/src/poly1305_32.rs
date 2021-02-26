//! Autogenerated: 'src/ExtractionOCaml/unsaturated_solinas' --lang Rust poly1305 32 '(auto)' '2^130 - 5' carry_mul carry_square carry add sub opp selectznz to_bytes from_bytes
//! curve description: poly1305
//! machine_wordsize = 32 (from "32")
//! requested operations: carry_mul, carry_square, carry, add, sub, opp, selectznz, to_bytes, from_bytes
//! n = 5 (from "(auto)")
//! s-c = 2^130 - [(1, 5)] (from "2^130 - 5")
//! tight_bounds_multiplier = 1 (from "")
//!
//! Computed values:
//! carry_chain = [0, 1, 2, 3, 4, 0, 1]
//! eval z = z[0] + (z[1] << 26) + (z[2] << 52) + (z[3] << 78) + (z[4] << 104)
//! bytes_eval z = z[0] + (z[1] << 8) + (z[2] << 16) + (z[3] << 24) + (z[4] << 32) + (z[5] << 40) + (z[6] << 48) + (z[7] << 56) + (z[8] << 64) + (z[9] << 72) + (z[10] << 80) + (z[11] << 88) + (z[12] << 96) + (z[13] << 104) + (z[14] << 112) + (z[15] << 120) + (z[16] << 128)
//! balance = [0x7fffff6, 0x7fffffe, 0x7fffffe, 0x7fffffe, 0x7fffffe]

#![allow(unused_parens)]
#[allow(non_camel_case_types)]

pub type fiat_poly1305_u1 = u8;
pub type fiat_poly1305_i1 = i8;
pub type fiat_poly1305_u2 = u8;
pub type fiat_poly1305_i2 = i8;


/// The function fiat_poly1305_addcarryx_u26 is an addition with carry.
/// Postconditions:
///   out1 = (arg1 + arg2 + arg3) mod 2^26
///   out2 = ⌊(arg1 + arg2 + arg3) / 2^26⌋
///
/// Input Bounds:
///   arg1: [0x0 ~> 0x1]
///   arg2: [0x0 ~> 0x3ffffff]
///   arg3: [0x0 ~> 0x3ffffff]
/// Output Bounds:
///   out1: [0x0 ~> 0x3ffffff]
///   out2: [0x0 ~> 0x1]
#[inline]
pub fn fiat_poly1305_addcarryx_u26(out1: &mut u32, out2: &mut fiat_poly1305_u1, arg1: fiat_poly1305_u1, arg2: u32, arg3: u32) -> () {
  let x1: u32 = (((arg1 as u32) + arg2) + arg3);
  let x2: u32 = (x1 & 0x3ffffff);
  let x3: fiat_poly1305_u1 = ((x1 >> 26) as fiat_poly1305_u1);
  *out1 = x2;
  *out2 = x3;
}

/// The function fiat_poly1305_subborrowx_u26 is a subtraction with borrow.
/// Postconditions:
///   out1 = (-arg1 + arg2 + -arg3) mod 2^26
///   out2 = -⌊(-arg1 + arg2 + -arg3) / 2^26⌋
///
/// Input Bounds:
///   arg1: [0x0 ~> 0x1]
///   arg2: [0x0 ~> 0x3ffffff]
///   arg3: [0x0 ~> 0x3ffffff]
/// Output Bounds:
///   out1: [0x0 ~> 0x3ffffff]
///   out2: [0x0 ~> 0x1]
#[inline]
pub fn fiat_poly1305_subborrowx_u26(out1: &mut u32, out2: &mut fiat_poly1305_u1, arg1: fiat_poly1305_u1, arg2: u32, arg3: u32) -> () {
  let x1: i32 = ((((((arg2 as i64) - (arg1 as i64)) as i32) as i64) - (arg3 as i64)) as i32);
  let x2: fiat_poly1305_i1 = ((x1 >> 26) as fiat_poly1305_i1);
  let x3: u32 = (((x1 as i64) & (0x3ffffff as i64)) as u32);
  *out1 = x3;
  *out2 = (((0x0 as fiat_poly1305_i2) - (x2 as fiat_poly1305_i2)) as fiat_poly1305_u1);
}

/// The function fiat_poly1305_cmovznz_u32 is a single-word conditional move.
/// Postconditions:
///   out1 = (if arg1 = 0 then arg2 else arg3)
///
/// Input Bounds:
///   arg1: [0x0 ~> 0x1]
///   arg2: [0x0 ~> 0xffffffff]
///   arg3: [0x0 ~> 0xffffffff]
/// Output Bounds:
///   out1: [0x0 ~> 0xffffffff]
#[inline]
pub fn fiat_poly1305_cmovznz_u32(out1: &mut u32, arg1: fiat_poly1305_u1, arg2: u32, arg3: u32) -> () {
  let x1: fiat_poly1305_u1 = (!(!arg1));
  let x2: u32 = ((((((0x0 as fiat_poly1305_i2) - (x1 as fiat_poly1305_i2)) as fiat_poly1305_i1) as i64) & (0xffffffff as i64)) as u32);
  let x3: u32 = ((x2 & arg3) | ((!x2) & arg2));
  *out1 = x3;
}

/// The function fiat_poly1305_carry_mul multiplies two field elements and reduces the result.
/// Postconditions:
///   eval out1 mod m = (eval arg1 * eval arg2) mod m
///
/// Input Bounds:
///   arg1: [[0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000]]
///   arg2: [[0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000]]
/// Output Bounds:
///   out1: [[0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000]]
#[inline]
pub fn fiat_poly1305_carry_mul(out1: &mut [u32; 5], arg1: &[u32; 5], arg2: &[u32; 5]) -> () {
  let x1: u64 = (((arg1[4]) as u64) * (((arg2[4]) * 0x5) as u64));
  let x2: u64 = (((arg1[4]) as u64) * (((arg2[3]) * 0x5) as u64));
  let x3: u64 = (((arg1[4]) as u64) * (((arg2[2]) * 0x5) as u64));
  let x4: u64 = (((arg1[4]) as u64) * (((arg2[1]) * 0x5) as u64));
  let x5: u64 = (((arg1[3]) as u64) * (((arg2[4]) * 0x5) as u64));
  let x6: u64 = (((arg1[3]) as u64) * (((arg2[3]) * 0x5) as u64));
  let x7: u64 = (((arg1[3]) as u64) * (((arg2[2]) * 0x5) as u64));
  let x8: u64 = (((arg1[2]) as u64) * (((arg2[4]) * 0x5) as u64));
  let x9: u64 = (((arg1[2]) as u64) * (((arg2[3]) * 0x5) as u64));
  let x10: u64 = (((arg1[1]) as u64) * (((arg2[4]) * 0x5) as u64));
  let x11: u64 = (((arg1[4]) as u64) * ((arg2[0]) as u64));
  let x12: u64 = (((arg1[3]) as u64) * ((arg2[1]) as u64));
  let x13: u64 = (((arg1[3]) as u64) * ((arg2[0]) as u64));
  let x14: u64 = (((arg1[2]) as u64) * ((arg2[2]) as u64));
  let x15: u64 = (((arg1[2]) as u64) * ((arg2[1]) as u64));
  let x16: u64 = (((arg1[2]) as u64) * ((arg2[0]) as u64));
  let x17: u64 = (((arg1[1]) as u64) * ((arg2[3]) as u64));
  let x18: u64 = (((arg1[1]) as u64) * ((arg2[2]) as u64));
  let x19: u64 = (((arg1[1]) as u64) * ((arg2[1]) as u64));
  let x20: u64 = (((arg1[1]) as u64) * ((arg2[0]) as u64));
  let x21: u64 = (((arg1[0]) as u64) * ((arg2[4]) as u64));
  let x22: u64 = (((arg1[0]) as u64) * ((arg2[3]) as u64));
  let x23: u64 = (((arg1[0]) as u64) * ((arg2[2]) as u64));
  let x24: u64 = (((arg1[0]) as u64) * ((arg2[1]) as u64));
  let x25: u64 = (((arg1[0]) as u64) * ((arg2[0]) as u64));
  let x26: u64 = (x25 + (x10 + (x9 + (x7 + x4))));
  let x27: u64 = (x26 >> 26);
  let x28: u32 = ((x26 & (0x3ffffff as u64)) as u32);
  let x29: u64 = (x21 + (x17 + (x14 + (x12 + x11))));
  let x30: u64 = (x22 + (x18 + (x15 + (x13 + x1))));
  let x31: u64 = (x23 + (x19 + (x16 + (x5 + x2))));
  let x32: u64 = (x24 + (x20 + (x8 + (x6 + x3))));
  let x33: u64 = (x27 + x32);
  let x34: u64 = (x33 >> 26);
  let x35: u32 = ((x33 & (0x3ffffff as u64)) as u32);
  let x36: u64 = (x34 + x31);
  let x37: u64 = (x36 >> 26);
  let x38: u32 = ((x36 & (0x3ffffff as u64)) as u32);
  let x39: u64 = (x37 + x30);
  let x40: u64 = (x39 >> 26);
  let x41: u32 = ((x39 & (0x3ffffff as u64)) as u32);
  let x42: u64 = (x40 + x29);
  let x43: u32 = ((x42 >> 26) as u32);
  let x44: u32 = ((x42 & (0x3ffffff as u64)) as u32);
  let x45: u64 = ((x43 as u64) * (0x5 as u64));
  let x46: u64 = ((x28 as u64) + x45);
  let x47: u32 = ((x46 >> 26) as u32);
  let x48: u32 = ((x46 & (0x3ffffff as u64)) as u32);
  let x49: u32 = (x47 + x35);
  let x50: fiat_poly1305_u1 = ((x49 >> 26) as fiat_poly1305_u1);
  let x51: u32 = (x49 & 0x3ffffff);
  let x52: u32 = ((x50 as u32) + x38);
  out1[0] = x48;
  out1[1] = x51;
  out1[2] = x52;
  out1[3] = x41;
  out1[4] = x44;
}

/// The function fiat_poly1305_carry_square squares a field element and reduces the result.
/// Postconditions:
///   eval out1 mod m = (eval arg1 * eval arg1) mod m
///
/// Input Bounds:
///   arg1: [[0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000]]
/// Output Bounds:
///   out1: [[0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000]]
#[inline]
pub fn fiat_poly1305_carry_square(out1: &mut [u32; 5], arg1: &[u32; 5]) -> () {
  let x1: u32 = ((arg1[4]) * 0x5);
  let x2: u32 = (x1 * 0x2);
  let x3: u32 = ((arg1[4]) * 0x2);
  let x4: u32 = ((arg1[3]) * 0x5);
  let x5: u32 = (x4 * 0x2);
  let x6: u32 = ((arg1[3]) * 0x2);
  let x7: u32 = ((arg1[2]) * 0x2);
  let x8: u32 = ((arg1[1]) * 0x2);
  let x9: u64 = (((arg1[4]) as u64) * (x1 as u64));
  let x10: u64 = (((arg1[3]) as u64) * (x2 as u64));
  let x11: u64 = (((arg1[3]) as u64) * (x4 as u64));
  let x12: u64 = (((arg1[2]) as u64) * (x2 as u64));
  let x13: u64 = (((arg1[2]) as u64) * (x5 as u64));
  let x14: u64 = (((arg1[2]) as u64) * ((arg1[2]) as u64));
  let x15: u64 = (((arg1[1]) as u64) * (x2 as u64));
  let x16: u64 = (((arg1[1]) as u64) * (x6 as u64));
  let x17: u64 = (((arg1[1]) as u64) * (x7 as u64));
  let x18: u64 = (((arg1[1]) as u64) * ((arg1[1]) as u64));
  let x19: u64 = (((arg1[0]) as u64) * (x3 as u64));
  let x20: u64 = (((arg1[0]) as u64) * (x6 as u64));
  let x21: u64 = (((arg1[0]) as u64) * (x7 as u64));
  let x22: u64 = (((arg1[0]) as u64) * (x8 as u64));
  let x23: u64 = (((arg1[0]) as u64) * ((arg1[0]) as u64));
  let x24: u64 = (x23 + (x15 + x13));
  let x25: u64 = (x24 >> 26);
  let x26: u32 = ((x24 & (0x3ffffff as u64)) as u32);
  let x27: u64 = (x19 + (x16 + x14));
  let x28: u64 = (x20 + (x17 + x9));
  let x29: u64 = (x21 + (x18 + x10));
  let x30: u64 = (x22 + (x12 + x11));
  let x31: u64 = (x25 + x30);
  let x32: u64 = (x31 >> 26);
  let x33: u32 = ((x31 & (0x3ffffff as u64)) as u32);
  let x34: u64 = (x32 + x29);
  let x35: u64 = (x34 >> 26);
  let x36: u32 = ((x34 & (0x3ffffff as u64)) as u32);
  let x37: u64 = (x35 + x28);
  let x38: u64 = (x37 >> 26);
  let x39: u32 = ((x37 & (0x3ffffff as u64)) as u32);
  let x40: u64 = (x38 + x27);
  let x41: u32 = ((x40 >> 26) as u32);
  let x42: u32 = ((x40 & (0x3ffffff as u64)) as u32);
  let x43: u64 = ((x41 as u64) * (0x5 as u64));
  let x44: u64 = ((x26 as u64) + x43);
  let x45: u32 = ((x44 >> 26) as u32);
  let x46: u32 = ((x44 & (0x3ffffff as u64)) as u32);
  let x47: u32 = (x45 + x33);
  let x48: fiat_poly1305_u1 = ((x47 >> 26) as fiat_poly1305_u1);
  let x49: u32 = (x47 & 0x3ffffff);
  let x50: u32 = ((x48 as u32) + x36);
  out1[0] = x46;
  out1[1] = x49;
  out1[2] = x50;
  out1[3] = x39;
  out1[4] = x42;
}

/// The function fiat_poly1305_carry reduces a field element.
/// Postconditions:
///   eval out1 mod m = eval arg1 mod m
///
/// Input Bounds:
///   arg1: [[0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000]]
/// Output Bounds:
///   out1: [[0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000]]
#[inline]
pub fn fiat_poly1305_carry(out1: &mut [u32; 5], arg1: &[u32; 5]) -> () {
  let x1: u32 = (arg1[0]);
  let x2: u32 = ((x1 >> 26) + (arg1[1]));
  let x3: u32 = ((x2 >> 26) + (arg1[2]));
  let x4: u32 = ((x3 >> 26) + (arg1[3]));
  let x5: u32 = ((x4 >> 26) + (arg1[4]));
  let x6: u32 = ((x1 & 0x3ffffff) + ((x5 >> 26) * 0x5));
  let x7: u32 = ((((x6 >> 26) as fiat_poly1305_u1) as u32) + (x2 & 0x3ffffff));
  let x8: u32 = (x6 & 0x3ffffff);
  let x9: u32 = (x7 & 0x3ffffff);
  let x10: u32 = ((((x7 >> 26) as fiat_poly1305_u1) as u32) + (x3 & 0x3ffffff));
  let x11: u32 = (x4 & 0x3ffffff);
  let x12: u32 = (x5 & 0x3ffffff);
  out1[0] = x8;
  out1[1] = x9;
  out1[2] = x10;
  out1[3] = x11;
  out1[4] = x12;
}

/// The function fiat_poly1305_add adds two field elements.
/// Postconditions:
///   eval out1 mod m = (eval arg1 + eval arg2) mod m
///
/// Input Bounds:
///   arg1: [[0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000]]
///   arg2: [[0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000]]
/// Output Bounds:
///   out1: [[0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000]]
#[inline]
pub fn fiat_poly1305_add(out1: &mut [u32; 5], arg1: &[u32; 5], arg2: &[u32; 5]) -> () {
  let x1: u32 = ((arg1[0]) + (arg2[0]));
  let x2: u32 = ((arg1[1]) + (arg2[1]));
  let x3: u32 = ((arg1[2]) + (arg2[2]));
  let x4: u32 = ((arg1[3]) + (arg2[3]));
  let x5: u32 = ((arg1[4]) + (arg2[4]));
  out1[0] = x1;
  out1[1] = x2;
  out1[2] = x3;
  out1[3] = x4;
  out1[4] = x5;
}

/// The function fiat_poly1305_sub subtracts two field elements.
/// Postconditions:
///   eval out1 mod m = (eval arg1 - eval arg2) mod m
///
/// Input Bounds:
///   arg1: [[0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000]]
///   arg2: [[0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000]]
/// Output Bounds:
///   out1: [[0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000]]
#[inline]
pub fn fiat_poly1305_sub(out1: &mut [u32; 5], arg1: &[u32; 5], arg2: &[u32; 5]) -> () {
  let x1: u32 = ((0x7fffff6 + (arg1[0])) - (arg2[0]));
  let x2: u32 = ((0x7fffffe + (arg1[1])) - (arg2[1]));
  let x3: u32 = ((0x7fffffe + (arg1[2])) - (arg2[2]));
  let x4: u32 = ((0x7fffffe + (arg1[3])) - (arg2[3]));
  let x5: u32 = ((0x7fffffe + (arg1[4])) - (arg2[4]));
  out1[0] = x1;
  out1[1] = x2;
  out1[2] = x3;
  out1[3] = x4;
  out1[4] = x5;
}

/// The function fiat_poly1305_opp negates a field element.
/// Postconditions:
///   eval out1 mod m = -eval arg1 mod m
///
/// Input Bounds:
///   arg1: [[0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000]]
/// Output Bounds:
///   out1: [[0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000], [0x0 ~> 0xc000000]]
#[inline]
pub fn fiat_poly1305_opp(out1: &mut [u32; 5], arg1: &[u32; 5]) -> () {
  let x1: u32 = (0x7fffff6 - (arg1[0]));
  let x2: u32 = (0x7fffffe - (arg1[1]));
  let x3: u32 = (0x7fffffe - (arg1[2]));
  let x4: u32 = (0x7fffffe - (arg1[3]));
  let x5: u32 = (0x7fffffe - (arg1[4]));
  out1[0] = x1;
  out1[1] = x2;
  out1[2] = x3;
  out1[3] = x4;
  out1[4] = x5;
}

/// The function fiat_poly1305_selectznz is a multi-limb conditional select.
/// Postconditions:
///   eval out1 = (if arg1 = 0 then eval arg2 else eval arg3)
///
/// Input Bounds:
///   arg1: [0x0 ~> 0x1]
///   arg2: [[0x0 ~> 0xffffffff], [0x0 ~> 0xffffffff], [0x0 ~> 0xffffffff], [0x0 ~> 0xffffffff], [0x0 ~> 0xffffffff]]
///   arg3: [[0x0 ~> 0xffffffff], [0x0 ~> 0xffffffff], [0x0 ~> 0xffffffff], [0x0 ~> 0xffffffff], [0x0 ~> 0xffffffff]]
/// Output Bounds:
///   out1: [[0x0 ~> 0xffffffff], [0x0 ~> 0xffffffff], [0x0 ~> 0xffffffff], [0x0 ~> 0xffffffff], [0x0 ~> 0xffffffff]]
#[inline]
pub fn fiat_poly1305_selectznz(out1: &mut [u32; 5], arg1: fiat_poly1305_u1, arg2: &[u32; 5], arg3: &[u32; 5]) -> () {
  let mut x1: u32 = 0;
  fiat_poly1305_cmovznz_u32(&mut x1, arg1, (arg2[0]), (arg3[0]));
  let mut x2: u32 = 0;
  fiat_poly1305_cmovznz_u32(&mut x2, arg1, (arg2[1]), (arg3[1]));
  let mut x3: u32 = 0;
  fiat_poly1305_cmovznz_u32(&mut x3, arg1, (arg2[2]), (arg3[2]));
  let mut x4: u32 = 0;
  fiat_poly1305_cmovznz_u32(&mut x4, arg1, (arg2[3]), (arg3[3]));
  let mut x5: u32 = 0;
  fiat_poly1305_cmovznz_u32(&mut x5, arg1, (arg2[4]), (arg3[4]));
  out1[0] = x1;
  out1[1] = x2;
  out1[2] = x3;
  out1[3] = x4;
  out1[4] = x5;
}

/// The function fiat_poly1305_to_bytes serializes a field element to bytes in little-endian order.
/// Postconditions:
///   out1 = map (λ x, ⌊((eval arg1 mod m) mod 2^(8 * (x + 1))) / 2^(8 * x)⌋) [0..16]
///
/// Input Bounds:
///   arg1: [[0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000]]
/// Output Bounds:
///   out1: [[0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0x3]]
#[inline]
pub fn fiat_poly1305_to_bytes(out1: &mut [u8; 17], arg1: &[u32; 5]) -> () {
  let mut x1: u32 = 0;
  let mut x2: fiat_poly1305_u1 = 0;
  fiat_poly1305_subborrowx_u26(&mut x1, &mut x2, 0x0, (arg1[0]), 0x3fffffb);
  let mut x3: u32 = 0;
  let mut x4: fiat_poly1305_u1 = 0;
  fiat_poly1305_subborrowx_u26(&mut x3, &mut x4, x2, (arg1[1]), 0x3ffffff);
  let mut x5: u32 = 0;
  let mut x6: fiat_poly1305_u1 = 0;
  fiat_poly1305_subborrowx_u26(&mut x5, &mut x6, x4, (arg1[2]), 0x3ffffff);
  let mut x7: u32 = 0;
  let mut x8: fiat_poly1305_u1 = 0;
  fiat_poly1305_subborrowx_u26(&mut x7, &mut x8, x6, (arg1[3]), 0x3ffffff);
  let mut x9: u32 = 0;
  let mut x10: fiat_poly1305_u1 = 0;
  fiat_poly1305_subborrowx_u26(&mut x9, &mut x10, x8, (arg1[4]), 0x3ffffff);
  let mut x11: u32 = 0;
  fiat_poly1305_cmovznz_u32(&mut x11, x10, (0x0 as u32), 0xffffffff);
  let mut x12: u32 = 0;
  let mut x13: fiat_poly1305_u1 = 0;
  fiat_poly1305_addcarryx_u26(&mut x12, &mut x13, 0x0, x1, (x11 & 0x3fffffb));
  let mut x14: u32 = 0;
  let mut x15: fiat_poly1305_u1 = 0;
  fiat_poly1305_addcarryx_u26(&mut x14, &mut x15, x13, x3, (x11 & 0x3ffffff));
  let mut x16: u32 = 0;
  let mut x17: fiat_poly1305_u1 = 0;
  fiat_poly1305_addcarryx_u26(&mut x16, &mut x17, x15, x5, (x11 & 0x3ffffff));
  let mut x18: u32 = 0;
  let mut x19: fiat_poly1305_u1 = 0;
  fiat_poly1305_addcarryx_u26(&mut x18, &mut x19, x17, x7, (x11 & 0x3ffffff));
  let mut x20: u32 = 0;
  let mut x21: fiat_poly1305_u1 = 0;
  fiat_poly1305_addcarryx_u26(&mut x20, &mut x21, x19, x9, (x11 & 0x3ffffff));
  let x22: u32 = (x18 << 6);
  let x23: u32 = (x16 << 4);
  let x24: u32 = (x14 << 2);
  let x25: u8 = ((x12 & (0xff as u32)) as u8);
  let x26: u32 = (x12 >> 8);
  let x27: u8 = ((x26 & (0xff as u32)) as u8);
  let x28: u32 = (x26 >> 8);
  let x29: u8 = ((x28 & (0xff as u32)) as u8);
  let x30: u8 = ((x28 >> 8) as u8);
  let x31: u32 = (x24 + (x30 as u32));
  let x32: u8 = ((x31 & (0xff as u32)) as u8);
  let x33: u32 = (x31 >> 8);
  let x34: u8 = ((x33 & (0xff as u32)) as u8);
  let x35: u32 = (x33 >> 8);
  let x36: u8 = ((x35 & (0xff as u32)) as u8);
  let x37: u8 = ((x35 >> 8) as u8);
  let x38: u32 = (x23 + (x37 as u32));
  let x39: u8 = ((x38 & (0xff as u32)) as u8);
  let x40: u32 = (x38 >> 8);
  let x41: u8 = ((x40 & (0xff as u32)) as u8);
  let x42: u32 = (x40 >> 8);
  let x43: u8 = ((x42 & (0xff as u32)) as u8);
  let x44: u8 = ((x42 >> 8) as u8);
  let x45: u32 = (x22 + (x44 as u32));
  let x46: u8 = ((x45 & (0xff as u32)) as u8);
  let x47: u32 = (x45 >> 8);
  let x48: u8 = ((x47 & (0xff as u32)) as u8);
  let x49: u32 = (x47 >> 8);
  let x50: u8 = ((x49 & (0xff as u32)) as u8);
  let x51: u8 = ((x49 >> 8) as u8);
  let x52: u8 = ((x20 & (0xff as u32)) as u8);
  let x53: u32 = (x20 >> 8);
  let x54: u8 = ((x53 & (0xff as u32)) as u8);
  let x55: u32 = (x53 >> 8);
  let x56: u8 = ((x55 & (0xff as u32)) as u8);
  let x57: u8 = ((x55 >> 8) as u8);
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

/// The function fiat_poly1305_from_bytes deserializes a field element from bytes in little-endian order.
/// Postconditions:
///   eval out1 mod m = bytes_eval arg1 mod m
///
/// Input Bounds:
///   arg1: [[0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0x3]]
/// Output Bounds:
///   out1: [[0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000], [0x0 ~> 0x4000000]]
#[inline]
pub fn fiat_poly1305_from_bytes(out1: &mut [u32; 5], arg1: &[u8; 17]) -> () {
  let x1: u32 = (((arg1[16]) as u32) << 24);
  let x2: u32 = (((arg1[15]) as u32) << 16);
  let x3: u32 = (((arg1[14]) as u32) << 8);
  let x4: u8 = (arg1[13]);
  let x5: u32 = (((arg1[12]) as u32) << 18);
  let x6: u32 = (((arg1[11]) as u32) << 10);
  let x7: u32 = (((arg1[10]) as u32) << 2);
  let x8: u32 = (((arg1[9]) as u32) << 20);
  let x9: u32 = (((arg1[8]) as u32) << 12);
  let x10: u32 = (((arg1[7]) as u32) << 4);
  let x11: u32 = (((arg1[6]) as u32) << 22);
  let x12: u32 = (((arg1[5]) as u32) << 14);
  let x13: u32 = (((arg1[4]) as u32) << 6);
  let x14: u32 = (((arg1[3]) as u32) << 24);
  let x15: u32 = (((arg1[2]) as u32) << 16);
  let x16: u32 = (((arg1[1]) as u32) << 8);
  let x17: u8 = (arg1[0]);
  let x18: u32 = (x16 + (x17 as u32));
  let x19: u32 = (x15 + x18);
  let x20: u32 = (x14 + x19);
  let x21: u32 = (x20 & 0x3ffffff);
  let x22: u8 = ((x20 >> 26) as u8);
  let x23: u32 = (x13 + (x22 as u32));
  let x24: u32 = (x12 + x23);
  let x25: u32 = (x11 + x24);
  let x26: u32 = (x25 & 0x3ffffff);
  let x27: u8 = ((x25 >> 26) as u8);
  let x28: u32 = (x10 + (x27 as u32));
  let x29: u32 = (x9 + x28);
  let x30: u32 = (x8 + x29);
  let x31: u32 = (x30 & 0x3ffffff);
  let x32: u8 = ((x30 >> 26) as u8);
  let x33: u32 = (x7 + (x32 as u32));
  let x34: u32 = (x6 + x33);
  let x35: u32 = (x5 + x34);
  let x36: u32 = (x3 + (x4 as u32));
  let x37: u32 = (x2 + x36);
  let x38: u32 = (x1 + x37);
  out1[0] = x21;
  out1[1] = x26;
  out1[2] = x31;
  out1[3] = x35;
  out1[4] = x38;
}

