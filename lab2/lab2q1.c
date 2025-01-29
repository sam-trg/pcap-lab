/* WAP to send a word and recv its togggled form */
#include <stdio.h>
#include <mpi.h>
#include <string.h>

int main(int argc, char* argv[]) {
    int rank;
    char word[1024];

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if(rank==0) {
        printf("Enter a word to send: ");
        scanf("%s", word);
        int length = strlen(word);

        printf("%d:\t%s\n", rank, word);
        MPI_Send(&word, length, MPI_CHAR, 1, 1, MPI_COMM_WORLD);

        MPI_Recv(&word, length, MPI_CHAR, 1, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("%d:\t%s\n", rank, word);
    }
    else {
        MPI_Recv(&word, 1024, MPI_CHAR, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        int i=0;
        while(word[i]!='\0'){
            if(word[i]>=65 &&word[i] <=91) word[i]+=32;
            else if(word[i]>=97 && word[i]<=123) word[i]-=32;
            i++;
        }
        MPI_Send(&word, strlen(word), MPI_CHAR, 0, 2, MPI_COMM_WORLD);
    }

    MPI_Finalize();

    return 0;
}