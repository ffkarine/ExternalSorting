#include <stdio.h>
#include <stdlib.h>
#include "div-merge.h"

int main()
{
    FILE *ini = fopen("entrada.txt", "r+");

    if(!ini)
        printf("Erro ao abrir o arquivo!");
    else
        sortExterno(ini);

    return 0;
}
