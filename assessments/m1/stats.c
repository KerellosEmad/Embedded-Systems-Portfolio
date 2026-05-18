#include <stdio.h>
#include "stats.h"

static unsigned char find_max(const unsigned char *array, unsigned int length) {
    unsigned char max = array[0];

    for (unsigned int i = 1; i < length; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

static unsigned char find_min(const unsigned char *array, unsigned int length) {
    unsigned char min = array[0];

    for (unsigned int i = 1; i < length; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

void print_statistics(const unsigned char *array, unsigned int length) {
    printf("Minimum: %u\n", find_minimum(array, length));
    printf("Maximum: %u\n", find_maximum(array, length));
    printf("Mean: %u\n", find_mean(array, length));
    printf("Median: %u\n", find_median(array, length));
}

void print_array(const unsigned char *array, unsigned int length) {
    for (unsigned int i = 0; i < length; i++) {
        printf("%u ", array[i]);
    }
    printf("\n");
}

void sort_array(unsigned char *array, unsigned int length) {
    for (unsigned int i = 0; i < length - 1; i++) {
        for (unsigned int j = i + 1; j < length; j++) {
            if (array[i] < array[j]) {
                unsigned char temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

/* FIXED: uses COPY so original array is NOT modified */
unsigned char find_median(const unsigned char *array, unsigned int length) {
    unsigned char temp[40];

    for (unsigned int i = 0; i < length; i++) {
        temp[i] = array[i];
    }

    sort_array(temp, length);

    if (length % 2 == 0) {
        return (temp[length/2] + temp[(length/2) - 1]) / 2;
    } else {
        return temp[length/2];
    }
}

/* FIXED mean calculation */
unsigned char find_mean(const unsigned char *array, unsigned int length) {
    unsigned int sum = 0;

    for (unsigned int i = 0; i < length; i++) {
        sum += array[i];
    }

    return (unsigned char)(sum / length);
}

/* FIXED max */
unsigned char find_maximum(const unsigned char *array, unsigned int length) {
    return find_max(array, length);
}

/* FIXED min */
unsigned char find_minimum(const unsigned char *array, unsigned int length) {
    return find_min(array, length);
}

int main() {
    unsigned char test[40] = {
        34, 201, 190, 154, 8, 194, 2, 6,
        114, 88, 45, 76, 123, 87, 25, 23,
        200, 122, 150, 90, 21, 34, 17, 50,
        12, 77, 150, 200, 3, 9, 40, 60,
        80, 99, 100, 120, 130, 140, 10, 5
    };

    unsigned int length = 40;

    printf("Original array:\n");
    print_array(test, length);

    sort_array(test, length);

    printf("\nSorted array (descending):\n");
    print_array(test, length);

    printf("\nStatistics:\n");
    print_statistics(test, length);

    return 0;
}
