/*
 * expt1_1.c
 * Course: EEE 6744 - Hands-on Hardware Security
 * Date: 08/31/2026
 * Team: Patrick Craig, Shreejaa Udaya Sekar, Sivanesh Murthi
 * Assignment: Experiment - 1 (Buffer Overflow Attack)
 * 
 * Part I: Code and Test Simple Examples
 *
 * Demonstrates:
 *   1. Heap Buffer Overflow
 *   2. Integer Overflow
 *   3. Stack Buffer Overflow
 *
 * Compile:
 *   gcc -w -fno-stack-protector -Wall -pedantic expt1_1.c -o expt1_1
 *
 * Run:
 *   ./expt1_1
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


// 1. HEAP BUFFER OVERFLOW

void heap_overflow_demo(void)
{

    struct heap_data {
        char buffer[8];
        unsigned int marker;
    };

    struct heap_data *data = malloc(sizeof(struct heap_data));

    if (data == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    memset(data->buffer, 0, sizeof(data->buffer));
    data->marker = 0x12345678U;

    printf("\n========== HEAP OVERFLOW ==========\n");
    printf("Memory region     : HEAP\n");
    printf("Structure address : %p\n", (void *)data);
    printf("Buffer address    : %p\n", (void*)data->buffer);
    printf("Marker address    : %p\n", (void*)&data->marker);
  
    printf("Buffer size       : %zu bytes\n", sizeof(data->buffer));
    printf("Data being copied : \"ABCDEFGHIJKL\"\n");
    printf("Characters        : 12\n");
    printf("Bytes Copied      : 13 (12 characters + '\\0')\n");
    printf("Overflow amount   : %d bytes\n", 13 - (int)sizeof(data->buffer));
    printf("Marker before     : 0x%08x\n", data->marker);

    memcpy(data->buffer, "ABCDEFGHIJKL", 13);

    data->buffer[7] = '\0';

    printf("Marker after      : 0x%08x\n", data->marker);
    printf("Heap overflow occured: data was written beyond buffer[8] (13 bytes were written into an 8-byte buffer).\n");

    free(data);
}


// 2. INTEGER OVERFLOW

void integer_overflow_demo(void)
{
    unsigned int value = UINT_MAX;

    printf("\n========== INTEGER OVERFLOW ==========\n");
    printf("Data type            : unsigned int\n");
    printf("Maximum value        : %u\n", UINT_MAX);
    printf("Value before         : %u\n", value);
    printf("Operation            : %u + 1\n", value);

    value = value + 1U;

    printf("Value after       : %u\n", value);
    printf("Integer overflow occured: value wrapped from UINT_MAX to 0 by adding 1.\n");
}

// 3. STACK BUFFER OVERFLOW

void stack_overflow_demo(void)
{
    struct stack_data {
        char buffer[8];
        unsigned int marker;
    };

    struct stack_data data;

    memset(data.buffer, 0, sizeof(data.buffer));
    data.marker = 0x12345678U;

    printf("\n========== STACK OVERFLOW ==========\n");
    printf("Memory region     : STACK\n");
    printf("Structure address : %p\n", (void *)&data);
    printf("Buffer address    : %p\n", (void*)data.buffer);
    printf("Marker address    : %p\n", (void*)&data.marker);

    printf("Buffer size       : %zu bytes\n", sizeof(data.buffer));
    printf("Data being copied : \"ABCDEFGHIJKL\"\n");
    printf("Characters        : 12\n");
    printf("Bytes copied      : 13 (12 characters + '\\0')\n");
    printf("Overflow amount   : %d bytes\n", 13 - (int)sizeof(data.buffer));
    printf("Marker before     : 0x%08x\n", data.marker);

    memcpy(data.buffer, "ABCDEFGHIJKL", 13);

    data.buffer[7] = '\0';

    printf("Marker after      : 0x%08x\n", data.marker);
    printf("Stack overflow occured: data was written beyond buffer[8] (13 bytes were written into an 8-byte buffer).\n");
}

int main(void)
{
    printf("====================================================\n");
    printf("Experiment 1 - Part I\n");
    printf("Buffer Overflow Attack: Simple Examples\n");
    printf("====================================================\n");

    heap_overflow_demo();
    integer_overflow_demo();
    stack_overflow_demo();

    printf("\n====================================================\n");
    printf("All three Part I examples completed.\n");
    printf("====================================================\n");

    return 0;
}
