// WAP for even process to say hello and odd to say world

#include <mpi.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int rank;
	MPI_Init(&argc, &argv);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if (rank % 2 == 0)
		printf("Process %d says: Hello\n", rank);
	else
		printf("Process %d says: world\n", rank);

	MPI_Finalize();

	return (0);
}