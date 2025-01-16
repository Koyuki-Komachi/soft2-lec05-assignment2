#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct {
    long m[2][2];
} Matrix2x2;

Matrix2x2 matrix_multipy(Matrix2x2 a, Matrix2x2 b) {
    Matrix2x2 result = {{{0, 0}, {0, 0}}};
    for (int i = 0; i < 2; ++i){
        for (int j = 0; j < 2; ++j){
            for (int k = 0; k < 2; ++k){
                result.m[i][j] += a.m[i][k] * b.m[k][j];
            }
        }
    }
    return result;
}

Matrix2x2 matrix_power(Matrix2x2 m, int n) {
    if (n == 0) {
        Matrix2x2 identity = {{{1, 0}, {0, 1}}};
        return identity;
    }
    if (n == 1) {
        return m;
    }

    Matrix2x2 half = matrix_power(m, n/2);

    if (n % 2 == 0) {
        return matrix_multipy(half, half);
    } else {
        return matrix_multipy(m, matrix_multipy(half, half));
    }
}

long fibo(int n) {
    assert(n <= 90);

    if (n == 0) return 0;
    if (n == 1) return 1;

    Matrix2x2 base = {{{1, 1}, {1, 0}}};

    Matrix2x2 result = matrix_power(base, n-1);

    return result.m[0][0];
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s n\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n < 0) {
        printf("Please enter a non-negative number\n");
        return 1;
    }

    printf("%ld\n", fibo(n));
}
