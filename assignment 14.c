#include <stdio.h>
#include <cuda_runtime.h>

#define N 1024

__global__ void matrixMultiply(float *A, float *B, float *C, int width) {
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;

    if (row < width && col < width) {
        float value = 0;
        for (int k = 0; k < width; k++) {
            value += A[row * width + k] * B[k * width + col];
        }
        C[row * width + col] = value;
    }
}

int main() {
    int size = N * N * sizeof(float);
    float *h_A, *h_B, *h_C, *h_D, *h_E;

    h_A = (float*)malloc(size);
    h_B = (float*)malloc(size);
    h_C = (float*)malloc(size);
    h_D = (float*)malloc(size);
    h_E = (float*)malloc(size);

    for (int i = 0; i < N * N; i++) {
        h_A[i] = rand() % 10;
        h_B[i] = rand() % 10;
        h_D[i] = rand() % 10;
    }

    float *d_A, *d_B, *d_C, *d_D, *d_E;
    cudaMalloc(&d_A, size);
    cudaMalloc(&d_B, size);
    cudaMalloc(&d_C, size);
cudaMalloc(&d_A, size);
cudaMalloc(&d_B, size);
cudaMalloc(&d_C, size);
cudaMalloc(&d_D, size);
cudaMalloc(&d_E, size);

cudaMemcpy(d_A, h_A, size, cudaMemcpyHostToDevice);
cudaMemcpy(d_B, h_B, size, cudaMemcpyHostToDevice);
cudaMemcpy(d_D, h_D, size, cudaMemcpyHostToDevice);

dim3 threadsPerBlock(16, 16); // 16x16 block
dim3 numBlocks((N + 15) / 16, (N + 15) / 16);

matrixMultiply<<<numBlocks, threadsPerBlock>>>(d_A, d_B, d_C, N);

cudaDeviceSynchronize();
matrixMultiply<<<numBlocks, threadsPerBlock>>>(d_C, d_D, d_E, N);

cudaDeviceSynchronize();
cudaMemcpy(h_E, d_E, size, cudaMemcpyDeviceToHost);

printf("Result matrix E (a few elements):\n");
for (int i = 0; i < 5; i++) {
    printf("%f ", h_E[i]);
}
printf("\n");

free(h_A);
free(h_B);
free(h_C);
free(h_D);
free(h_E);

cudaFree(d_A);
cudaFree(d_B);
cudaFree(d_C);
cudaFree(d_D);
cudaFree(d_E);

return 0;



