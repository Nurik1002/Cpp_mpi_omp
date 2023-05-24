// 14)  Bir jarayondan 2- jarayonga 3 ta  teg orqali turli xil tipdagi  3ta malumot jo’nating va 
// bu ma’lumotlarni ekranga chop eting.

#include <mpi.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    int rank;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        int idata[3] = {10, 20, 30};
        float fdata[3] = {13.324, 21.127218, 15.18};
        double ddata[3] = {31.159, 18.828, 11.421};

        MPI_Send(idata, 3, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Send(fdata, 3, MPI_FLOAT, 1, 1, MPI_COMM_WORLD);
        MPI_Send(ddata, 3, MPI_DOUBLE, 1, 2, MPI_COMM_WORLD);
    }

    if (rank == 1) {
        int ridata[3];
        float rfdata[3];
        double rddata[3];

        MPI_Recv(ridata, 3, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        MPI_Recv(rfdata, 3, MPI_FLOAT, 0, 1, MPI_COMM_WORLD, &status);
        MPI_Recv(rddata, 3, MPI_DOUBLE, 0, 2, MPI_COMM_WORLD, &status);

        cout << "Qabul qilingan int data: " << ridata[0] << ", " << ridata[1] << ", " << ridata[2] << endl;
        cout << "Qabul qilingan float data: " << rfdata[0] << ", " << rfdata[1] << ", " << rfdata[2] << endl;
        cout << "Qabul qilingan double data: " << rddata[0] << ", " << rddata[1] << ", " << rddata[2] << endl;
    }

    MPI_Finalize();
    return 0;
}

// Output : 
// Qabul qilingan int data: 10, 20, 30
// Qabul qilingan float data: 13.324, 21.1272, 15.18
// Qabul qilingan double data: 31.159, 18.828, 11.421