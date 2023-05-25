// 15) Bir jarayondan 2- jarayonga 2 ta  2-jarayondan 1- jarayonga 1 ta turli tipdagi ma’lumot jo’nating va 
// bu ma’lumotlarni ekranga chop eting.

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
        int idata = 42;
        double ddata = 21.718243;
        float rfdata;

        MPI_Isend(&idata, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &send_request);
        MPI_Isend(&ddata, 1, MPI_DOUBLE, 1, 1, MPI_COMM_WORLD, &send_request);

        MPI_Irecv(&rfdata, 1, MPI_FLOAT, 1, 2, MPI_COMM_WORLD, &recv_request);

        MPI_Wait(&send_request, &status);
        MPI_Wait(&recv_request, &status);

        cout << "Qabul qilingan float data: " << rfdata << endl;
    }

    if (rank == 1) {
        int ridata;
        double rddata;
        float fdata = 152.1522;

        MPI_Irecv(&ridata, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &recv_request);
        MPI_Irecv(&rddata, 1, MPI_DOUBLE, 0, 1, MPI_COMM_WORLD, &recv_request);

        MPI_Isend(&fdata, 1, MPI_FLOAT, 0, 2, MPI_COMM_WORLD, &send_request);

        MPI_Wait(&recv_request, &status);
        MPI_Wait(&send_request, &status);

        cout << "Qabul qilingan int data: " << ridata << endl;
        cout << "Qabul qilingan double data: " << rddata << endl;
    }

    MPI_Finalize();
    return 0;
}

// Output : 
// Qabul qilingan float data: 152.152
// Qabul qilingan int data: 42
// Qabul qilingan double data: 21.7182