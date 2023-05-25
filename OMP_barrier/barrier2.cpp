#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


int main(int argc, char* argv[])
{
	
	omp_set_num_threads(4);
    #pragma omp parallel
    {
        printf("Thread %d prints 1\n", omp_get_thread_num());
        #pragma omp barrier
        printf("Thread %d prints 2\n", omp_get_thread_num());
    }
    return 0;
}
// Output :
// Thread 0 prints 1
// Thread 2 prints 1
// Thread 1 prints 1
// Thread 3 prints 1
// Thread 2 prints 2
// Thread 0 prints 2
// Thread 3 prints 2
// Thread 1 prints 2