/*WAP for even slave to print square and odd, cube of num bsent from master's array*/
#include<stdio.h>
#include<mpi.h>

int main(int argc, char* argv[]) {
    
    MPI_Init(&argc, &argv);
    
    int size, rank;
    int num;
    char* buff[1024];

    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    
    if(rank==0) {

        int arr[3] = {3,6,5};
        int bsize = 3*sizeof(char) + MPI_BSEND_OVERHEAD;
        MPI_Buffer_attach(buff, bsize);
        for(int i=1; i<size; i++) {
            MPI_Bsend(arr+i-1, 1, MPI_INT, i, 1, MPI_COMM_WORLD);
        }
        MPI_Buffer_detach(buff, &bsize);
    }
    
    for(int i=1; i<size; i++) {
        if(rank==i) {
            MPI_Recv(&num, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            if(i%2==0) printf("%d : %d\n", num, num*num);
            else printf("%d : %d\n", num, num*num*num);
        }
    }
    
    MPI_Finalize();
    return 0;
}