#ifndef DIV-MERGE_H_INCLUDED
#define DIV-MERGE_H_INCLUDED
#define MEM_MAX 100

int elementos(FILE *ini);
void dividir(FILE *ini, int tam, int nEle, FILE **subs, int *maior, int pilha);
void concatena(FILE **subs, int *maior, int nEle, int tam);
void merge(int *vetor, int com, int meio, int fin);
void mergeSort(int *vetor, int com, int fin);
void sortExterno(FILE *ini);

#endif // DIV-MERGE_H_INCLUDED
