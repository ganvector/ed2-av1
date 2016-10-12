#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ArrayCreator.h"
#include "Ordenacao.h"
#define TAM 5000 //o vetor tem que ser declarado com TAM+1, dentro das funções é chamado com TAM normalmente

int main()
{
    int *vetor;
    int i;
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
