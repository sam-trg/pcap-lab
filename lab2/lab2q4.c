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
        for(int i=1; i<size-1; i++) {
            if(rank==i) {
                MPI_Recv(&num, 1, MPI_INT, i-1, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                printf("%d:\t%d\n", rank, num);
                num++;
                MPI_Send(&num, 1, MPI_INT, i+1, 1, MPI_COMM_WORLD);
            }
        }

        if(rank==size-1) {
            MPI_Recv(&num, 1, MPI_INT, size-2, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("%d:\t%d\n", rank, num);
            num++;
            MPI_Send(&num, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
        }
    }

    MPI_Finalize();
    return 0;
}