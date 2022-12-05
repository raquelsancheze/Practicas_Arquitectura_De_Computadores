#include <mpi.h>

main(int argc, char** argv){
    int nproc; //Número procesos
    int myrank; //id del proceso

    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD, &nproc);

    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

    double start, finish, time;

    MPI_Barrier(MPI_COMM_WORLD);
    start = MPI_Wtime();

    printf("Hola mundo, soy el proceso %d de un total de %d. \n", myrank, nproc);

    MPI_Barrier(MPI_COMM_WORLD);
    finish = MPI_Wtime();
    time = finish - start;
    printf("Tiempo de ejecución %f. \n",time);

    MPI_Finalize();
}