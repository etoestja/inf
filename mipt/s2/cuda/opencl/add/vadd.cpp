#include <stdio.h>
#include <CL/cl.h>

#define SIZE 10

//using namespace std;

int va[SIZE];
int vb[SIZE];
int vc[SIZE];

char* load_program_source(const char*);

int Init(){
        int i;
        srand(20);
        for(i=0;i<SIZE;i++){
                va[i]=rand()%10;
                vb[i]=rand()%10;
        }
}

char* load_program_source(const char *filename)
{
        int fileSize = 0;
        FILE *pFile = fopen(filename, "r");
        rewind(pFile);
        fseek(pFile, 0, SEEK_END);
        fileSize = ftell(pFile);
        rewind(pFile);

        char *data = (char*) calloc(sizeof(char), fileSize+1);
        fread(data, 1, fileSize, pFile);
        data[fileSize]='\0';
        fclose(pFile);
        return data;
}

int main(){
	int i;
        if(!Init()){
                printf("Unable to initialize data");
                return 1;
        }

	for(i=0; i<SIZE; i++) printf("%d ", va[i]); printf("\n");
        for(i=0; i<SIZE; i++) printf("%d ", vb[i]); printf("\n");

	cl_platform_id platforms[3];

    unsigned int numPlatforms;
    cl_int ciErrNum;
	cl_context hContext;
    ciErrNum = clGetPlatformIDs(3,platforms,&numPlatforms);
   if (ciErrNum != CL_SUCCESS)
    {
        printf(" Error %d  clGetPlatformIDs call !!!\n",ciErrNum);
     return -1;
    }

    cl_context_properties properties[] = { CL_CONTEXT_PLATFORM, (intptr_t)platforms[0], 0 };

    hContext = clCreateContextFromType(properties, CL_DEVICE_TYPE_GPU, 0, 0, &ciErrNum);
    if (ciErrNum != CL_SUCCESS)
    {
        printf("Error %d Failed to create OpenCL context!\n",ciErrNum);
        return -1;
    }


	cl_int  *eret;
	eret = new cl_int;

        cl_context GPUContext = clCreateContextFromType(properties,CL_DEVICE_TYPE_ALL, NULL, NULL, eret);

        if(!GPUContext){
                printf("Error: Failed to create context %d \n",*eret);
                return 1;
        }
	delete eret;

        //Get the list of GPU devices associated with this context
        size_t ParmDataBytes;
        clGetContextInfo(GPUContext, CL_CONTEXT_DEVICES, 0, NULL, &ParmDataBytes);
        cl_device_id* GPUDevices = (cl_device_id*)malloc(ParmDataBytes);
        clGetContextInfo(GPUContext, CL_CONTEXT_DEVICES, ParmDataBytes,GPUDevices,NULL);

        //Create a command queue on first gpu device
        cl_command_queue GPUCommandQueue = clCreateCommandQueue(GPUContext, GPUDevices[0],0,NULL);
        if(!GPUCommandQueue){
                printf("Error: Failed to create a command queue");
                return 1;
        }

        //Allocate memory
        cl_mem GPUva = clCreateBuffer(GPUContext, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, sizeof(int)*SIZE, va, NULL);
        cl_mem GPUvb = clCreateBuffer(GPUContext, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, sizeof(int)*SIZE, vb, NULL);
        cl_mem GPUvc = clCreateBuffer(GPUContext, CL_MEM_WRITE_ONLY, sizeof(int)*SIZE, NULL, NULL);

        //Create OCL program reading the source code from the file
        char * OclSource = load_program_source("vectoradd.cl");
        cl_program  OpenCLProgram = clCreateProgramWithSource(GPUContext,1,(const char**)&OclSource,NULL,NULL);

        //Build the program
        clBuildProgram(OpenCLProgram,0,NULL,NULL,NULL,NULL);

        //obtain the handle for the kernel
        cl_kernel OpenCLVectorAdd = clCreateKernel(OpenCLProgram,"VectorAdd",NULL);

       //associate GPU memory with the kernel
        clSetKernelArg(OpenCLVectorAdd, 0, sizeof(cl_mem), (void*)&GPUvc);
        clSetKernelArg(OpenCLVectorAdd, 1, sizeof(cl_mem), (void*)&GPUvb);
        clSetKernelArg(OpenCLVectorAdd, 2, sizeof(cl_mem), (void*)&GPUva);

        //Launch the kernel in the GPU
        size_t WorkSize[1] = {SIZE};
        clEnqueueNDRangeKernel(GPUCommandQueue, OpenCLVectorAdd,1,NULL,WorkSize,NULL,0,NULL,NULL);

        //copy the result back to the main memory
        clEnqueueReadBuffer(GPUCommandQueue, GPUvc, CL_TRUE,0,sizeof(int) * SIZE, vc, 0, NULL, NULL);

	for(int i=0; i<SIZE; i++) printf("%d ",vc[i]); printf("\n");

        //cleanup
        free(GPUDevices);
        clReleaseKernel(OpenCLVectorAdd);
        clReleaseProgram(OpenCLProgram);
        clReleaseCommandQueue(GPUCommandQueue);
        clReleaseContext(GPUContext);
        clReleaseMemObject(GPUva);
        clReleaseMemObject(GPUvb);
        clReleaseMemObject(GPUvc);

        printf("End");
        return 0;
}

