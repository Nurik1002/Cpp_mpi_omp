// 10)  Bir jarayondan 2- jarayonga 2 ta  ma’lumot (MPI_DOUBLE va MPI_INT tipidagi ) 
// jo’nating va bu ma’lumotlarni ekranga chop eting.

#include <mpi.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv){
    int rank;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        double doubledata[2] = {5.3443, 2.435345};
        int intdata[2] = {10, 20};

        MPI_Send(doubledata, 2, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD);
        MPI_Send(intdata, 2, MPI_INT, 1, 1, MPI_COMM_WORLD);
    }

    if (rank == 1) {
        double rdoubledata[2];
        int rintdata[2];

        MPI_Recv(rdoubledata, 2, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, &status);
        MPI_Recv(rintdata, 2, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);

        cout << "Qabul qilingan double data: " << rdoubledata[0] << ", " << rdoubledata[1] << endl;
        cout << "Qabul qilingan int data: " << rintdata[0] << ", " << rintdata[1] << endl;
    }

    MPI_Finalize();
    return 0;
}

// Output : 
// Qabul qilingan double data: 5.3443, 2.43534
// Qabul qilingan int data: 10, 20
