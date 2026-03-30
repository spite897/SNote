/*
 * in n A B
 *
 * C[n+1]
 * for i to n
 *      C[i] += A[i] + B[i]
 *      if C[i] > 1 
 *          C[i] -= 2
 *          C[i+1] += 1
 *
*/

#include<stdio.h>
#include<stdlib.h>

#define N 5

int A[N] = { 0,0,0,1,0 };
int B[N] = { 1,1,1,1,1 };

int* binaryAdd(int n, int* A, int* B){
    int i;
    int* ret = (int*)malloc(sizeof(int)*(n+1));

    for ( i=0; i<n; i++){
        ret[i] += A[i] + B[i];
        if (ret[i] > 1 ){
            ret[i] -= 2;
            ret[i+1] += 1;
        }

    }

    return ret;
}

int main(){
    int* C ;
    int i;

    C = binaryAdd( N, A, B);

    for(i=0;i<N+1;i++){
        printf("C[%d] : %d \n", i, C[i] );
    }


    return 0;
}

#undef N
