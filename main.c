/* main.c - Entry point for our program */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "processor.h"

/* CERT-C Violation 1: ERR33-C - Detect and handle errors
   No error checking after malloc */
void process_input(const char* input) {
    char* buffer = (char*)malloc(strlen(input) + 1);
    strcpy(buffer, input);
    
    /* Process the data */
    process_data(buffer);
    
    free(buffer);
}

/* CERT-C Violation 2: STR31-C - Guarantee that storage for strings has sufficient space
   Using fixed-size buffer without checking input length */
void display_message(const char* message) {
    char buffer[50];
    strcpy(buffer, message);  /* No bounds checking */
    printf("Message: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    printf("Starting application...\n");
    
    /* Initialize utility functions */
    initialize();
    
    /* Process some data */
    if (argc > 1) {
        process_input(argv[1]);
        display_message(argv[1]);
    } else {
        printf("No input provided\n");
    }
    
    /* Clean up */
    cleanup();
    
    printf("Application completed successfully\n");
    return 0;
}
