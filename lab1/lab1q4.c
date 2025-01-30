// WAP so nth rank process toggles nth index of a string

#include <stdio.h>
#include <mpi.h>
#include <ctype.h>

void toggle(char* c) {
    if(isupper(*c)) *c = tolower(*c);
    else if(islower(*c)) *c = toupper(*c); 
}

int main(int argc, char* argv[]){
    int rank;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    char word[6]="hello"; //you must allocate n+1 bytes to an n character string to account for the nul byte

    printf("%d:\t", rank);
    toggle(word+rank);
    printf("%s\n", word);
    
    MPI_Finalize();
    return 0;
}