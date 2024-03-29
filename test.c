#include <stdlib.h>
#include <stdio.h>

#include "bit_array.h"

int main(int argc, char *argv[])
{
    ulong i, m, N, total;
    N = atol(argv[1]);

    bit_array* B = new_bit_array(N);

    set_all(B);
    zero_bit(B, 0);
    zero_bit(B, 1);

    for (i = 2; i*i < N; i++) {
        if (is_set(B, i)) {
            for (m = i*i; m < N; m += i) {
                zero_bit(B, m);
            }
        }
    }

    total = 0;
    for (i = 0; i < N; i++) {
        if (is_set(B, i)) {
            total++;
        }
    }

    printf("total: %d\n", total);

    free_bit_array(B);

    return 1;
}
