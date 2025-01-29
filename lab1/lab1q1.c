/*WAP to print pow(x,rank) for each process*/

#include<stdio.h>
#include<mpi.h>
#include<math.h>

int main(int argc, char* argv[]){

    int x = 7;

    int rank;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    printf("Process %d says:\t%f\n", rank, pow(x, rank));

    MPI_Finalize();
    
    return 0;
}