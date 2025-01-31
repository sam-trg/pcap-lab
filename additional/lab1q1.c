/*WAP to reverse digits of int array using 6 process
input array: 18, 523, 301, 1234, 2, 14
output array;81, 321, 103, 4321, 2, 41
*/
#include <mpi.h>
#include <stdio.h>

void	reverse(void)
{
	int	new_num;

	while (num > 0)
	{
		new_num
	}
}

int	main(int argc, char *argv[])
{
	int rank;
	int nums[] = {18, 523, 301, 1234, 2, 14} MPI_Init(&argc, &argv);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	reverse(nums, rank);

	MPI_Finalize();

	return (0);
}