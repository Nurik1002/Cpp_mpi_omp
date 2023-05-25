#include <omp.h>
#include <stdio.h>

int main() {
    int a=0, b=0;
    #pragma omp parallel num_threads(4)
    {
        #pragma omp single
        a++;
        #pragma omp critical
        b++;
    }
    printf("single: %d -- critical: %d\n", a, b);
    return 0;
}
// Output : 
// single: 1 -- critical: 4