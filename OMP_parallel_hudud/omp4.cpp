// 2)Har bir kishi OpenMP kutubxonasidan foydalanib o'z ismini  jurnalda nechanchi 
// nomerda bo'lsa shuncha oqim orqali ekranga chiqarsin. 
#include <iostream>
#include <omp.h>
using namespace std;
 


int main()
{
    #pragma omp parallel  num_threads(25)   
        printf("\nNurgeldi");
    
    return 0;
}

// Output : 
// Nurgeldi
// Nurgeldi
// Nurgeldi
// Nurgeldi
// Nurgeldi
// Nurgeldi
// Nurgeldi
// Nurgeldi
// Nurgeldi
// Nurgeldi
// Nurgeldi
// Nurgeldi
// Nurgeldi
// Nurgeldi
// Nurgeldi
// Nurgeldi
// Nurgeldi
// Nurgeldi
// Nurgeldi
// Nurgeldi
// Nurgeldi
// Nurgeldi
// Nurgeldi
// Nurgeldi
// Nurgeldi