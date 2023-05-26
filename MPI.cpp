#include <mpi.h>
#include <stdlib.h>
#include <string>

int main(int argc, char **argv){
    char *name;
    int len;

    name = (char*)malloc(MPI_MAX_PROCESSOR_NAME * sizeof(char));

    int size;
    int rank;
    int flag;
    int send;
    int recv;

    MPI_Status status;
    MPI_Request send_request, recv_request;

    MPI_Initialized(&flag);
   // printf("\nMPI_Initialized : %d", flag);

    MPI_Init( &argc , &argv);
    // MPI_Init ishlatilganmi yoki yo'qligini tekshirish
    MPI_Initialized(&flag);
   // printf("\nMPI_Initialized : %d", flag);

    // Jarayonlar sonini o'lish
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    // Jarayon rankini o'lish
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // printf("\nsize : %d     rank : %d \n", size, rank);

    // Processor name ni o'lish
    MPI_Get_processor_name(name, &len);

    if (rank == 0){
        send = 5;
        // Bir jarayondan boshqa jarayonga habar yuborish
        MPI_Send( &send , 1 , MPI_INT , 1 , 1 , MPI_COMM_WORLD);
        printf("\nrank : %d   send : %d\n", rank, send);
    }

    if (rank == 1){
        // Habarni qabul qilish
        MPI_Recv( &recv , 1 , MPI_INT , 0, 1 , MPI_COMM_WORLD , &status);
        printf("\nrank : %d   recv : %d\n", rank, recv);
    }

    if (rank == 4){
        send = 12;
        //Blakirovkasiz habar yuborish
        MPI_Isend( &send , 1 , MPI_INT , 3 , 2 , MPI_COMM_WORLD , &send_request);
        // Blokirovkasiz habar yuborilganda jarayon ishni tugashini kutmaydi
        // MPI_Wait Jarayonni kutdiradi
        MPI_Wait(&send_request, &status);
        printf("\nrank : %d     Isend : %d\n", rank, send);
    }

    if (rank == 3){
        // Blokirovkasiz habarni qabul qilish
        MPI_Irecv(&recv, 1, MPI_INT, 4, 2, MPI_COMM_WORLD, &recv_request);
        MPI_Wait(&recv_request, &status);
        printf("\nrank : %d      Irecv : %d", rank, recv);
    }
    MPI_Finalize();

    printf("\n%s",name);

    return 0;
}