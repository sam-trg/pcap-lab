// Write an MPI program using N processes to find 1!+2!....N!.
// Use scan. Also, handle different errors.

#include <stdio.h>
#include <mpi.h>

int main(int argc, char* argv[]) {
    int rank, size, sum;
    int factorial=1;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    for(int i=0; i<rank; i++) {
        factorial*=(i+1);
    }

    for(int i=1; i<size-1;i++){
        MPI_Scan(&factorial, &sum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    }

    printf("Sum is: %d\n", sum);

    MPI_Finalize();
    return 0;
}
