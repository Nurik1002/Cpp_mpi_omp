//13)  Bir jarayondan 2- jarayonga 2 ta  teg orqali turli xil tipdagi  (MPI_FLOAT va MPI_DOUBLE)  
// malumot jo’nating va bu ma’lumotlarni ekranga chop eting.
#include <mpi.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    int rank;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        float fdata[2] = {5.23424, 12.3242};
        double ddata[2] = {7.14773159, 21.7182438};

        MPI_Send(fdata, 2, MPI_FLOAT, 1, 0, MPI_COMM_WORLD);
        MPI_Send(ddata, 2, MPI_DOUBLE, 1, 1, MPI_COMM_WORLD);
    }

    if (rank == 1) {
        float rfdata[2];
        double rddata[2];

        MPI_Recv(rfdata, 2, MPI_FLOAT, 0, 0, MPI_COMM_WORLD, &status);
        MPI_Recv(rddata, 2, MPI_DOUBLE, 0, 1, MPI_COMM_WORLD, &status);

        cout << "Qabul qilingan float data: " << rfdata[0] << ", " << rfdata[1] << endl;
        cout << "Qabul qilingan double data: " << rddata[0] << ", " << rddata[1] << endl;
    }

    MPI_Finalize();
    return 0;
}
// Output : 
// Qabul qilingan float data: 5.23424, 12.3242
// Qabul qilingan double data: 7.14773, 21.7182