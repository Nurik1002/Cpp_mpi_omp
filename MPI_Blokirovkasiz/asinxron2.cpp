// 6) Bir jarayondan 2- jarayonga 2 ta MPI_FLOAT tipidagi ma’lumot
//  jo’nating va bu ma’lumotlarni ekranga chop eting.

#include <mpi.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv){
    int rank;
    MPI_Status status;
    MPI_Request send_request, recv_request;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        float yubor[2] = {3.14f, 2.718f};

        MPI_Isend(yubor, 2, MPI_FLOAT, 1, 0, MPI_COMM_WORLD, &send_request);
        MPI_Wait( &send_request , &status);
    }

    if (rank == 1) {
        float qabul[2];

        MPI_Irecv(qabul, 2, MPI_FLOAT, 0, 0, MPI_COMM_WORLD, &recv_request);
        MPI_Wait( &recv_request , &status);

        cout << "Qabul qilingan sonlar: " << qabul[0] << ", " << qabul[1] << endl;
    }

    MPI_Finalize();
    return 0;
}

// Output : 
// Qabul qilingan sonlar: 3.14, 2.718