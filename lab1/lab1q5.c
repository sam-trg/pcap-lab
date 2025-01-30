/*WAP where even ranked process prints factorial and odd fibonacci*/

#include <stdio.h>
#include <mpi.h>

void fib(int n) {
    int c;
    int a=0;
    printf(" %d ", a);
    if (n==1) return; 
    int b=1;
    printf(" %d ", b);
    if (n==2) return;
    for(int i=0; i<n-2; i++) {
        c=a+b;
        printf(" %d ", c);
        a = b;
        b = c;
    }
}

int factorial(int n){
    int product = 1;
    for(int i=n; i>0; i--){
        product*=n;
        n--;
    }
    return product;
}

int main(int argc, char* argv[]){
    int rank;    
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if(rank%2==0) {
        printf("%d:\tFactorial: %d\n", rank, factorial(rank));
    }
    else {
        printf("%d:\tSeries: ", rank);
        fib(rank);
        printf("\n");
    }
    
    MPI_Finalize();
    return 0;
}