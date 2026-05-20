/******************************************************************************
 * Copyright (C) 2026 by Kerellos Emad
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright.
 *
 *****************************************************************************/
/**
 * @file main.c
 * @brief Main entry point for the application
 *
 * This file contains the main execution loop. It utilizes a compile-time 
 * conditional switch (-DCOURSE1) to trigger the automated test suite 
 * defined in course1.c.
 *
 * @author Kerellos Emad
 * @date May 2026
 *
 */

#include <stdint.h>
#include <stdlib.h>
#include "course1.h"

int main(void) {
    
    /* 
     * Compile-time switch requirement:
     * Wrapping the course deliverable call within an #ifdef block.
     * This allows us to toggle the test execution on or off using the 
     * -DCOURSE1 flag during the compilation process.
     */
#ifdef COURSE1
    course1();
#endif

    return 0;
}
