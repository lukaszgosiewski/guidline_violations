/* processor.h - Data processing function declarations */
#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <stddef.h>

/* Process the provided data */
void process_data(char* data);

/* Calculate the size needed for processing */
int calculate_size(char* data);

/* Analyze the provided data */
void analyze_data(const char* data, size_t len);

#endif /* PROCESSOR_H */
