#include <mpi.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    int rank, size;
    long long N = 1000000000;
    long long local_sum = 0, global_sum = 0;
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

    MPI_Reduce(&local_sum, &global_sum, 1, MPI_LONG_LONG, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("The sum of the first %lld integers is: %lld\n", N, global_sum);
    }

    MPI_Finalize();

    return 0;
}
