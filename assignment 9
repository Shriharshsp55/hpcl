#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {
    int rank, size;
    char message[20];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    sprintf(message, "Hello from process %d", rank);

    if (rank == 0) {
        printf("Root process %d: Receiving messages:\n", rank);

        for (int i = 1; i < size; i++) {
            MPI_Recv(message, 20, MPI_CHAR, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("Received message: %s\n", message);
        }

        printf("Received message: Hello from process 0\n");
    } else {
        MPI_Send(message, 20, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();

    return 0;
}
