#include <iostream>
#include <omp.h>
using namespace std;
 


int main()
{
    //omp_set_num_threads(10);// oqimlar sonini belgilash - agar keyingi paralel sohalarda oqim 
    //sonini kiritmasak u holda oqim sonini shu funksiyadan oladi yani 10 ta oqim ishga tushiriladi
    double start_time, end_time, total_time;
    start_time = omp_get_wtime(); // vaqtni o'lchash funksiyasi
    #pragma omp parallel //num_threads(3) // agar son quyilmasa (num_threads(3)
    ////olib tashlansa) oqimlar soni logik protsessorlar soniga teng bo'ladi
    {
       cout << "Hello World" <<"  oqim raqami = " <<omp_get_thread_num()<<"  oqimlar umumiy soni = "<< omp_get_num_threads()<<endl;
//omp_get_thread_num() funksiyasi oqim  raqamini olish uchun ishlatiladi
//omp_get_num_threads() funksiyasi oqimlar umumiy sonini olish uchun ishlatiladi
       cout << "salom parallel"<<endl;
    }
    end_time=omp_get_wtime();
    total_time=end_time-start_time;
    cout<<end_time-start_time<<"   "<<total_time<<endl;
    cout << "salom"<<endl;

    return 0;
}

// Output : 
// Hello World  oqim raqami = 0  oqimlar umumiy soni = 8
// salom parallel
// Hello World  oqim raqami = 4  oqimlar umumiy soni = 8
// salom parallel
// Hello World  oqim raqami = 2  oqimlar umumiy soni = 8
// salom parallel
// Hello World  oqim raqami = 5  oqimlar umumiy soni = 8
// salom parallel
// Hello World  oqim raqami = 6  oqimlar umumiy soni = 8
// salom parallel
// Hello World  oqim raqami = 3  oqimlar umumiy soni = 8
// salom parallel
// Hello World  oqim raqami = 1  oqimlar umumiy soni = 8
// salom parallel
// Hello World  oqim raqami = 7  oqimlar umumiy soni = 8
// salom parallel
// 0.028874   0.028874
// salom