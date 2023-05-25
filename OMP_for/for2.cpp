#include <omp.h>
#include <stdio.h>


int main() {
    int N = 3;
    int matrix[N][N] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};

    #pragma omp parallel for num_threads(4)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] *= 2;
        }
    }

    printf("Matritsaning yangi elemetlari:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// Output :
// Matritsaning yangi elemetlari:
// 2 4 6 
// 8 10 12 
// 14 16 18 