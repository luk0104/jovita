#ifndef __MACHINE_H
#define __MACHINE_H

/* Registers */
#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define R4 4
#define R5 5
#define R6 6
#define R7 7
#define R8 8
#define R9 9

/**
 * No operation
 *
 * noop
 */
//#define NOOP 0x00

/**
 * Absolute value
 *
 * abs Rdest, Rsrc
 */
#define ABS 0x01

/**
 * Substract
 *
 * sub Rdest, src1, src2
 */
#define SUB 0x03

/**
 * Negate value
 *
 * neg Rdest, src
 */
#define NEG 0x04

/**
 * OR
 *
 * or Rdest, src1, src2
 */
#define OR 0x06

/**
 * XOR
 *
 * xor Rdest, src1, src2
 */
#define XOR 0x07

#endif /* __MACHINE_H */
