#include <stdio.h>
#include <omp.h>
using namespace std;

int main()
{
   omp_set_num_threads(3);
   #pragma omp parallel for schedule(dynamic,3)
   for(int i=0; i<22; i++)
   {
       printf("\n%d  - oqim  %d - iteratsiya. ",omp_get_thread_num() , i);
   }
   return 0;
}

// Output :
// 0  - oqim  0 - iteratsiya. 
// 0  - oqim  1 - iteratsiya. 
// 0  - oqim  2 - iteratsiya. 
// 0  - oqim  9 - iteratsiya. 
// 0  - oqim  10 - iteratsiya. 
// 0  - oqim  11 - iteratsiya. 
// 1  - oqim  3 - iteratsiya. 
// 1  - oqim  4 - iteratsiya. 
// 1  - oqim  5 - iteratsiya. 
// 0  - oqim  12 - iteratsiya. 
// 0  - oqim  13 - iteratsiya. 
// 0  - oqim  14 - iteratsiya. 
// 0  - oqim  18 - iteratsiya. 
// 0  - oqim  19 - iteratsiya. 
// 0  - oqim  20 - iteratsiya. 
// 0  - oqim  21 - iteratsiya. 
// 1  - oqim  15 - iteratsiya. 
// 1  - oqim  16 - iteratsiya. 
// 1  - oqim  17 - iteratsiya. 
// 2  - oqim  6 - iteratsiya. 
// 2  - oqim  7 - iteratsiya. 
// 2  - oqim  8 - iteratsiya