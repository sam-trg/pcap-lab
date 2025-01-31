// Write a MPI program to read an integer value M and NXM elements into an ID array in the root process,
// where N is the number of processes. Root process sends M elements to each process.
// Each process finds average of M elements it received and sends these average values to root.
// Root collects all the values and finds the total average. Use collective communication routines.

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int rank, size, M;
	int *row = NULL;
	int **arr = NULL;
	int sum, avg;
	int *partial_avg = NULL;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if (rank == 0)
	{
		printf("Enter value of M: ");
		scanf("%d", &M);

		arr = (int **)(malloc(size * sizeof(int *)));

		for (int i = 0; i < size; i++)
		{
			arr[i] = (int *)malloc(M * sizeof(int));
			for (int j = 0; j < M; j++)
			{
				printf("Enter %dx%dth elem: ", i, j);
				scanf("%d", &arr[i][j]);
			}
		}

		partial_avg = (int *)malloc(size * sizeof(int));
	}

	MPI_Scatter(arr, size, MPI_INT, row, M, MPI_INT, 0, MPI_COMM_WORLD);

	for (int i = 0; i < M; i++)
	{
		sum += row[i];
	}
	avg = sum / M;

	MPI_Gather(&avg, 1, MPI_INT, partial_avg, size, MPI_INT, 0, MPI_COMM_WORLD);

	if (rank == 0)
	{
		for (int i = 0; i < size; i++)
			printf("%d", partial_avg[i]);
	}

	MPI_Finalize();
	return (0);
}