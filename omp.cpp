#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
  
int main()
{
    //omp_set_num_threads(10);// oqimlar sonini belgilash - agar keyingi paralel sohalarda oqim //sonini kiritmasak u holda oqim sonini shu funksiyadan oladi yani 10 ta oqim ishga tushiriladi
    double start_time, end_time, total_time;
    start_time = omp_get_wtime(); // vaqtni o'lchash funksiyasi
    #pragma omp parallel //num_threads(3) // agar son quyilmasa (num_threads(3)
    ////olib tashlansa) oqimlar soni logik protsessorlar soniga teng bo'ladi
    {
       printf("\nOqim raqami : %d\tOqimlar umumiy soni : %d", omp_get_thread_num(), omp_get_num_threads());
        //omp_get_thread_num() funksiyasi oqim  raqamini olish uchun ishlatiladi
        //omp_get_num_threads() funksiyasi oqimlar umumiy sonini olish uchun ishlatiladi
       printf("\nSalom parallel");
    }
    end_time=omp_get_wtime();
    total_time=end_time-start_time;
    printf("\nTotal time : %f", total_time);
    printf("\nSALOM");
    return 0;
}

