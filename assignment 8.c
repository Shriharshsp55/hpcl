#include <omp.h>
#include <stdio.h>

int main() {
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();

        if (thread_id == 0) {
            printf("Thread %d: Series of 2: ", thread_id);
            for (int i = 1; i <= 5; i++) {
                printf("%d ", 2 * i);
            }
            printf("\n");
        }

        if (thread_id == 1) {
            printf("Thread %d: Series of 4: ", thread_id);
            for (int i = 1; i <= 5; i++) {
                printf("%d ", 4 * i);
            }
            printf("\n");
        }
    }

    return 0;
}
