/*****************************************************************************/
/**
 * @file data.c
 * @brief Implementation file for standard data conversion operations.
 *
 * This file provides custom ASCII-to-Integer and Integer-to-ASCII conversion
 * mechanisms using pointer arithmetic and primitive math operations.
 *
 * @author Kerellos Emad
 * @date May 2026
 *
 */

#include <stdint.h>
#include <stddef.h>
#include "data.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
    if (ptr == NULL || base < 2 || base > 16) {
        return 0;
    }

    uint8_t * start_ptr = ptr;
    int32_t temp_data = data;
    uint8_t is_negative = 0;

    // Handle 0 explicitly
    if (data == 0) {
        *ptr = '0';
        ptr++;
        *ptr = '\0';
        return 2; // '0' and '\0'
    }

    // Handle negative numbers for base 10
    if (data < 0 && base == 10) {
        is_negative = 1;
        // Check for integer underflow boundary before absolute conversion
        if (temp_data == INT32_MIN) {
            // Hardcode standard INT32_MIN string processing or step it manually
            // An easier trick is working with negative modulo or shifting types
        }
    }

    // Process digits backward into the string buffer
    while (temp_data != 0) {
        int32_t remainder = temp_data % (int32_t)base;
        if (remainder < 0) {
            remainder = -remainder; // Strip sign for character resolution
        }
        
        // Resolve digit character representation
        if (remainder < 10) {
            *ptr = (uint8_t)(remainder + '0');
        } else {
            *ptr = (uint8_t)((remainder - 10) + 'A');
        }
        ptr++;
        temp_data /= (int32_t)base;
    }

    // Append negative symbol if flagged
    if (is_negative) {
        *ptr = '-';
        ptr++;
    }

    // Append Null Terminator to cap the string layout
    *ptr = '\0';
    uint8_t length = (uint8_t)(ptr - start_ptr);

    // Reverse the working string in place to fix the backward generation
    uint8_t * rev_start = start_ptr;
    uint8_t * rev_end = ptr - 1;
    while (rev_start < rev_end) {
        uint8_t temp = *rev_start;
        *rev_start = *rev_end;
        *rev_end = temp;
        rev_start++;
        rev_end--;
    }

    return length;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
    if (ptr == NULL || digits == 0 || base < 2 || base > 16) {
        return 0;
    }

    int32_t result = 0;
    uint8_t is_negative = 0;
    uint8_t i = 0;

    // Inspect first character index for negative sign flag
    if (*ptr == '-') {
        is_negative = 1;
        i++;
    }

    // Parse loop passing through valid non-null characters
    while (i < digits && *(ptr + i) != '\0') {
        uint8_t current_char = *(ptr + i);
        uint32_t digit_value = 0;

        if (current_char >= '0' && current_char <= '9') {
            digit_value = current_char - '0';
        } else if (current_char >= 'A' && current_char <= 'F') {
            digit_value = current_char - 'A' + 10;
        } else if (current_char >= 'a' && current_char <= 'f') {
            digit_value = current_char - 'a' + 10;
        } else {
            break; // Break execution on invalid symbol detection
        }

        // Out of range validation check for base configurations
        if (digit_value >= base) {
            break;
        }

        result = (result * base) + digit_value;
        i++;
    }

    if (is_negative) {
        result = -result;
    }

    return result;
}
