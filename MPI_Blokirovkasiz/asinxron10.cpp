// 16) Bir jarayondan 2- jarayonga 2 ta  2-jarayondan 1- jarayonga 3 ta 
// turli tipdagi ma’lumot jo’nating va bu ma’lumotlarni ekranga chop eting.
#include <mpi.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    int rank;
    MPI_Status status;
    MPI_Request send_request[6], recv_request[6];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        int idata[3] = {11, 22, 33};
        float fdata[3] = {31.9714f, 97.7918f, 96.618f};
        double ddata[3] = {234.259, 223.18, 656.41421};

        MPI_Isend(idata, 3, MPI_INT, 1, 0, MPI_COMM_WORLD, &send_request[0]);
        MPI_Isend(fdata, 3, MPI_FLOAT, 1, 1, MPI_COMM_WORLD, &send_request[1]);
        MPI_Isend(ddata, 3, MPI_DOUBLE, 1, 2, MPI_COMM_WORLD, &send_request[2]);

        int ridata[3];
        float rfdata[3];
        double rddata[3];

        MPI_Irecv(ridata, 3, MPI_INT, 1, 3, MPI_COMM_WORLD, &recv_request[0]);
        MPI_Irecv(rfdata, 3, MPI_FLOAT, 1, 4, MPI_COMM_WORLD, &recv_request[1]);
        MPI_Irecv(rddata, 3, MPI_DOUBLE, 1, 5, MPI_COMM_WORLD, &recv_request[2]);
        // MPI_Waitall barchasini kuttirish uchun ishlatiladi
        MPI_Waitall(3, send_request, MPI_STATUSES_IGNORE);
        MPI_Waitall(3, recv_request, MPI_STATUSES_IGNORE);

        cout << "Qabul qilingan int data: ";
        for (int i = 0; i < 3; ++i) {
            cout << ridata[i] << " ";
        }
        cout << endl;

        cout << "Qabul qilingan float data: ";
        for (int i = 0; i < 3; ++i) {
            cout << rfdata[i] << " ";
        }
        cout << endl;

        cout << "Qabul qilingan double data: ";
        for (int i = 0; i < 3; ++i) {
            cout << rddata[i] << " ";
        }
        cout << endl;
    }

    if (rank == 1) {
        int ridata[3];
        float rfdata[3];
        double rddata[3];

        MPI_Irecv(ridata, 3, MPI_INT, 0, 0, MPI_COMM_WORLD, &recv_request[0]);
        MPI_Irecv(rfdata, 3, MPI_FLOAT, 0, 1, MPI_COMM_WORLD, &recv_request[1]);
        MPI_Irecv(rddata, 3, MPI_DOUBLE, 0, 2, MPI_COMM_WORLD, &recv_request[2]);

        int idata[3] = {205, 25, 3};
        float fdata[3] = {31.1414f, 14.74118f, 15.61418f};
        double ddata[3] = {19.514149, 14.41718, 14.41421};

        MPI_Isend(idata, 3, MPI_INT, 0, 3, MPI_COMM_WORLD, &send_request[0]);
        MPI_Isend(fdata, 3, MPI_FLOAT, 0, 4, MPI_COMM_WORLD, &send_request[1]);
        MPI_Isend(ddata, 3, MPI_DOUBLE, 0, 5, MPI_COMM_WORLD, &send_request[2]);

        MPI_Waitall(3, recv_request, MPI_STATUSES_IGNORE);
        MPI_Waitall(3, send_request, MPI_STATUSES_IGNORE);

        cout << "Qabul qilingan int data: ";
        for (int i = 0; i < 3; ++i) {
            cout << ridata[i] << " ";
        }
        cout << endl;

        cout << "Qabul qilingan float data: ";
        for (int i = 0; i < 3; ++i) {
            cout << rfdata[i] << " ";
        }
        cout << endl;

        cout << "Qabul qilingan double data: ";
        for (int i = 0; i < 3; ++i) {
            cout << rddata[i] << " ";
        }
        cout << endl;
    }

    MPI_Finalize();
    return 0;
}


// Output :

// Qabul qilingan int data: 205 25 3 
// Qabul qilingan float data: 31.1414 14.7412 15.6142 
// Qabul qilingan double data: 19.5141 14.4172 14.4142 

// Qabul qilingan int data: 11 22 33 
// Qabul qilingan float data: 31.9714 97.7918 96.618 
// Qabul qilingan double data: 234.259 223.18 656.414 