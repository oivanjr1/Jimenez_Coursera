/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief Statistical analysis program for an unsigned char data array
 *
 * This file contains a simple C program that prints an array, calculates
 * basic statistics, and sorts the array from largest to smallest.
 *
 * @author Oscar Ivan Jimenez Rodriguez
 * @date September 2026
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)



int main(void) {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
     print_array(test, SIZE);
    print_statistics(test, SIZE);
    sort_array(test, SIZE);
    print_array(test, SIZE);

    return 0;
}

void print_statistics(unsigned char *data, unsigned int size) {
    printf("\nStatistics:\n");
    printf("Minimum: %d\n", find_minimum(data, size));
    printf("Maximum: %d\n", find_maximum(data, size));
    printf("Mean: %d\n", find_mean(data, size));
    printf("Median: %d\n", find_median(data, size));
}

void print_array(unsigned char *data, unsigned int size) {
    unsigned int i;

    printf("\nArray:\n");

    for (i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }

    printf("\n");
}

unsigned char find_median(unsigned char *data, unsigned int size) {
    sort_array(data, size);

    if (size % 2 == 0) {
        return (data[(size / 2) - 1] + data[size / 2]) / 2;
    } else {
        return data[size / 2];
    }
}

unsigned char find_mean(unsigned char *data, unsigned int size) {
    unsigned int i;
    unsigned int sum = 0;

    for (i = 0; i < size; i++) {
        sum += data[i];
    }

    return sum / size;
}

unsigned char find_maximum(unsigned char *data, unsigned int size) {
    unsigned int i;
    unsigned char max = data[0];

    for (i = 1; i < size; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }

    return max;
}

unsigned char find_minimum(unsigned char *data, unsigned int size) {
    unsigned int i;
    unsigned char min = data[0];

    for (i = 1; i < size; i++) {
        if (data[i] < min) {
            min = data[i];
        }
    }

    return min;
}

void sort_array(unsigned char *data, unsigned int size) {
    unsigned int i, j;
    unsigned char temp;

    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (data[i] < data[j]) {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
  }


