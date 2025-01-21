/*WAP to send number from sender to receiver. rcvr prints it*/
#include <stdio.h>
#include <mpi.h>

int main(int argc, char* argv[]){
    MPI_Init(&argc, &argv);
    int num;
    //MPI_send(void* msg, count of msg elems, data type of msg elems, destn rank, tag, commur obj)
    int rank;
    MPI_Status status;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if(rank==0) {
        num = 5;
        MPI_Send(&num, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    }
    else {
        MPI_Recv(&num, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        printf("%d\n", num);
    }
    MPI_Finalize();
    return 0;
}