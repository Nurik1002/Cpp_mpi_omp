#include <omp.h>
#include <stdio.h>

int main() {
    // Misol 1: 
    int count = 0;
    #pragma omp parallel for
    for (int i = 0; i < 10; ++i) {
        #pragma omp atomic
        count++;
    }
    printf("Sanagich: %d\n", count);
return 0;
}
// Output :
// Sanagich: 10