/*Write MPI program to read N values in an array in the root process.
Distribute these N values among N processes.
Each process finds the square of the value it receives.
Let every process return these values to the root and
root process gathers and prints the result.
Use collective communication routines*/

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int size, rank;
	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int num;
	int *arr = NULL;

	if (rank == 0)
	{
		// read N values in root
		arr = (int *)malloc(size * sizeof(int));
		printf("Enter %d elements:\n", size);
		for (int i = 0; i < size; i++)
		{
			scanf("%d", &arr[i]);
		}
	}
	// distribute to N processes
	MPI_Scatter(arr, 1, MPI_INT, &num, 1, MPI_INT, 0, MPI_COMM_WORLD);

	num *= num;

	// collect from N processes and print result
	MPI_Gather(&num, 1, MPI_INT, arr, 1, MPI_INT, 0, MPI_COMM_WORLD);

	if (rank == 0)
	{
		printf("Here is the new array:\n");
		for (int i = 0; i < size; i++)
		{
			printf("%d\n", arr[i]);
		}

		free(arr);
	}

	MPI_Finalize();
	return (0);
}