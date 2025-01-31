/*WAP for even slave to print square and odd,
	cube of num bsent from master's array*/

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int size, rank;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int num;

	if (rank == 0)
	{
		// accept array of nums to be sent
		int *arr = (int *)malloc(size * sizeof(int));
		printf("Enter %d elements:\n", size);
		for (int i = 0; i < size; i++)
		{
			scanf("%d", arr + i);
		}

		// init buffer
		int bsize = size * sizeof(int) + MPI_BSEND_OVERHEAD;
		void *b = malloc(bsize);

		// bsend
		MPI_Buffer_attach(b, bsize);
		for (int i = 1; i < size; i++)
		{
			MPI_Bsend(arr + i, 1, MPI_INT, i, 1, MPI_COMM_WORLD);
		}
		MPI_Buffer_detach(b, &bsize);
		free(b);
	}

	else
	{
		MPI_Recv(&num, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		if (rank % 2 == 0)
			printf("P%d:\t%d - %d\n", rank, num, num * num);
		else
			printf("P%d:\t%d - %d\n", rank, num, num * num * num);
	}

	free(arr);
	MPI_Finalize();
	return (0);
}