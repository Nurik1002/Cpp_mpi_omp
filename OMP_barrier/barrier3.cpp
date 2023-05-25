#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


int main(int argc, char* argv[])
{
	#pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        for (int i = 0; i < thread_id; i++) {
            printf("\n%d ", thread_id);
            
        }
        #pragma omp barrier
        #pragma omp single
        printf("\nIsh tugadi.");
    }
    return 0;
}
// Output :
// 1 
// 4 
// 4 
// 4 
// 4 
// 2 
// 2 
// 6 
// 6 
// 6 
// 6 
// 6 
// 6 
// 3 
// 3 
// 3 
// 5 
// 5 
// 5 
// 5 
// 5 
// 7 
// 7 
// 7 
// 7 
// 7 
// 7 
// 7 
// Ish tugadi