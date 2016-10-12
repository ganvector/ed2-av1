#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ArrayCreator.h"
#include "Ordenacao.h"
<<<<<<< HEAD
#define TAM 5000 //o vetor tem que ser declarado com TAM+1, dentro das funções é chamado com TAM normalmente
=======
#define TAM 100000 //o vetor tem que ser declarado com TAM+1, dentro das funções é chamado com TAM normalmente
>>>>>>> origin/master

int main()
{
    int *vetor;
    int i;
<<<<<<< HEAD
    clock_t start, end;
    /*printf("\t\t---SELECTSORT---\n");
    for (i=1;i<=20;i++){
        vetor = (int*)malloc((i*TAM+1)*sizeof(int));
        ordem_crescente(vetor, i*TAM);
        start = clock();
        SelectSort(vetor, i*TAM);
        end = clock();
        printf("O tempo com %d valores foi -> %f segundos\n", i*TAM, (float)(end-start)/CLOCKS_PER_SEC);
        free(vetor);
    }*/

    printf("\t\t---INSERTSORT---\n");
    for(i=1;i<=20;i++){
        vetor = malloc((i*TAM+1)*sizeof(int));
        ordem_aleatoria(vetor, i*TAM);
        start = clock();
        InsertSort(vetor, i*TAM);
        end = clock();
        printf("O tempo com %d valores foi -> %.3f segundos\n", i*TAM, (float)(end-start)/CLOCKS_PER_SEC);
        free(vetor);
    }
    return 0;
=======
    int vetor[TAM+1];
    clock_t resultados[21];

    ordem_crescente(vetor, TAM);
    ordem_aleatoria(vetor, TAM);
    printf("\t\tSELECT SORT\n");
    SelectSort(vetor, TAM, resultados);

    ImprimirResultados(resultados);
    ordem_aleatoria(vetor, TAM);
    printf("\n\n\t\tINSERT SORT\n");
    InsertSort(vetor, TAM, resultados);
    ImprimirResultados(resultados);


>>>>>>> origin/master
}

void MedirVetorCrescente(int *vet, int n){
    ordem_crescente(vet, n);
    printf("Tempo para Vetor CRESCENTE:\n");
    printf("\tAlgoritmo de Insercao:\n");
    printf("\tAlgoritmo de Selecao:\n");
    printf("\tAlgoritmo de Insercao:\n");
    printf("\tAlgoritmo de Shell:\n");
    printf("\tAlgoritmo de Quick:\n");
    printf("\tAlgoritmo de Heap:\n");
    printf("\tAlgoritmo de Merge:\n");
}

void ImprimirResultados(clock_t *resultados){
    int i;
    for (i = 1; i <= 20; i++){
        printf("\n(%2d) i = %6d -> %2.2fs", i, i*5000, (float)resultados[i]/CLOCKS_PER_SEC);
    }
}
