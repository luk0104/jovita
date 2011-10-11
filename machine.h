#ifndef __MACHINE_H
#define __MACHINE_H

/**
 * Absolute value
 *
 * abs Rdest, Rsrc
 */
#define ABS 0x01

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
