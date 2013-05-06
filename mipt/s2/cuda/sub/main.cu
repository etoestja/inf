#include <stdio.h>

// Variables
float* h_A;
float* h_B;
float* h_C;
float* d_A;
float* d_B;
float* d_C;

// Functions
void Cleanup(bool);
void RandomInit(float*, int);
void ParseArguments(int, char**);

// Device code
__global__ void VecAdd(const float* A, const float* B, float* C, int N)
{
    int i = blockDim.x * blockIdx.x + threadIdx.x;
    if (i < N)
        C[i] = A[i] - B[i];
}

// Host code
int main(int argc, char** argv)
{
    int N;
    scanf("%d", &N);

    size_t size = N * sizeof(float);

    // Allocate input vectors h_A and h_B in host memory
    h_A = (float*)malloc(size);
    h_B = (float*)malloc(size);
    h_C = (float*)malloc(size);

    cudaError_t error;
    
    // Initialize input vectors
    for(int i = 0; i < N; i++)
    {
        scanf("%f", h_A + i);
        scanf("%f", h_B + i);
    }


    // Allocate vectors in device memory
    error = cudaMalloc((void**)&d_A, size);
    error = cudaMalloc((void**)&d_B, size);
    error = cudaMalloc((void**)&d_C, size);

    // Copy vectors from host memory to device memory
    error = cudaMemcpy(d_A, h_A, size, cudaMemcpyHostToDevice);
    error = cudaMemcpy(d_B, h_B, size, cudaMemcpyHostToDevice);

    // Invoke kernel
    int threadsPerBlock = 256;
    int blocksPerGrid = (N + threadsPerBlock - 1) / threadsPerBlock;
    VecAdd<<<blocksPerGrid, threadsPerBlock>>>(d_A, d_B, d_C, N);

    // Copy result from device memory to host memory
    // h_C contains the result in host memory
    
    error = cudaMemcpy(h_C, d_C, size, cudaMemcpyDeviceToHost);

    // Verify result
    int i;
    for (i = 0; i < N; ++i)
        printf("%f+%f=%f\n", h_A[i], h_B[i], h_C[i]);
}
