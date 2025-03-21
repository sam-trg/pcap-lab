// WAP for each slave to print num recvd from master

#include <mpi.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	MPI_Init(&argc, &argv);

	int size, rank;
	int num;

	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if (rank == 0)
	{
		printf("Enter a number: ");
		scanf("%d", &num);

		for (int i = 1; i < size; i++)
		{
			MPI_Send(&num, 1, MPI_INT, i, 1, MPI_COMM_WORLD);
		}
		printf("All messages sent successfully.\n");
	}

	else
	{
		MPI_Recv(&num, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("%d:\t Received %d\n", rank, num);
	}

	MPI_Finalize();
	return (0);
}