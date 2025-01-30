/*WAP for each process to do different arithmetic operation*/

#include <mpi.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int a = 3;
	int b = 2;

	int rank;
	MPI_Init(&argc, &argv);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if (rank == 0)
		printf("Sum of %d and %d is: %d\n", a, b, a + b);
	else if (rank == 1)
		printf("Product of %d and %d is: %d\n", a, b, a * b);
	else if (rank == 2)
		printf("Difference of %d and %d is: %d\n", a, b, a - b);
	else if (rank == 3)
		printf("Quotient of %d and %d is: %d\n", a, b, a / b);

	MPI_Finalize();

	return (0);
}