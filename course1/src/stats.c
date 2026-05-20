/******************************************************************************
 * Copyright (C) 2026 by Kerellos Emad
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright.
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief Implementation file for array statistics reporting module.
 *
 * This file implements the mathematical manipulation and sorting functions
 * required to calculate the median, mean, maximum, and minimum values of an array.
 *
 * @author Kerellos Emad
 * @date May 2026
 *
 */

#include <stdio.h>
#include <stdint.h>
#include "stats.h"
#include "platform.h"

void print_statistics(const uint8_t *array, uint32_t length) {
    if (array == NULL || length == 0) return;

    PRINTF("=== Array Statistics ===\n");
    PRINTF("Minimum: %d\n", find_minimum(array, length));
    PRINTF("Maximum: %d\n", find_maximum(array, length));
    PRINTF("Mean:    %d\n", find_mean(array, length));
    PRINTF("Median:  %d\n", find_median(array, length));
    PRINTF("========================\n");
}

void print_array(const uint8_t *ptr, uint32_t length) {
#ifdef VERBOSE
    if (ptr == NULL || length == 0) return;

    PRINTF("Array Elements:\n");
    for (uint32_t i = 0; i < length; i++) {
        PRINTF("[Index %d]: %d\n", i, ptr[i]);
    }
    PRINTF("\n");
#endif
}

uint8_t find_median(const uint8_t *array, uint32_t length) {
    if (array == NULL || length == 0) return 0;

    // Create a local buffer to safely sort without modifying the original data
    uint8_t copy[length];
    for (uint32_t i = 0; i < length; i++) {
        copy[i] = array[i];
    }

    sort_array(copy, length);

    if (length % 2 == 0) {
        return (copy[(length / 2) - 1] + copy[length / 2]) / 2;
    } else {
        return copy[length / 2];
    }
}

uint8_t find_mean(const uint8_t *array, uint32_t length) {
    if (array == NULL || length == 0) return 0;

    uint32_t sum = 0;
    for (uint32_t i = 0; i < length; i++) {
        sum += array[i];
    }

    return (uint8_t)(sum / length);
}

uint8_t find_maximum(const uint8_t *array, uint32_t length) {
    if (array == NULL || length == 0) return 0;

    uint8_t max = array[0];
    for (uint32_t i = 1; i < length; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

uint8_t find_minimum(const uint8_t *array, uint32_t length) {
    if (array == NULL || length == 0) return 0;

    uint8_t min = array[0];
    for (uint32_t i = 1; i < length; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

void sort_array(uint8_t *array, uint32_t length) {
    if (array == NULL || length == 0) return;

    // Simple Bubble Sort (Descending order)
    for (uint32_t i = 0; i < length - 1; i++) {
        for (uint32_t j = 0; j < length - i - 1; j++) {
            if (array[j] < array[j + 1]) {
                uint8_t temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
