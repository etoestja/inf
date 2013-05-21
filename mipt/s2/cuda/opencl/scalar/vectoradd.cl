__kernel void VectorAdd(__global int* vc, __global int* vb, __global int* va){
        int i;
        for(i=0;i<100;i++){
                vc[i]=vb[i]*va[i];
        }
}
