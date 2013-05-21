#include <stdio.h>
#include <cuda.h>
#include <cuda_runtime_api.h>
#include <time.h>
// define matSize 2
// define matSizeC (matSize*matSize)

unsigned matSize;
unsigned matSizeC;

void printmat(unsigned *matrix){
	for (unsigned i=0; i<matSize; ++i){
		for (unsigned j=0; j<matSize; ++j){
			printf("%3u ",matrix[i*matSize+j]);
		}
		printf("\n");
	}
	printf("\n");
}
void MatrixMul(unsigned size,unsigned *a, unsigned *b, unsigned *r);
int main(int argc, char *argv[]){
	srand(time(NULL));
	unsigned *matrixA;
	unsigned *matrixB;
	unsigned *matrixR; 
	if (argc>1){
		sscanf(argv[1],"%u",&matSize);
		matSizeC=matSize*matSize;
		matrixA = malloc(matSizeC*sizeof(unsigned));
		matrixB = malloc(matSizeC*sizeof(unsigned));
		matrixR = calloc(matSizeC,sizeof(unsigned));

		for (unsigned i=0; i<matSizeC; ++i){
			matrixA[i]=rand()%10;
		}
		for (unsigned i=0; i<matSizeC; ++i){
			matrixB[i]=rand()%10;
		}
	}else{
		FILE *file = fopen("inputMatrix.txt","r");
		if (!file){
			printf(" failed \n");
			return 1;
		}
		 
		fscanf(file,"%u",&matSize);
		if (!matSize){
			printf("Nothing to be done\n");
			return 1;
		}
		printf("Matrix Size is %u \n",matSize);
		matSizeC=matSize*matSize;
		//Выделяем память и читаем
		matrixA = malloc(matSizeC*sizeof(unsigned));
		matrixB = malloc(matSizeC*sizeof(unsigned));
		matrixR = calloc(matSizeC,sizeof(unsigned));

		for (unsigned i=0; i<matSizeC; ++i){
			fscanf(file,"%u",matrixA+i);
		}
		for (unsigned i=0; i<matSizeC; ++i){
			fscanf(file,"%u",matrixB+i);
		}
	}
	//На всякий случай отпишемся о прочитанном
	printmat(matrixA);
	printmat(matrixB);

	unsigned *d_matA,*d_matB,*d_matR;
	cudaMalloc((void**)&d_matA,matSizeC*sizeof(unsigned));
	cudaMalloc((void**)&d_matB,matSizeC*sizeof(unsigned));
	cudaMalloc((void**)&d_matR,matSizeC*sizeof(unsigned));
	cudaMemcpy(d_matA,matrixA,matSizeC*sizeof(unsigned),cudaMemcpyHostToDevice);
	cudaMemcpy(d_matB,matrixB,matSizeC*sizeof(unsigned),cudaMemcpyHostToDevice);
	cudaMemcpy(d_matR,matrixR,matSizeC*sizeof(unsigned),cudaMemcpyHostToDevice);
	MatrixMul(matSize,d_matA,d_matB,d_matR);
	cudaMemcpy(matrixR,d_matR,matSizeC*sizeof(unsigned),cudaMemcpyDeviceToHost);
	printmat(matrixR);

   return 0;
}
