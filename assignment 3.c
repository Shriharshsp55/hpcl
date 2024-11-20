#include <omp.h>
#include <stdio.h>

int main() {
    // Initialize the OpenMP parallel region
    #pragma omp parallel
    {
        // Get the thread ID
        int thread_id = omp_get_thread_num();
        // Get the total number of threads
        int num_threads = omp_get_num_threads();

        // Print a message with thread ID
        printf("Hello, world from thread %d out of %d threads!\n", thread_id, num_threads);
    }

    return 0;
}
