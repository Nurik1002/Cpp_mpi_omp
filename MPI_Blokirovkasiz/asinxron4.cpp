// 8) Bir jarayondan 2- jarayonga 2 ta  ma’lumot 
// (MPI_INT va MPI_FLOAT tipidagi ) jo’nating va bu ma’lumotlarni ekranga chop eting.

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
        int intdata[2] = {10, 20};
        float floatdata[2] = {3.14f, 2.718f};

        MPI_Isend(intdata, 2, MPI_INT, 1, 0, MPI_COMM_WORLD, &send_request);
        MPI_Isend(floatdata, 2, MPI_FLOAT, 1, 1, MPI_COMM_WORLD, &send_request);
        MPI_Wait( &send_request , &status);
    }

    if (rank == 1) {
        int rintdata[2];
        float rfloatdata[2];

        MPI_Irecv(rintdata, 2, MPI_INT, 0, 0, MPI_COMM_WORLD, &recv_request);
        MPI_Irecv(rfloatdata, 2, MPI_FLOAT, 0, 1, MPI_COMM_WORLD, &recv_request);
        MPI_Wait( &recv_request , &status);

        cout << "Qabul qilingan integer data: " << rintdata[0] << ", " << rintdata[1] << endl;
        cout << "Qabul qilingan  float data: " << rfloatdata[0] << ", " << rfloatdata[1] << endl;
    }

    MPI_Finalize();
    return 0;
}

// Output : 
// Qabul qilingan integer data: 10, 20
// Qabul qilingan  float data: 3.14, 2.718