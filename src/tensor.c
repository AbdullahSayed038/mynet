#include "includes.h"

// void matmul(float *A, float *B, float *C, int M, int N, int K){
//     for (int i = 0; i < M; i++){
//         for (int j = 0; j < N; j++){
//             C[i * N + j] = 0.0f;
//             for (int k = 0; k < K; k++){
//                 C[i * N + j] += A[i * K + k] * B[k * N + j];
//             }
//         }
//     }
// }

// void    math_error()
// {
//     write(2, "Math error\n", 12);
//     exit(1);
// }

void matmul(t_mynet *mynet)
{
    if (mynet->A->columns != mynet->B->rows)
    {
        write(2, "Math error, The matrixes dont have same row and column\n", 56);
        // exitfree();
    }
    int K = mynet->A->columns;
    for (int i = 0; i < mynet->A->rows; i++){
        for (int j = 0; j < mynet->B->columns; j++){
            mynet->C->content[i * mynet->B->columns + j] = 0.0f;
            for (int k = 0; k < K; k++){
                mynet->C->content[i * mynet->B->columns + j] += mynet->A->content[i * K + k] * mynet->B->content[k * mynet->B->columns + j];
            }
        }
    }
}

// void    print_matrix(t_tensor **mat, int row, int col)
// {
//     for (int i = 0; i < row; i++)
//     {
//         printf("[");
//         for (int j = 0; j < col; j++)
//         {
//             printf("%f, ", mat[i * col + j]);
//         }
//         printf("]");
//         printf("\n");
//     }
// }

float *copy_content(float *content, int length)
{
    int j = 0;
    float *ret = malloc(length * sizeof(float));
    if (!ret)
        return(NULL);
    while(j < length)
    {
        ret[j] = content[j];
        j++;
    }
    return ret;
}

t_tensor *create_tensor(float *content, int rows, int columns, int length)
{
    t_tensor *ret = malloc(sizeof(t_tensor));
    
    if (content == NULL)
    {
        ret->content = calloc(length, sizeof(float));
    }
    else
    {
        ret->content = copy_content(content, length);
        if (!ret->content)
            return (NULL);
    }
    ret->rows = rows;
    ret->columns = columns;
    ret->length = length;
    return ret;
}

void    init_mynet(t_mynet *mynet)
{
    float A[] = {1,2,3,4,5,6,7,8,9};
    float B[] = {10,20,30,40,50,60,70,80,90};
    mynet->A = create_tensor(A, 3, 3, 9);
    mynet->B = create_tensor(B, 3, 3, 9);
    mynet->C = create_tensor(NULL, 3, 3, 9);
}

void    print_C(t_mynet *mynet)
{
    for (int i = 0; i < mynet->C->rows; i++)
    {
        printf("[");
        for (int j = 0; j < mynet->C->columns; j++)
        {
            printf("%f, ", mynet->C->content[i * mynet->C->columns + j]);
        }
        printf("]");
        printf("\n");
    }
}