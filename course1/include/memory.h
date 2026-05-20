/**
 * @file memory.h
 * @brief Header file for memory manipulation function prototypes.
 *
 * This file contains the declarations and structural specifications for 
 * custom byte-level memory operations using pure pointer arithmetic.
 *
 * @author Kerellos Emad
 * @date May 2026
 *
 */

#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>
#include <stddef.h>

/**
 * @brief Moves a block of data from a source to a destination.
 *
 * This function copies a specified length of bytes from a source memory
 * location to a destination location. It safely handles overlapping memory
 * regions without data corruption by checking the address boundaries.
 *
 * @param src Pointer to the source memory block
 * @param dst Pointer to the destination memory block
 * @param length Number of bytes to move
 *
 * @return Pointer to the destination memory block (dst)
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, uint32_t length);

/**
 * @brief Copies a block of data from a source to a destination.
 *
 * This function copies a specified length of bytes from a source memory
 * location to a destination location. The behavior is undefined if the
 * source and destination memory regions overlap.
 *
 * @param src Pointer to the source memory block
 * @param dst Pointer to the destination memory block
 * @param length Number of bytes to copy
 *
 * @return Pointer to the destination memory block (dst)
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, uint32_t length);

/**
 * @brief Sets all bytes of a memory block to a specified value.
 *
 * This function takes a pointer to a memory location and sets a given
 * number of bytes to the specified uniform value.
 *
 * @param src Pointer to the memory block to set
 * @param length Number of bytes to set
 * @param value The byte value to be written across the block
 *
 * @return Pointer to the modified memory block (src)
 */
uint8_t * my_memset(uint8_t * src, uint32_t length, uint8_t value);

/**
 * @brief Zeroes out all bytes of a memory block.
 *
 * This function takes a pointer to a memory location and sets a given
 * number of bytes to zero (0).
 *
 * @param src Pointer to the memory block to clear
 * @param length Number of bytes to zero out
 *
 * @return Pointer to the modified memory block (src)
 */
uint8_t * my_memzero(uint8_t * src, uint32_t length);

/**
 * @brief Reverses the order of bytes within a memory block.
 *
 * This function takes a pointer to a memory region and reverses the order
 * of all bytes within the specified length in place.
 *
 * @param src Pointer to the memory block to reverse
 * @param length Number of bytes to reverse
 *
 * @return Pointer to the reversed memory block (src)
 */
uint8_t * my_reverse(uint8_t * src, uint32_t length);

/**
 * @brief Dynamically allocates a block of 32-bit words on the heap.
 *
 * This function allocates space for a specified number of 32-bit integer 
 * words using dynamic memory allocation and returns a pointer to the block.
 *
 * @param length Number of 32-bit words to allocate
 *
 * @return Pointer to the allocated memory block, or NULL if allocation fails
 */
int32_t * reserve_words(uint32_t length);

/**
 * @brief Frees a dynamically allocated block of memory.
 *
 * This function releases a previously reserved dynamic memory block back
 * to the system heap using a standard cleanup wrapper.
 *
 * @param src Pointer to the dynamically allocated memory block to free
 *
 * @return Void
 */
void free_words(uint32_t * src);

#endif /* __MEMORY_H__ */
