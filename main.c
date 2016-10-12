#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ArrayCreator.h"
#include "Ordenacao.h"
#define TAM 5000 //o vetor tem que ser declarado com TAM+1, dentro das funções é chamado com TAM normalmente

void MedirSelectSort(FILE *);

int main()
{
    FILE *ff;

    ff = fopen("resposta.txt", "w");

    MedirSelectSort(ff);

    fclose(ff);
    return 0;

}



void ImprimirResultados(clock_t *resultados){
    int i;
    for (i = 1; i <= 20; i++){
        printf("\n(%2d) i = %6d -> %2.2fs", i, i*5000, (float)resultados[i]/CLOCKS_PER_SEC);
    }
}

void MedirSelectSort(FILE *ff){
    int i, j;
    int *vetor;
    clock_t start, end, resultados[21];

    fprintf(ff, "--METODO DE SELECAO--\n");
    printf("--METODO DE SELECAO--\n");
    fprintf(ff, "\tOrdem Crescente:\n");
    printf("\tOrdem Crescente:\n");
    for(i=1; i<=20; i++){
        vetor = (int*)malloc((i*TAM+1)*sizeof(int));
        ordem_crescente(vetor, i*TAM);
        start = clock();
        SelectSort(vetor, i*TAM);
        end = clock();
        resultados[i] = end - start;
        fprintf(ff, "\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC);
        printf("\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC);
        free(vetor);
    }
    fprintf(ff, "\n\tOrdem Decrescente:\n");
    printf("\n\tOrdem Decrescente:\n");
    for(i=1; i<=20; i++){
        vetor = (int*)malloc((i*TAM+1)*sizeof(int));
        ordem_decrescente(vetor, i*TAM);
        start = clock();
        SelectSort(vetor, i*TAM);
        end = clock();
        resultados[i] = end - start;
        fprintf(ff, "\t\tO tempo com %6d valores foi -> %2.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC);
        printf("\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC);
        free(vetor);
    }

    for(i=1; i<=20;i++)
        resultados[i] = 0;

    fprintf(ff, "\n\tOrdem Aleatoria:\n");
    printf("\n\tOrdem Aleatoria:\n");
    for(i=1; i<=20; i++){
        vetor = (int*)malloc((i*TAM+1)*sizeof(int));
        for(j=1; j<=10;j++){
            ordem_aleatoria(vetor, i*TAM);
            start = clock();
            SelectSort(vetor, i*TAM);
            end = clock();
            resultados[i] += end - start;
        }
        fprintf(ff, "\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC/10);
        printf("\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC/10);
        free(vetor);
    }
}
