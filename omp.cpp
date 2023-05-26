#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
  
int n;
#pragma omp threadprivate(n)
    
int main()
{
    // //omp_set_num_threads(10);// oqimlar sonini belgilash - agar keyingi paralel sohalarda oqim //sonini kiritmasak u holda oqim sonini shu funksiyadan oladi yani 10 ta oqim ishga tushiriladi
    // double start_time, end_time, total_time;
    // start_time = omp_get_wtime(); // vaqtni o'lchash funksiyasi
    // #pragma omp parallel //num_threads(3) // agar son quyilmasa (num_threads(3)
    // ////olib tashlansa) oqimlar soni logik protsessorlar soniga teng bo'ladi
    // {
    //    printf("\nOqim raqami : %d\tOqimlar umumiy soni : %d", omp_get_thread_num(), omp_get_num_threads());
    //     //omp_get_thread_num() funksiyasi oqim  raqamini olish uchun ishlatiladi
    //     //omp_get_num_threads() funksiyasi oqimlar umumiy sonini olish uchun ishlatiladi
    //    printf("\nSalom parallel");
    // }
    // end_time=omp_get_wtime();
    // total_time=end_time-start_time;
    // printf("\nTotal time : %f", total_time);
    // printf("\nSALOM");
    

    ////  private optsiyasi

    // int n=1;
    // printf("n ketma-ket sohada (boshlash): %d\n", n);
    // #pragma omp parallel private(n)
    // {
    //     printf("Oqimdagi n ning qiymati (kirishda): %d\n", n);
    //     // n oʻzgaruvchisini joriy oqim raqamiga belgilang 
    //     n=omp_get_thread_num();
    //     printf("Har bir oqim uchun n qiymati (chiqish):%d\n", n);
    // }
    //     printf("n ketma-ket sohada (oxiri): %d\n", n);

    // // output : 
    // // n ketma-ket sohada (boshlash): 1
    // // Oqimdagi n ning qiymati (kirishda): 0
    // // Har bir oqim uchun n qiymati (chiqish):6
    // // Oqimdagi n ning qiymati (kirishda): 0
    // // Har bir oqim uchun n qiymati (chiqish):1
    // // Oqimdagi n ning qiymati (kirishda): 0
    // // Har bir oqim uchun n qiymati (chiqish):4
    // // Oqimdagi n ning qiymati (kirishda): 0
    // // Har bir oqim uchun n qiymati (chiqish):5
    // // Oqimdagi n ning qiymati (kirishda): 0
    // // Har bir oqim uchun n qiymati (chiqish):3
    // // Oqimdagi n ning qiymati (kirishda): 0
    // // Har bir oqim uchun n qiymati (chiqish):2
    // // Oqimdagi n ning qiymati (kirishda): 32544
    // // Har bir oqim uchun n qiymati (chiqish):0
    // // Oqimdagi n ning qiymati (kirishda): 0
    // // Har bir oqim uchun n qiymati (chiqish):7
    // // n ketma-ket sohada (oxiri): 1

    // //// Shared optsiyasi
    // int i, m[10];
    // printf("m massivi boshida: \n");
    // /// * m massivni nol bilan toʻldiring va chop eting * /
    // for (i=0; i<10; i++){
    //     m[i]=0;
    //     printf("%d : %d\n",i, m[i]);
    // }
    // #pragma omp parallel shared(m)
    // {
    // // m massivning 1 elementini tayinlang, ularning soni joriy oqimning
    // // soniga toʻgʻri keladi 
    // m[omp_get_thread_num()]=1;
    // }
    // //  Massivni yana chop qilaylik
    // printf("Oxirida m massivi:\n");
    // for (i=0; i<10; i++) printf("%d : %d\n",i, m[i]);
    // // output : 
    // // m massivi boshida: 
    // // 0 : 0
    // // 1 : 0
    // // 2 : 0
    // // 3 : 0
    // // 4 : 0
    // // 5 : 0
    // // 6 : 0
    // // 7 : 0
    // // 8 : 0
    // // 9 : 0
    // // Oxirida m massivi:
    // // 0 : 1
    // // 1 : 1
    // // 2 : 1
    // // 3 : 1
    // // 4 : 1
    // // 5 : 1
    // // 6 : 1
    // // 7 : 1
    // // 8 : 0
    // // 9 : 0

    // // firstprivate optsiyasi
    // int n=10;
    // printf("Boshidagi n qiymati: %d\n", n);

    // #pragma omp parallel firstprivate(n) num_threads(3)
    // {
    //     printf("Oqimdagi n ning qiymati (kirishda):%d\n", n);
    //     /// * n oʻzgaruvchisini joriy oqim raqamiga belgilang*/
    //     n=omp_get_thread_num();
    //     printf("Har bir oqim uchun n qiymati (chiqish):%d\n", n);
    // }
    // printf("Oxirida n qiymati:%d\n", n);

    // //Output : 
    // Boshidagi n qiymati: 10
    // // Oqimdagi n ning qiymati (kirishda):10
    // // Har bir oqim uchun n qiymati (chiqish):0
    // // Oqimdagi n ning qiymati (kirishda):10
    // // Har bir oqim uchun n qiymati (chiqish):1
    // // Oqimdagi n ning qiymati (kirishda):10
    // // Har bir oqim uchun n qiymati (chiqish):2
    // // Oxirida n qiymati:10

    // threadprivate
    
    // int num;
    // n=1;
    // printf("\nn : (asosiy) %d\n", n);
    // #pragma omp parallel private (num)
    // {
    //     num=omp_get_thread_num();
    //     printf("Oqimdagi n ning qiymati %d (kirish):%d\n ", num, n);
    //     // * n oʻzgaruvchisini joriy oqim raqamiga belgilang * /
    //     n=omp_get_thread_num();
    //     printf("Oqimdagi n ning qiymati %d (tashqari) %d \n ", num, n);
    // }

    // printf("n qiymati (oʻrtada): %d\n",n);
    
    // #pragma omp parallel private (num)
    // {
    //     num=omp_get_thread_num();
    //     printf("%d oqimdagi n qiymati (yana): %d\n", num, n);
    // }
    // // n : (asosiy) 1
    // // Oqimdagi n ning qiymati 0 (kirish):1
    // // Oqimdagi n ning qiymati 0 (tashqari) 0 
    // // Oqimdagi n ning qiymati 2 (kirish):0
    // // Oqimdagi n ning qiymati 6 (kirish):0
    // // Oqimdagi n ning qiymati 4 (kirish):0
    // // Oqimdagi n ning qiymati 3 (kirish):0
    // // Oqimdagi n ning qiymati 5 (kirish):0
    // // Oqimdagi n ning qiymati 5 (tashqari) 5 
    // // Oqimdagi n ning qiymati 7 (kirish):0
    // // Oqimdagi n ning qiymati 7 (tashqari) 7 
    // // Oqimdagi n ning qiymati 2 (tashqari) 2 
    // // Oqimdagi n ning qiymati 6 (tashqari) 6 
    // // Oqimdagi n ning qiymati 4 (tashqari) 4 
    // // Oqimdagi n ning qiymati 3 (tashqari) 3 
    // // Oqimdagi n ning qiymati 1 (kirish):0
    // // Oqimdagi n ning qiymati 1 (tashqari) 1 

    // // n qiymati (oʻrtada): 0

    // // 4 oqimdagi n qiymati (yana): 4
    // // 6 oqimdagi n qiymati (yana): 6
    // // 1 oqimdagi n qiymati (yana): 1
    // // 5 oqimdagi n qiymati (yana): 5
    // // 2 oqimdagi n qiymati (yana): 24 oqimdagi n qiymati (yana): 4
    // // 6 oqimdagi n qiymati (yana): 6
    // // 1 oqimdagi n qiymati (yana): 1
    // // 7 oqimdagi n qiymati (yana): 7
    // // 0 oqimdagi n qiymati (yana): 0
    // // 3 oqimdagi n qiymati (yana): 3

//     //reduction
//     int i;
//     int sum = 0;

//     #pragma omp parallel for reduction(+: sum)
//     for (i = 0; i < 10; i++) {
//         sum += i;
//     }

//    printf("\nSum : %d\n", sum);

//    // Ouput : 
//    // Sum : 45
    return 0;
}

