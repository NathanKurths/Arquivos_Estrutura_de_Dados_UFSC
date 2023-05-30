#include "lab.h"
#include <stdlib.h>

int main(void)
{
    unsigned int qtd = 0;
    double *vector = le_valores("numero.txt", &qtd);

    free(vector);

    return 0;
}