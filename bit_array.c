#include "bit_array.h"

// Struct definition.
typedef struct bit_array {
    ulong nbits;
    ulong nwords;
    ulong* words;
} bit_array;

// Creation and destruction routines.
bit_array* new_bit_array(ulong N)
{
    bit_array* array = malloc(sizeof(bit_array));

    array->nbits = N;
    array->nwords = N / WORD_SIZE + 1;

    ulong cap = 1;
    while (cap < array->nwords) cap <<= 1;

    array->words = (ulong*) calloc(cap, sizeof(ulong));

    return array;
}

// Free the memory used by the bit_array.
void free_bit_array(bit_array* B)
{
    free(B->words);
    free(B);
}

// Returns the capacity of the bit_array.
ulong num_bits(bit_array *B)
{
    return B->nbits;
}

// Check if bit at index idx is set.
char is_set(bit_array *B, ulong idx)
{
    return (B->words[idx / WORD_SIZE] >> (idx % WORD_SIZE)) & ONE;
}

// Set the bit at index idx.
void set_bit(bit_array *B, ulong idx)
{
    B->words[idx / WORD_SIZE] |= (ONE << (idx % WORD_SIZE));
}

// Clear the bit at index idx.
void zero_bit(bit_array *B, ulong idx)
{
    B->words[idx / WORD_SIZE] &= ~(ONE << (idx % WORD_SIZE));
}

// Set all bits in the array.
void set_all(bit_array *B)
{
    ulong i;
    for (i = 0; i < B->nbits; i++) {
        set_bit(B, i);
    }
}

// Clear all bits in the array.
void zero_all(bit_array *B)
{
    ulong i;
    for (i = 0; i < B->nbits; i++) {
        zero_bit(B, i);
    }
}
