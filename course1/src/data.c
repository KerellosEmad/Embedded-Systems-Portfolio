/******************************************************************************
 * Copyright (C) 2026 by Kerellos Emad
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright.
 *
 *****************************************************************************/
/**
 * @file data.c
 * @brief Implementation file for data conversion utilities.
 *
 * This file provides signed integer to ASCII conversion and vice versa 
 * via standard pointer arithmetic manipulation.
 *
 * @author Kerellos Emad
 * @date May 2026
 *
 */

#include <stdint.h>
#include <stddef.h>
#include "data.h"
#include "memory.h" // For my_reverse if needed

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
    if (ptr == NULL || base < 2 || base > 16) {
        return 0;
    }

    uint8_t *start = ptr;
    uint32_t len = 0;
    int is_negative = 0;

    // Handle 0 explicitly
    if (data == 0) {
        *ptr++ = '0';
        *ptr = '\0';
        return 1;
    }

    // Handle negative numbers only for base 10
    if (data < 0 && base == 10) {
        is_negative = 1;
        // Handle absolute value carefully to avoid overflow on INT32_MIN
        uint32_t abs_data = (uint32_t)(-(data + 1)) + 1;
        while (abs_data > 0) {
            uint32_t remainder = abs_data % base;
            *ptr++ = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'a');
            abs_data /= base;
            len++;
        }
    } else {
        // Unsigned treatment for non-base-10 or positive numbers
        uint32_t unsigned_data = (uint32_t)data;
        while (unsigned_data > 0) {
            uint32_t remainder = unsigned_data % base;
            *ptr++ = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'a');
            unsigned_data /= base;
            len++;
        }
    }

    // Append negative sign if needed
    if (is_negative) {
        *ptr++ = '-';
        len++;
    }

    // Null-terminate the string
    *ptr = '\0';

    // Reverse the generated string in-place to get correct order
    my_reverse(start, len);

    return len;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
    if (ptr == NULL || digits == 0 || base < 2 || base > 16) {
        return 0;
    }

    int32_t result = 0;
    int is_negative = 0;
    uint8_t i = 0;

    // Check for negative sign indicator (base 10 specific usually)
    if (ptr[0] == '-') {
        is_negative = 1;
        i++;
    } else if (ptr[0] == '+') {
        i++;
    }

    // Process each character code symbol
    for (; i < digits; i++) {
        if (ptr[i] == '\0') {
            break; 
        }

        uint8_t value;
        if (ptr[i] >= '0' && ptr[i] <= '9') {
            value = ptr[i] - '0';
        } else if (ptr[i] >= 'a' && ptr[i] <= 'f') {
            value = ptr[i] - 'a' + 10;
        } else if (ptr[i] >= 'A' && ptr[i] <= 'F') {
            value = ptr[i] - 'A' + 10;
        } else {
            break; // Non-alphanumeric symbol breakthrough
        }

        if (value >= base) {
            break; // Sanity protection check against base mismatch
        }

        result = (result * base) + value;
    }

    if (is_negative) {
        result = -result;
    }

    return result;
}
