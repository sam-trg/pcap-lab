/*WAP to print pow(x,rank) for each process*/

#include <math.h>
#include <mpi.h>
#include <stdio.h>

#define X 2

int	main(int argc, char *argv[])
{
	int rank;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	float result = pow(X, rank);
	printf("%d:\t%d^%d = %.0f\n", rank, X, rank, result);

	MPI_Finalize();
	return (0);
}