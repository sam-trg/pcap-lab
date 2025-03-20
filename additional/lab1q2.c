/* Write an MPI program to find prime no's from 1-100 using two processes*/

#include <mpi.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int rank;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	int start = rank * 50;
	int end = start + 50;
	for (int i = start; i < end; i++)
	{
		int is_prime = 1;
		for (int j = 2; j < (int)i / 2; j++)
		{
			if (i % j == 0)
			{
				is_prime = 0;
				break ;
			}
		}
		if (i != 0 && i != 1 && is_prime)
		{
			printf("%d ", i);
		}
	}
	MPI_Finalize();
	return (0);
}