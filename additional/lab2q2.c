// Write MPI program to read N in root. Using N processs including root
// Find our 1! + (1+2) + 3! + (1+2+3+4) +5!
// i.e. clearly odd rank calcs fact and even prints sum
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int	rank;
	int	size;
	int	local_term=0;
	int	sum;
	int	N;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	if (rank == 0) {
		printf("Enter stop value N: ");
		scanf("%d", &N);
		if (N > size) {
			printf("Invalid input\n");
            exit(0);
		}
	}

	if (rank < N) {
        printf("%d\n", rank);
        if (rank % 2 == 0) {
			int sum=0;
            for (int i = 0; i <= rank; i++) { 
				printf("%d+", i);
                sum+=i;
            }
            local_term+=sum;
		}
        else {
            int fact=1;
            int temp=rank;
            while(temp>0) {
                fact*=temp;
                temp-=1;
            }
            printf("%d!=%d", rank, fact);
            local_term+=fact;
        }
    }
	MPI_Finalize();
	return (0);
}
