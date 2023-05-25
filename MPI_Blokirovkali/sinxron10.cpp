// 16) Bir jarayondan 2- jarayonga 2 ta  2-jarayondan 1- jarayonga 3 ta 
// turli tipdagi ma’lumot jo’nating va bu ma’lumotlarni ekranga chop eting.
#include <mpi.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    int rank;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        int idata[3] = {11, 22, 33};
        float fdata[3] = {31.9714f, 97.7918f, 96.618f};
        double ddata[3] = {234.259, 223.18, 656.41421};

        MPI_Send(idata, 3, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Send(fdata, 3, MPI_FLOAT, 1, 1, MPI_COMM_WORLD);
        MPI_Send(ddata, 3, MPI_DOUBLE, 1, 2, MPI_COMM_WORLD);

        int ridata[3];
        float rfdata[3];
        double rddata[3];
        
        MPI_Recv(ridata, 3, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);
        MPI_Recv(rfdata, 3, MPI_FLOAT, 1, 1, MPI_COMM_WORLD, &status);
        MPI_Recv(rddata, 3, MPI_DOUBLE, 1, 2, MPI_COMM_WORLD, &status);

        cout << "Qabul qilingan  int data: ";
        for (int i = 0; i < 3; ++i) {
            cout << ridata[i] << " ";
        }
        cout << endl;

        cout << "Qabul qilingan  float data: ";
        for (int i = 0; i < 3; ++i) {
            cout << rfdata[i] << " ";
        }
        cout << endl;

        cout << "Qabul qilingan  double data: ";
        for (int i = 0; i < 3; ++i) {
            cout << rddata[i] << " ";
        }
        cout << endl;
    }

    if (rank == 1) {
        int ridata[3];
        float rfdata[3];
        double rddata[3];

        MPI_Recv(ridata, 3, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        MPI_Recv(rfdata, 3, MPI_FLOAT, 0, 1, MPI_COMM_WORLD, &status);
        MPI_Recv(rddata, 3, MPI_DOUBLE, 0, 2, MPI_COMM_WORLD, &status);

        cout << "Qabul qilingan  int data: ";
        for (int i = 0; i < 3; ++i) {
            cout << ridata[i] << " ";
        }
        cout << endl;

        cout << "Qabul qilingan  float data: ";
        for (int i = 0; i < 3; ++i) {
            cout << rfdata[i] << " ";
        }
        cout << endl;

        cout << "Qabul qilingan  double data: ";
        for (int i = 0; i < 3; ++i) {
            cout << rddata[i] << " ";
        }
        cout << endl;

        int idata[3] = {205, 25, 3};
        float fdata[3] = {31.1414f, 14.74118f, 15.61418f};
        double ddata[3] = {19.514149, 14.41718, 14.41421};

        MPI_Send(idata, 3, MPI_INT, 0, 0, MPI_COMM_WORLD);
        MPI_Send(fdata, 3, MPI_FLOAT, 0, 1, MPI_COMM_WORLD);
        MPI_Send(ddata, 3, MPI_DOUBLE, 0, 2, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}

// Output :

// Qabul qilingan  int data: 11 22 33 
// Qabul qilingan  float data: 31.9714 97.7918 96.618 
// Qabul qilingan  double data: 234.259 223.18 656.414 

// Qabul qilingan  int data: 205 25 3 
// Qabul qilingan  float data: 31.1414 14.7412 15.6142 
// Qabul qilingan  double data: 19.5141 14.4172 14.4142 