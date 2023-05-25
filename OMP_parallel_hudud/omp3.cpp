//1)Har bir kishi OpenMP kutubxonasidan foydalanib o'z ismini logic 
// protsessorlar soni nechta bo'lsa shuncha marotaba ekranga chiqarsin ( oqimlar sonini kiritmagan holda).
#include <iostream>
#include <omp.h>
using namespace std;
 


int main()
{
    #pragma omp parallel     
        cout << "\nNurgeldi";
    
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