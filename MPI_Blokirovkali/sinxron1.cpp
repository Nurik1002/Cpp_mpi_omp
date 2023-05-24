//   Xabar jo'natish
// int MPI_Send(void* buf, int count, MPI_Datatype datatype, int dest, int msgtag, MPI_Comm comm)
// buf – xabar yuborish buferining bosh manzili;
// count - xabardagi uzatiladigan elementlar soni;
// datatype - uzatilgan elementlarning turi;
// dest - qabul qilish jarayonining raqami;
// msgtag - xabar identifikatori;
// comm - bu guruh identifikatori.

//   Xabarni qabul qilish
// int MPI_Recv(void* buf, int count, MPI_Datatype datatype, int source, int msgtag, MPI_Comm comm, MPI_Status*status)
// OUT buf – xabarni qabul qiluvchi bufer  manzili;
// count - qabul qilingan xabardagi elementlarning maksimal soni;
// datatype- qabul qilingan xabar elementlarining turi;
// source - jo'natuvchi jarayonning raqami;
// msgtag - qabul qilingan xabarning identifikatori;
// OUT status – qabul qilingan xabar parametrlari.

#include <mpi.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv){
    int rank;
    float a, b;
    MPI_Status status;

    MPI_Init(&argc , &argv);

    MPI_Comm_rank( MPI_COMM_WORLD , &rank);
    a = 0.0;
    b = 0.0;
  
   
   // MPI_Send() funktsiyasi bilan b ni 1-chi rankga jo'natadi.
   // MPI_Recv() bilan esa a ni 1-chi rankdan olish uchun kutiladi.
    if (rank == 0){
        b = 1.0;
        MPI_Send(&b , 1, MPI_INT , 1 , 5 , MPI_COMM_WORLD);
        MPI_Recv( &a , 1 , MPI_INT , 1 , 5 ,MPI_COMM_WORLD, &status);
    }


    // MPI_Recv() bilan b ni 0-rankdan olish uchun kutiladi.
    // MPI_Send() bilan esa a ni 0-rankga jo'natadi.
    if (rank == 1){
        a = 2.0;
        MPI_Recv(&b , 1 , MPI_INT , 0 , 5 ,MPI_COMM_WORLD, &status);
        MPI_Send(&a , 1 , MPI_INT , 0 , 5 , MPI_COMM_WORLD);        
    }

    cout << "\nprocess : " << rank << " a = " << a << " b = " << b;
    MPI_Finalize();
    return 0;
}

// Output : 
// process : 1 a = 2 b = 1
// process : 2 a = 0 b = 0
// process : 0 a = 2 b = 1