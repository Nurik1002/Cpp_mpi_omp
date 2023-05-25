// MPI_Request tipidagi send_request va recv_request o'zgaruvchilari 
// habar almashish jarayonining davomini kuzatish uchun ishlatiladi.

// MPI_Wait funksiyalari habar almashish jarayonining tugaguncha kutish uchun ishlatiladi.

//MPI_Isend funksiyasi yuborish operatsiyasini boshlaydi, lekin yuborish jarayonini 
// tugatganligini kuzatmaydi. Ushbu funksiya quyidagi parametrlarni qabul qiladi:

// buf: Yuboriladigan ma'lumotning ishorasi (buffer).
// count: Yuboriladigan ma'lumotning elementlar soni.
// datatype: Yuboriladigan ma'lumotning turi.
// dest: Qabul qiluvchi protsessning raqami (rank).
// tag: Habar almashish uchun belgilangan tag.
// comm: Kommunikatsiya o'qimining identifikatori (MPI_COMM_WORLD kabi).


// MPI_Irecv funksiyasi esa qabul qilish operatsiyasini boshlaydi, lekin qabul qilish jarayonini 
// tugatganligini kuzatmaydi. Ushbu funksiya quyidagi parametrlarni qabul qiladi:

// buf: Qabul qilingan ma'lumot uchun ishora (buffer).
// count: Qabul qilingan ma'lumotning elementlar soni.
// datatype: Qabul qilingan ma'lumotning turi.
// source: Yuboruvchi protsessning raqami (rank).
// tag: Habar almashish uchun belgilangan tag.
// comm: Kommunikatsiya o'qimining identifikatori (MPI_COMM_WORLD kabi).

// send_request va recv_request o'zgaruvchilar MPI_Request tipida bo'lgan obyektlardir. 
//Ular asinxronlik (non-blocking) habar almashish operatsiyalarini boshlash va tugatish 
// jarayonlarini kuzatish uchun ishlatiladi.
#include <mpi.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv){
    int rank;
    float a, b;
    MPI_Status status;
    MPI_Request send_request, recv_request;

    MPI_Init(&argc , &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    a = 0.0;
    b = 0.0;
  
    if (rank == 0) {
        b = 1.0;
        MPI_Isend(&b, 1, MPI_FLOAT, 1, 5, MPI_COMM_WORLD, &send_request);
        MPI_Irecv(&a, 1, MPI_FLOAT, 1, 5, MPI_COMM_WORLD, &recv_request);

        
        MPI_Wait(&send_request, &status);
        MPI_Wait(&recv_request, &status);
    }

    if (rank == 1) {
        a = 2.0;
        MPI_Irecv(&b, 1, MPI_FLOAT, 0, 5, MPI_COMM_WORLD, &recv_request);
        MPI_Isend(&a, 1, MPI_FLOAT, 0, 5, MPI_COMM_WORLD, &send_request);

       
        MPI_Wait(&recv_request, &status);
        MPI_Wait(&send_request, &status);
    }

    cout << "\nprocess: " << rank << " a = " << a << " b = " << b;

    MPI_Finalize();
    return 0;
}


// Output : 
// process: 0 a = 2 b = 1
// process: 2 a = 0 b = 0
// process: 1 a = 2 b = 1