/*WAP for circular msg passing*/

#include<stdio.h>
#include<mpi.h>

int main(int argc, char* argv[]) {
    
    MPI_Init(&argc, &argv);
    
    int size, rank;
    int num;

    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    
    if(rank==0) {
        printf("Enter a number: ");
        scanf("%d", &num);
        num++;
        MPI_Send(&num, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
        MPI_Recv(&num, 1, MPI_INT, size-1, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Root:\t%d\n", num);
    }

    else {
        MPI_Recv(&num, 1, MPI_INT, rank-1, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("%d:\t%d\n", rank, num);
        num++;

        int next = (rank+1)%size;
        MPI_Send(&num, 1, MPI_INT, next, 1, MPI_COMM_WORLD);
    }

    MPI_Finalize();

    return 0;
}