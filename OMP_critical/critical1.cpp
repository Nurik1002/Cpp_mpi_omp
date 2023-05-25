#include <omp.h>
#include <stdio.h>

int main() {
    int counter = 0;

    #pragma omp parallel num_threads(4)
    {
        #pragma omp critical
        {
            counter++;
            printf("Jarayon :  %d, counter  : %d\n", omp_get_thread_num(), counter);
        }
    }

    return 0;
}
// Output :
// Jarayon :  1, counter  : 1
// Jarayon :  0, counter  : 2
// Jarayon :  2, counter  : 3
// Jarayon :  3, counter  : 4