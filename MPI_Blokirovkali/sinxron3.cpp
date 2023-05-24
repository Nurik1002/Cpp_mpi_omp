// 7) Bir jarayondan 2- jarayonga 2 ta MPI_DOUBLE tipidagi ma’lumot jo’nating
// va bu ma’lumotlarni ekranga chop eting.

#include <mpi.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv){
    int rank;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        double data[2] = {3.14159, 2.71828};

        MPI_Send(data, 2, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD);
    }

    if (rank == 1) {
        double rdata[2];

        MPI_Recv(rdata, 2, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, &status);

        cout << "Qabul qilingan sonlar: " << rdata[0] << ", " << rdata[1] << endl;
    }

    MPI_Finalize();
    return 0;
}

// Output : 
// Qabul qilingan sonlar: 3.14159, 2.71828