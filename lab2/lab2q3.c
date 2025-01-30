/*WAP for even slave to print square and odd, cube of num bsent from master's array*/

#include<stdio.h>
#include<mpi.h>

int main(int argc, char* argv[]) {
    int size, rank;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int num;
    char* buf[1024];
    
    if(rank==0) {
        int arr[8] = {3,9,5,2,8,5,6,7};
        int bsize = 8*sizeof(int) + MPI_BSEND_OVERHEAD;
        MPI_Buffer_attach(buf, bsize);
        for(int i=1; i<size; i++) {
            MPI_Bsend(arr+i-1, 1, MPI_INT, i, 1, MPI_COMM_WORLD);
        }
        MPI_Buffer_detach(buf, &bsize);
    }

    else {
        
        MPI_Recv(&num, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        if(rank%2==0) printf("%d:\t%d - %d\n",rank, num, num*num);
        else printf("%d:\t%d - %d\n",rank, num, num*num*num);
    }

    MPI_Finalize();

    return 0;
}