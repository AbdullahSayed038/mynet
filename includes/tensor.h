#ifndef TENSOR_H
# define TENSOR_H

    #include "includes.h"

    typedef struct s_tensor
    {
        float *content;
        int rows;
        int columns;
        int length;
    } t_tensor;

    typedef struct s_mynet
    {
        t_tensor *A;
        t_tensor *B;
        t_tensor *C;
    } t_mynet;



    void    print_C(t_mynet *mynet);
    void    init_mynet(t_mynet *mynet);
    t_tensor *create_tensor(float *content, int rows, int columns, int length);
    float *copy_content(float *content, int length);
    void matmul(t_mynet *mynet);

#endif