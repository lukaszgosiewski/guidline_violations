/* utils.c - Utility functions */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

/* Global variable for configuration */
static char config_path[256];

/* CERT-C Violation 1: DCL30-C - Declare objects with appropriate storage durations
   Using static variable when it should be stack-based */
static int counter = 0;

/* CERT-C Violation 2: MEM30-C - Do not access freed memory
   Accessing memory after it's been freed */
void cleanup_resources(char* resource) {
    if (resource != NULL) {
        free(resource);
        /* Violation: Accessing freed memory */
        printf("Resource name: %s\n", resource);
    }
}

void initialize() {
    printf("Initializing utilities...\n");
    strcpy(config_path, "/etc/app/config.conf");
    
    printf("Configuration path: %s\n", config_path);
    counter = 0;
}

void cleanup() {
    printf("Cleaning up utilities...\n");
    printf("Processed %d items\n", counter);
    
    /* Clean up resources */
    char* temp = malloc(100);
    strcpy(temp, "Temporary resource");
    cleanup_resources(temp);
}

int get_count() {
    return counter;
}

void increment_count() {
    counter++;
}
