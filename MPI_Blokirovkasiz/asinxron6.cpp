// 12)  Bir jarayondan 2- jarayonga 2 ta  teg orqali turli xil tipdagi  
// (MPI_FLOAT va MPI_INT)  malumot jo’nating va bu ma’lumotlarni ekranga chop eting.

#include <mpi.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    int rank;
    MPI_Status status;
    MPI_Request send_request, recv_request;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        float fdata[2] = {3.14f, 2.718f};
        int idata[2] = {10, 20};

        MPI_Isend(fdata, 2, MPI_FLOAT, 1, 0, MPI_COMM_WORLD, &send_request);
        MPI_Isend(idata, 2, MPI_INT, 1, 1, MPI_COMM_WORLD, &send_request);
        MPI_Wait(&send_request, &status);
    }

    if (rank == 1) {
        float rfdata[2];
        int ridata[2];

        MPI_Irecv(rfdata, 2, MPI_FLOAT, 0, 0, MPI_COMM_WORLD, &recv_request);
        MPI_Irecv(ridata, 2, MPI_INT, 0, 1, MPI_COMM_WORLD, &recv_request);
        MPI_Wait(&recv_request, &status);

        cout << "Qabul qilingan float data: " << rfdata[0] << ", " << rfdata[1] << endl;
        cout << "Qabul qilingan int data: " << ridata[0] << ", " << ridata[1] << endl;
    }

    MPI_Finalize();
    return 0;
}

// Output :
// Qabul qilingan float data: 3.14, 2.718
// Qabul qilingan int data: 10, 20