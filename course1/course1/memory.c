/******************************************************************************
 * Copyright (C) 2026 by Kerellos Emad
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright.
 *
 *****************************************************************************/
/**
 * @file memory.c
 * @brief Implementation file for custom memory manipulation functions.
 *
 * This file provides various custom utilities to manipulate memory blocks
 * via byte-level pointer arithmetic, avoiding standard library overrides.
 *
 * @author Kerellos Emad
 * @date May 2026
 *
 */

#include <stdint.h>
#include <stdlib.h>
#include "memory.h" // Fixed: Points to the header file, not itself!

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, uint32_t length) {
    if (src == NULL || dst == NULL || length == 0) {
        return dst;
    }

    /* Check for memory overlap. If destination is ahead of source 
     * but still within the range of length, copy backwards to prevent 
     * overwriting source data before it's moved. */
    if (dst > src && dst < (src + length)) {
        for (uint32_t i = length; i > 0; i--) {
            *(dst + i - 1) = *(src + i - 1);
        }
    } 
    // Otherwise, copy forward safely
    else {
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

    // Standard forward copy routine. Overlap behavior is undefined.
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
    if (src == NULL || length == 0) {
        return src;
    }

    for (uint32_t i = 0; i < length; i++) {
        *(src + i) = 0;
    }

    return src;
}

uint8_t * my_reverse(uint8_t * src, uint32_t length) {
    if (src == NULL || length == 0) {
        return src;
    }

    uint32_t start = 0;
    uint32_t end = length - 1;
    uint8_t temp;

    // Swap bytes from outside inward until pointers meet in the middle
    while (start < end) {
        temp = *(src + start);
        *(src + start) = *(src + end);
        *(src + end) = temp;
        start++;
        end--;
    }

    return src;
}

int32_t * reserve_words(uint32_t length) {
    if (length == 0) {
        return NULL;
    }

    // Allocate memory on the heap matching the total word count requested
    int32_t * ptr = (int32_t *)malloc(length * sizeof(int32_t));
    
    return ptr;
}

void free_words(int32_t * src) {
    if (src != NULL) {
        free(src);
    }
}
