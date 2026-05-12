#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void matmul(float *A, float *B, float *C, int M, int N, int K){
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            C[i * N + j] = 0.0f;
            for (int k = 0; k < K; k++){
                C[i * N + j] += A[i * K + k] * B[k * N + j];
            }
        }
    }
}

void    print_matrix(float *mat, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        printf("[");
        for (int j = 0; j < col; j++)
        {
            printf("%f, ", mat[i * col + j]);
        }
        printf("]");
        printf("\n");
    }
}

int main(){
    float A[] = {1, 2, 3, 4, 5, 6};  // [2x3]
    float B[] = {7, 8, 9, 10, 11, 12}; // [3x2]
    float C[4];  // [2x2]
    
    matmul(A, B, C, 2, 2, 3);
    print_matrix(C, 2, 2);
    return (0);
}