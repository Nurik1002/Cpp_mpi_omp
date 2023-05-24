#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
  
int main(int argc, char* argv[])
{
    int nthreads, tid;
  
    #pragma omp parallel private(nthreads, tid)
    {
        // Jarayon raqamini olish
        tid = omp_get_thread_num();
        printf("thread = %d\n",
               tid);
  
        if (tid == 0) {
  
        
            nthreads = omp_get_num_threads();
            printf("Number of threads = %d\n",
                   nthreads);
        }
    }
    return 0;
}

// Output : 
// thread = 0
// thread = 1
// thread = 6
// thread = 7
// thread = 4
// thread = 2
// Number of threads = 8
// thread = 3
// thread = 5