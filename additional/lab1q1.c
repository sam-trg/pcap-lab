/*WAP to reverse digits of int array using 9 process
input array: 18, 523, 301, 1234, 2, 14, 108, 1928
output array;81, 523, 103, 4321, 2, 41, 801, 8291
*/
#include <mpi.h>
#include <stdio.h>


int	main(int argc, char *argv[])
{
	int rank;
	int arr[9] = {18, 523, 301, 1234, 2, 14, 108, 150, 1928};
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	int num = arr[rank];
	int reverse=0;
	int temp=num;
	int digit;

	while(temp>0){
		digit=temp%10;
		reverse = reverse*10 + digit;
		temp/=10;
	}
	
	arr[rank]=reverse;
	/*
	if (rank==0) {
		for(int i=0; i<9; i++) {
			printf("%d ", arr[i]); // this doesn't work coz each process has its own local copy with the updated value
		}
	}
	*/

	MPI_Gather(&reverse, 1, MPI_INT, arr, 1, MPI_INT, 0, MPI_COMM_WORLD);

	if (rank==0) {
		for(int i=0; i<9; i++) {
			printf("%d ", arr[i]); 
		}
	}

	MPI_Finalize();

	return (0);
}