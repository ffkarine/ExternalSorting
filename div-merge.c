#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "div-merge.h"

int elementos(FILE *ini)
{
    int tam = 0;
    while(!feof(ini))
    {
        fscanf(ini, "%*d");
        tam++;
    }

    rewind(ini);

    return tam;
}
void dividir(FILE *ini, int tam, int nEle, FILE **subs, int *maior, int pilha)
{
    int j, k, temp = 0;
    char arqs[30];

    fscanf(ini, "%d", &temp);
    *maior = temp;
    rewind(ini);

    for(j = 0; j < nEle; j++)
    {
        sprintf(arqs, "arq%d.txt", j);
        subs[j] = fopen(arqs, "w+");


            for(k = 0; k < pilha && !feof(ini); k++) //coloca a qtd de elementos (no max MEM_MAX) nos arqs auxiliares e encontra o maior
            {
                fscanf(ini, "%d", &temp);
                fprintf(subs[j], "%d ", temp);

                if(temp > *maior)
                    *maior = temp;
            }

        fclose(subs[j]);
    }
}

void concatena(FILE **subs, int *maior, int nEle, int tam)
{
    char nomearqs[30];
    int *concat = malloc(nEle * sizeof(int)), i = 0, j = 0, menor, qtd = 0, pos;
    FILE *saida = fopen("saida.txt", "w");

    for(i = 0; i < nEle; i++)
    {
        sprintf(nomearqs, "arq%d.txt", i);
        subs[i] = fopen(nomearqs, "r"); //abre o arquivo i
    }

    for(i = 0; i < nEle && fscanf(subs[i], "%d", &concat[i]) != EOF; i++); //pega o menor valor de cada arquivo

    while(qtd < tam)
    {
        //procura o menor entre os menores
        j = 0;
        menor = concat[j];

        for(j = 0; j < nEle; j++)
        {
            if(concat[j] <= menor && concat[j] <= *maior)
            {
                menor = concat[j];
                pos = j;
            }
        }

        if(fscanf(subs[pos], "%d", &concat[pos]) != EOF); //caminha no arquivo de onde veio o menor

        else
            concat[pos] = *maior+1; //se for o ultimo elemento do arquivo, tira ele do limite de captura

        fprintf(saida, "%d ", menor);
        qtd++;
    }

    for(i = 0; i < nEle; i++)
        fclose(subs[i]);

}

void merge(int *vetor, int com, int meio, int fin)
{
    int i, j, tam = (fin - com + 1), met1 = com, fin1 = 0, met2 = meio+1, fin2 = 0, *temp = malloc(tam * sizeof (int));

    if(temp)
    {
        for(i = 0; i<tam; i++)
        {
            if(!fin1 && !fin2) //enquanto nenhuma das duas metades chegar no final
            {
                //verifica o menor número e insere no temp
                if(vetor[met1] < vetor[met2])
                {
                    temp[i] = vetor[met1];
                    met1++;
                }
                else
                {
                    temp[i] = vetor[met2];
                    met2++;
                }

                //caso uma das metades chegue no fim, muda o valor da var. de controle e sai do if
                if(met1 > meio)
                    fin1 = 1;

                if(met2 > fin)
                    fin2 = 1;
            }
            else
            {
                //verifica qual das metades chegou ao final e copia o resto da outra para o temp
                if(fin1)
                {
                    temp[i] = vetor[met2];
                    met2++;
                }
                else
                {
                    temp[i] = vetor[met1];
                    met1++;
                }
            }
        }
        for (i = 0, j = com; i < tam; i++, j++)
            vetor[j] = temp[i];    }
    free(temp);
}

void mergeSort(int *vetor, int com, int fin)
{
    int meio;
    if(com < fin)
    {
        meio = (com + fin)/2;
        mergeSort(vetor, com, meio);
        mergeSort(vetor, meio+1, fin);
        merge(vetor, com, meio, fin);
    }
}

void sortExterno(FILE *ini)
{
    int tam, pilha = MEM_MAX, nEle, i, j, k, *maior = malloc(sizeof(int));
    int *temp = malloc(pilha * sizeof(int));
    char nomearqs[30];
    tam = elementos(ini);

    if(tam <= pilha) //se a qtd total de elementos for menor que a minha pilha só ordena
    {
        FILE *men = fopen("saida.txt", "w");

        for(j = 0; j < tam; j++)
                fscanf(ini, "%d", &temp[j]);

        mergeSort(temp, 0, tam);

        for(j = 0; j < tam; j++)
            fprintf(men, "%d ", temp[j]);

        fclose(men);
    }

    else
    {
        if(tam%pilha) //verifica se vão ter elementos sobressalentes
            nEle = ceil((tam/pilha)+1);

        else
            nEle = ceil(tam/pilha);

        if(nEle > MEM_MAX)
        {
            printf("Nao e possivel ordenar este arquivo com uma pilha de tamanho %d\n", pilha);
            pilha = ceil(sqrt(tam));
            printf("Para %d elementos e necessario uma pilha de pelo menos %d de tamanho.\n", tam, pilha);
            return -1;
        }

        pilha = MEM_MAX;

        FILE **subs = malloc(nEle * sizeof(FILE*));

        if(!subs)
            printf("ERRO");

        ///divide o arquivo inicial em sub arquivos
        dividir(ini, tam, nEle, subs, maior, pilha);

        ///ordena os sub arquivos
        for(i = 0; i < nEle; i++)
        {
            sprintf(nomearqs, "arq%d.txt", i);
            subs[i] = fopen(nomearqs, "r"); //abre o arquivo de ordem i

            for(j = 0; j < pilha && fscanf(subs[i], "%d", &temp[j]) != EOF; j++);

            k = j;
            fclose(subs[i]); //fecha o arquivo de ordem i
            mergeSort(temp, 0, k-1); //ordena o vetor temp, que corresponde ao arquivo i
            subs[i] = fopen(nomearqs, "w"); //abre o arquivo i novamente para colocar o vetor ordenado lá dentro
            for(j = 0; j < k; j++)
                fprintf(subs[i], "%d ", temp[j]); //coloca o o vetor ordenado lá dentro

            fclose(subs[i]);// fecha o arquivo i
        }

        ///concatena os arquivos ordenados
        concatena(subs, maior, nEle, tam);

        ///remove os arquivos auxiliares
        for(i = 0; i < nEle; i++)
        {
            sprintf(nomearqs, "arq%d.txt", i);
            remove(nomearqs);
        }

        free(subs);
    }
    free(maior);
}
