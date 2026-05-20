/******************************************************************************
 * Copyright (C) 2026 by Kerellos Emad
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright.
 *
 *****************************************************************************/
/**
 * @file memory.c
 * @brief Implementation file for memory manipulation functions.
 *
 * This file contains byte-level memory operations using raw pointer
 * arithmetic, satisfying the architectural demands of the course assessment.
 *
 * @author Kerellos Emad
 * @date May 2026
 *
 */

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include "memory.h"

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, uint32_t length) {
    if (src == NULL || dst == NULL || length == 0) {
        return dst;
    }

    // Handle overlapping memory regions safely
    if (dst > src && dst < (src + length)) {
        // Copy from back to front
        for (uint32_t i = length; i > 0; i--) {
            *(dst + i - 1) = *(src + i - 1);
        }
    } else {
        // Copy from front to back
        for (uint32_t i = 0; i < length; i++) {
            *(dst + i) = *(src + i);
        }
    }

    return dst;
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, uint32_t length) {
    if (src == NULL || dst == NULL || length == 0) {
        return dst;
    }

    for (uint32_t i = 0; i < length; i++) {
        *(dst + i) = *(src + i);
    }

    return dst;
}

uint8_t * my_memset(uint8_t * src, uint32_t length, uint8_t value) {
    if (src == NULL || length == 0) {
        return src;
    }

    for (uint32_t i = 0; i < length; i++) {
        *(src + i) = value;
    }

    return src;
}

uint8_t * my_memzero(uint8_t * src, uint32_t length) {
    return my_memset(src, length, 0);
}

uint8_t * my_reverse(uint8_t * src, uint32_t length) {
    if (src == NULL || length == 0) {
        return src;
    }

    uint8_t * start = src;
    uint8_t * end = src + length - 1;
    uint8_t temp;

    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    return src;
}

int32_t * reserve_words(uint32_t length) {
    if (length == 0) {
        return NULL;
    }
    
    // Allocate space based on 32-bit words
    return (int32_t *)malloc(length * sizeof(uint32_t));
}

void free_words(uint32_t * src) {
    if (src != NULL) {
        free((void *)src);
    }
}
