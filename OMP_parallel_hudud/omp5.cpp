// 4)1 dan n gacha bo’lgan sonlarni har birini nga ko’paytirib ekarnga 
// chiqaring va bu dasturni nta oqim orqali ishni taqsimlab bajaring .
#include <iostream>
#include <omp.h>
using namespace std;
 
int main()
{
    int n  = 25, nn;
    #pragma omp parallel num_threads(25) 
    {
        printf("\n%d * %d = %d", omp_get_thread_num(), 25, omp_get_thread_num()*25);
    }
    
    return 0;
}

// Output :
// 0 * 25 = 0
// 15 * 25 = 375
// 5 * 25 = 125
// 24 * 25 = 600
// 4 * 25 = 100
// 7 * 25 = 175
// 8 * 25 = 200
// 2 * 25 = 50
// 12 * 25 = 300
// 16 * 25 = 400
// 9 * 25 = 225
// 20 * 25 = 500
// 21 * 25 = 525
// 23 * 25 = 575
// 17 * 25 = 425
// 10 * 25 = 250
// 6 * 25 = 150
// 18 * 25 = 450
// 19 * 25 = 475
// 1 * 25 = 25
// 11 * 25 = 275
// 14 * 25 = 350
// 22 * 25 = 550
// 13 * 25 = 325
// 3 * 25 = 75