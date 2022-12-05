#include <stdio.h>
#include "mpi.h"

int main(int argc, char **argv){
    int myrank, nproc;
    int count = 2;

    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &nproc);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

    int buffer[count * nproc];
    int buf[count];

    if(myrank == 0){
        for(int i = 0; i < (count * nproc); i++){
            buffer[i] = i;
        };
    }

    MPI_Scatter(buffer, count, MPI_INT, buf, count, MPI_INT, 0, MPI_COMM_WORLD);
    
    if(myrank != 0){
        printf("Soy el proceso %d y he recibido los datos: ", myrank);
        for(int i = 0; i < count; i++){
            printf("%d", buf[i]);
            if(i != count - 1){
                printf(", ");
            }
        }
        printf("\n");
        for(int i = 0; i < count; i++){
            buf[i] = buf[i] + myrank;
        }
    }
    
    MPI_Gather(buf, count, MPI_INT, buffer, count, MPI_INT, 0, MPI_COMM_WORLD);

    if(myrank == 0){
        printf("Soy el proceso 0 y he recibido los datos: [");
        for(int i = 0; i < nproc * count; i++){
            printf("%d", buffer[i]);
            if(i != nproc * count - 1){
                printf(", ");
            }
        }
        printf("] \n");
    }

    MPI_Finalize();
}