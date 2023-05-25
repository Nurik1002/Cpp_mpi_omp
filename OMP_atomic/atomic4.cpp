#include <omp.h>
#include <stdio.h>

int main() {
    // Misol 1: 
    int total = 0;
    #pragma omp parallel for
    for (int i = 0; i < 10; ++i) {
        int partial = i * 2;
        #pragma omp atomic
        total += partial;
    }
    printf("Jami : %d\n", total);
return 0;
}
// Output :
// Jami : 90