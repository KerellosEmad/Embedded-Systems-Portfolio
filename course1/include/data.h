/**
 * @file data.h
 * @brief Header file for data conversion function prototypes and macros.
 *
 * This file contains the declarations for ASCII-to-Integer and Integer-to-ASCII
 * conversion mechanisms alongside required numerical base macros.
 *
 * @author Kerellos Emad
 * @date May 2026
 *
 */

#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>

/* Numerical Base Constants required by course1 test functions */
#define BASE_10 (10)
#define BASE_16 (16)

/**
 * @brief Converts a signed 32-bit integer into an ASCII string.
 *
 * This function processes an integer value and converts it into a character
 * string representation based on the requested numerical base (2 through 16).
 * The resulting string is null-terminated and signed numbers are supported
 * for decimal outputs.
 *
 * @param data The signed 32-bit integer to convert
 * @param ptr Pointer to the destination string buffer memory
 * @param base The numerical radix layout (e.g., 2, 10, 16)
 *
 * @return The length of the converted character string (including sign, excluding null terminator)
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Converts an ASCII string back into a signed 32-bit integer.
 *
 * This function parses a character string representation of a number and 
 * converts it into its equivalent signed 32-bit integer form given the digits count
 * and specified numerical base layout.
 *
 * @param ptr Pointer to the source ASCII string memory block
 * @param digits The count of character symbols to parse
 * @param base The numerical radix layout (e.g., 2, 10, 16)
 *
 * @return The converted signed 32-bit integer value, or 0 upon execution failure
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
