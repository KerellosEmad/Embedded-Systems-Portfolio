# Embedded Statistical Analysis Module 

## Overview
This project implements a simple statistical analysis module in C for embedded systems practice. It processes a fixed-size array of unsigned 8-bit integers and computes basic statistics such as minimum, maximum, mean, and median.

The project demonstrates core C programming concepts, including arrays, pointers, functions, modular design, and basic sorting algorithms, with an embedded systems focus (no dynamic memory allocation).

## Features
- Print array elements
- Sort the array in descending order
- Compute statistical values:
  - Minimum
  - Maximum
  - Mean (integer division)
  - Median (using a safe copy of the array)
- Modular design using header and source files
- Embedded-friendly implementation (stack-based memory usage)

## Project Structure
- stats.h  → Function declarations (API)
- stats.c  → Function implementations + test main
- README.md → Project documentation

## How It Works
1. A fixed array of 40 unsigned char values is defined.
2. The array is printed in its original form.
3. The array is sorted in descending order.
4. Statistical functions are applied:
   - Min/Max via scanning
   - Mean via summation
   - Median via sorted copy of the array
5. Results are printed to the console.

## Build & Run
gcc stats.c -o stats
./stats

## Author
Kerellos Emad

## Notes
- Fixed dataset size (40 elements)
- Uses unsigned char for memory efficiency
- No dynamic memory allocation (embedded systems practice)
