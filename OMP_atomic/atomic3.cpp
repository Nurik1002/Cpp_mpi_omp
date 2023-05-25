#include <omp.h>
#include <stdio.h>

int main() {
    // Misol 1: 
    int value = 42;
    #pragma omp parallel
    {
        #pragma omp atomic
        value++;
        printf("Jatayon id %d: %d\n", omp_get_thread_num(), value);
    }
return 0;
}
// Output :
// Jatayon id 2: 43
// Jatayon id 5: 49
// Jatayon id 1: 50
// Jatayon id 7: 45
// Jatayon id 0: 47
// Jatayon id 3: 46
// Jatayon id 6: 48
// Jatayon id 4: 44