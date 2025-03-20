// Write an MPI program to read N elems from master and let N processes including master check if elem is prime
#include <stdio.h>
#include<mpi.h>

int main(int argc, char* argv[]) {
    int rank; int size; int num;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int arr[size];
    if(rank==0) {
        for(int i=0; i<size; i++) {
            printf("Enter element %d: ", i+1);
            scanf("%d", &arr[i]);
        }
    }
    MPI_Scatter(arr,1, MPI_INT, &num,1, MPI_INT, 0, MPI_COMM_WORLD);
    int is_prime=1;
    for(int j=2; j<=(int)num/2; j++){
        if(num%j==0) {
            is_prime=0;
            break;
        }
    }
    if(num!=0 && num!=1 && is_prime){
        printf("%d is prime.\n", num);
    }
    else{
        printf("%d is not prime.\n", num);
    }
    MPI_Finalize();
    return 0;
}
