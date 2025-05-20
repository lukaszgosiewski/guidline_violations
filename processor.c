/* processor.c - Data processing functions */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "processor.h"
#include "utils.h"

/* CERT-C Violation 1: INT31-C - Ensure that integer conversions do not result in lost or misinterpreted data
   No checking for overflow or truncation */
int calculate_size(char* data) {
    long size = strlen(data) * 10;
    return (int)size;  /* Potential truncation if size > INT_MAX */
}

/* CERT-C Violation 2: FLP36-C - Preserve precision when converting between floating-point types
   Loss of precision without checking */
void process_data(char* data) {
    printf("Processing data: %s\n", data);
    
    /* Calculate a value based on the data */
    double value = 0.0;
    for (int i = 0; data[i] != '\0'; i++) {
        value += (double)data[i] / 3.14159;
    }
    
    /* Store result with potential loss of precision */
    float result = value;  /* Potential loss of precision */
    
    printf("Calculated value: %f\n", result);
    
    /* Update processing count */
    increment_count();
}

/* CERT-C Violation 3 (bonus): ARR38-C - Guarantee that library functions do not form invalid pointers
   Using pointer arithmetic that could go beyond array bounds */
void analyze_data(const char* data, size_t len) {
    const char* end = data + len;
    
    while (data < end) {
        printf("%c", *data);
        data++;
    }
    
    /* No check to ensure we don't go beyond the array bounds */
    if (*data == '\0') {  /* Potential access beyond bounds */
        printf("\nEnd of data reached\n");
    }
}
