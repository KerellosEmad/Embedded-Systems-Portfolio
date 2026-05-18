/**
 * @file stats.h
 * @brief Function declarations for statistical analysis of an array
 *
 * AUTHOR : KERELLOS EMAD
 * DATE : 21-4-2026
 */

#ifndef STATS_H
#define STATS_H

/**
 * @brief Prints statistics of the array
 *
 * @param array Pointer to the data array
 * @param length Number of elements in the array
 */
void print_statistics(const unsigned char *array, unsigned int length);

/**
 * @brief Prints the array elements
 *
 * @param array Pointer to the data array
 * @param length Number of elements in the array
 */
void print_array(const unsigned char *array, unsigned int length);

/**
 * @brief Sorts the array in descending order
 *
 * @param array Pointer to the data array
 * @param length Number of elements in the array
 */
void sort_array(unsigned char *array, unsigned int length);

/**
 * @brief Finds the median value of the array
 *
 * @param array Pointer to the data array
 * @param length Number of elements in the array
 * @return Median value
 */
unsigned char find_median(const unsigned char *array, unsigned int length);

/**
 * @brief Calculates the mean of the array
 *
 * @param array Pointer to the data array
 * @param length Number of elements in the array
 * @return Mean value (rounded down)
 */
unsigned char find_mean(const unsigned char *array, unsigned int length);

/**
 * @brief Finds the maximum value in the array
 *
 * @param array Pointer to the data array
 * @param length Number of elements in the array
 * @return Maximum value
 */
unsigned char find_maximum(const unsigned char *array, unsigned int length);

/**
 * @brief Finds the minimum value in the array
 *
 * @param array Pointer to the data array
 * @param length Number of elements in the array
 * @return Minimum value
 */
unsigned char find_minimum(const unsigned char *array, unsigned int length);

#endif
