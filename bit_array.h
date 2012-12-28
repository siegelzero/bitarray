#include <stdlib.h>
#include <inttypes.h>

#ifndef BIT_ARRAY_H
#define BIT_ARRAY_H

// This will make things a little cleaner.
#define ulong unsigned long

// Number of bits in an unsigned long.
#define WORD_SIZE (sizeof(ulong)*8)
#define ONE ((ulong)0x1)

typedef struct bit_array bit_array;

// Create or destroy a bit_array
bit_array* new_bit_array(ulong N);
void free_bit_array(bit_array* B);

ulong num_bits(bit_array* B);

// Manipulate a bit_array
void set_bit(bit_array* B, ulong idx);
void zero_bit(bit_array *B, ulong idx);
void switch_bit(bit_array* B, ulong idx);
char is_set(bit_array *B, ulong idx);

void set_all(bit_array* B);
void zero_all(bit_array* B);

#endif
