#include <stdlib.h>
#include <stdio.h>
#include "bit_array.h"

ulong integer_sqrt(ulong n);

int main(int argc, char *argv[])
{
    ulong N, D, i, j, m, count, total;

    if (argc < 1) {
        return 0;
    }
    else {
        N = atol(argv[1]);
    }

    D = integer_sqrt(N);
    bit_array* b_list = new_bit_array(D);

    set_all(b_list);
    zero_bit(b_list, 0);
    zero_bit(b_list, 1);

    for (i = 2; i*i < D; i++) {
        if (is_set(b_list, i)) {
            for (m = i*i; m < D; m += i) {
                zero_bit(b_list, m);
            }
        }
    }

    count = 0;
    for (i = 2; i < D; i++) {
        if (is_set(b_list, i)) {
            count++;
        }
    }

    ulong* p_list;
    ulong* p_squares;

    p_list = (ulong*) calloc(count, sizeof(ulong));
    p_squares = (ulong*) calloc(count, sizeof(ulong));

    j = 0;
    for (i = 2; i < D; i++) {
        if (is_set(b_list, i)) {
            p_list[j] = i;
            p_squares[j] = i*i;
            j++;
        }
    }

    // We'll reuse b_list now to sieve each interval.
    total = 0;
    for (m = 0; m < N; m += D) {
        set_all(b_list);
        for (i = 0; i < count; i++) {
            while (p_squares[i] < D) {
                zero_bit(b_list, p_squares[i]);
                p_squares[i] += p_list[i];
            }
            p_squares[i] -= D;
        }
        for (i = 0; i < D; i++) {
            if (is_set(b_list, i) && 1 < m + i && m + i < N) {
                total++;
            }
        }
    }

    printf("total: %lu\n", total);

    free(p_list);
    free(p_squares);
    free_bit_array(b_list);

    return 1;
}

ulong integer_sqrt(ulong n)
{
    ulong x, y;

    x = n;
    while (1) {
        y = (x + n / x) / 2;
        if (y >= x)
            return x;
        x = y;
    }
}
