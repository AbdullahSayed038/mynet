#include "includes.h"

int main()
{
    t_mynet *mynet = malloc(sizeof(t_mynet));
    if (!mynet)
        return (1);
    init_mynet(mynet);
    matmul(mynet);
    print_C(mynet);
    return (0);
}