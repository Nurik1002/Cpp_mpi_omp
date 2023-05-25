// 7) Bir jarayondan 2- jarayonga 2 ta MPI_DOUBLE tipidagi ma’lumot jo’nating
// va bu ma’lumotlarni ekranga chop eting.

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
        double data[2] = {121.234, 211.128};

        MPI_Isend(data, 2, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD, &send_request);
        MPI_Wait( &send_request , &status);
    }

    if (rank == 1) {
        double rdata[2];

        MPI_Irecv(rdata, 2, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, &recv_request);
        MPI_Wait( &recv_request , &status);

        cout << "Qabul qilingan sonlar: " << rdata[0] << ", " << rdata[1] << endl;
    }

    MPI_Finalize();
    return 0;
}

// Output : 
// Qabul qilingan sonlar: 121.234, 211.128