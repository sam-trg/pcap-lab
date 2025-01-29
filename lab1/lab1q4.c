// WAP so rth rank process toggles rth index of a string
#include <stdio.h>
#include <mpi.h>

// pseudocode: to the rth index, add 65, 97 +32

int main(int argc, char* argv[]){

    char word[6]="hello"; //you must allocate n+1 bytes to an n character string to account for the nul byte

    int rank;

    MPI_Init(&argc, &argv);
    
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    printf("%d:\t", rank);

    if(word[rank]>=65 && word[rank]<=91) {
        word[rank]+=32;
    }

    else if(word[rank]>=97 && word[rank]<=123) {
        word[rank]-=32;
    } 

    printf("%s\n", word);
    
    MPI_Finalize();

    return 0;

}
