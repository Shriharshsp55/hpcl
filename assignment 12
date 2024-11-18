#include <mpi.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    int rank, size;
    long long N = 1000000;
    long long local_sum = 0, total_sum = 0;
    long long start, end;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    long long range_per_process = N / size;
    start = rank * range_per_process + 1;
    end = (rank + 1) * range_per_process;
    if (rank == size - 1) {
        end = N;
    }

    for (long long i = start; i <= end; i++) {
        local_sum += i;
    }

    int prev = (rank - 1 + size) % size;
    int next = (rank + 1) % size;

    if (rank == 0) {
        MPI_Send(&local_sum, 1, MPI_LONG_LONG, next, 0, MPI_COMM_WORLD);
        MPI_Recv(&total_sum, 1, MPI_LONG_LONG, prev, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        total_sum += local_sum;
        printf("The total sum of the first %lld integers is: %lld\n", N, total_sum);
    } else {
        MPI_Send(&local_sum, 1, MPI_LONG_LONG, next, 0, MPI_COMM_WORLD);
        MPI_Recv(&total_sum, 1, MPI_LONG_LONG, prev, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        total_sum += local_sum;

        if (rank == size - 1) {
            MPI_Send(&total_sum, 1, MPI_LONG_LONG, next, 0, MPI_COMM_WORLD);
        }
    }

    MPI_Finalize();

    return 0;
}
