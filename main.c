#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ArrayCreator.h"
#include "Ordenacao.h"
#define TAM 10 //o vetor tem que ser declarado com TAM+1, dentro das funções é chamado com TAM normalmente

int main()
{
    clock_t start, end;
    int i;
    int vetor[TAM+1];
    int vetor2[9] = {0, 12, 43, 1, 6, 56, 23, 52, 9};
    clock_t resultados[21];

    ordem_crescente(vetor, TAM);
    ordem_aleatoria(vetor, TAM);

    ShellSort(vetor2, 8);

    ImprimirResultados(resultados);



    printf("\n\n%.2f, %.2f", (float)start, (float)end);
    printf("\nTotal = %.2f", (float)(end - start)/CLOCKS_PER_SEC);
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
