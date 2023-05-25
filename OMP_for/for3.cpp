#include <omp.h>
#include <stdio.h>

int main() {
    #pragma omp parallel
    #pragma omp for nowait
    for (int i = 0; i < 10; ++i) {
        printf("\n i : %d", i);
    }
    return 0;
}
// Output:
//  i : 0
//  i : 1
//  i : 6
//  i : 9
//  i : 2
//  i : 3
//  i : 5
//  i : 7
//  i : 8
//  i : 4