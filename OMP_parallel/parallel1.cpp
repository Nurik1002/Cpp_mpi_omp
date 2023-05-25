#include <omp.h>
#include <stdio.h>


int main() {
    int n = 10;
    int data[n];

    // omp parallel
    #pragma omp parallel num_threads(n)
    {
        
        printf("\nJarayaon id : %d", omp_get_thread_num());
    }

    return 0;
}

// Output : 
// Jarayaon id : 0
// Jarayaon id : 1
// Jarayaon id : 3
// Jarayaon id : 4
// Jarayaon id : 2
// Jarayaon id : 6
// Jarayaon id : 8
// Jarayaon id : 7
// Jarayaon id : 5
// Jarayaon id : 9