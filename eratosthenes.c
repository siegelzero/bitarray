#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    unsigned long i, m, N, total;
    N = atol(argv[1]);

    char* B;
    B = (char*) calloc(N, sizeof(char));

    for (i = 2; i < N; i++) {
        B[i] = 1;
    }

    for (i = 2; i*i < N; i++) {
        if (B[i]) {
            for (m = i*i; m < N; m += i) {
                B[m] = 0;
            }
        }
    }

    total = 0;
    for (i = 0; i < N; i++) {
        if (B[i]) {
            total++;
        }
    }

    printf("total: %d\n", total);

    return 1;
}
