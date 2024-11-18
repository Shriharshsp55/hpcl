#include <mpi.h>
#include <stdio.h>

#define NUM_ELEMENTS 2

int main(int argc, char* argv[]) {
    int rank, size;
    int data[NUM_ELEMENTS];

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    data[0] = rank * 10 + 2;
    data[1] = rank * 10 + 1;

    if (rank == 0) {
        printf("Root process %d: Receiving messages:\n", rank);

        for (int i = 1; i < size; i++) {
            MPI_Recv(data, NUM_ELEMENTS, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("Received from process %d: %d %d\n", i, data[0], data[1]);
        }

        printf("Received from process %d: %d %d\n", rank, data[0], data[1]);
    } else {
        MPI_Send(data, NUM_ELEMENTS, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();

    return 0;
}
