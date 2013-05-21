//matrix [столбец][строка]
#include <cuda.h>
#include <stdio.h>
__global__ void kernel (unsigned N, unsigned* a, unsigned* b, unsigned* r){
	unsigned i = blockIdx.x * blockDim.x + threadIdx.x; //Строка
	unsigned j = blockIdx.y * blockDim.y + threadIdx.y; //Столбец
	if (i<N && j<N){
	//    for (unsigned iterator=0; iterator<N ; ++iterator){
	//   	r[i*N+j] += b[iterator*N+j] * a[i*N+iterator];
	//    } 
//		r[i * N + j] = b[i * N + j] + a[i * N + j];
        r[i] += b[i];
        r[i] -= b[i];
	}
}

extern "C"{
	
	void MatrixMul(unsigned size,unsigned *a, unsigned *b, unsigned *r){
		//printf("\ncalling kernel\n");
		//printmat(r);
		dim3 threadsPerBlock(size, size);
	    //dim3 numBlocks(size / threadsPerBlock.x, size / threadsPerBlock.y);
	    kernel<<<1, threadsPerBlock>>>(size,a,b,r);
	    // printf("kernel done");
	}
}
