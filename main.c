#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "ArrayCreator.h"
#include "Ordenacao.h"
#define TAM 5000 //o vetor tem que ser declarado com TAM+1, dentro das funções é chamado com TAM normalmente

void MedirSelectSort(FILE *, bool);
void MedirInsertSort(FILE *, bool);
void MedirBubbleSort(FILE *, bool);
void MedirShellSort(FILE *, bool);
void MedirQuickSort(FILE *, bool);
void MedirHeapSort(FILE *, bool);
void MedirMergeSort(FILE*, bool);


int main()
{
    FILE *ff;

    ff = fopen("resposta.txt", "w");
    for(;;){
        system("cls");
        switch(menu()){
            case 0:
                return 0;
            case 1:
                MedirInsertSort(ff, false);
                system("pause");
                break;
            case 2:
                MedirSelectSort(ff, false);
                system("pause");
                break;
            case 3:
                MedirBubbleSort(ff, false);
                system("pause");
                break;
            case 4:
                MedirShellSort(ff, false);
                system("pause");
                break;
            case 5:
                MedirQuickSort(ff, false);
                system("pause");
                break;
            case 6:
                MedirHeapSort(ff, false);
                system("pause");
                break;
            case 7:
                MedirMergeSort(ff, false);
                system("pause");
                break;
            case 8:
                MedirInsertSort(ff, true);
                MedirSelectSort(ff, true);
                MedirBubbleSort(ff, true);
                MedirShellSort(ff, true);
                MedirQuickSort(ff, true);
                MedirHeapSort(ff, true);
                MedirMergeSort(ff, true);
                printf("Relatorio terminado.");
                system("pause");
        }
    }
    fclose(ff);
    return 0;

}

int menu(void){
    int escolha;

    for(;;){
        printf("\t\t\t---MENU---\n\n");
        printf("(1) - Exibir tempos de Insercao\n(2) - Exibir tempos de Selecao\n(3) - Exibir tempos de Bolha\n(4) - Exibir tempos de Shell\n(5) - Exibir tempos de Quick\n(6) - Exibir tempos de Heap\n(7) - Exibir tempos de Merge\n(8) - Gerar Relatorio de tempos em .txt\n(0) - Sair\n");
        printf("\nDigite a opcao desejada -> "); scanf("%d", &escolha);
        if ((escolha >= 0) && (escolha <= 8))
            return escolha;
        else{
            printf("Opcao invalida\n");
            system("pause");
            system("cls");
        }
    }
}

void MedirSelectSort(FILE *ff, bool imprimir){
    int i, j;
    int *vetor;
    clock_t start, end, resultados[21];

    if(imprimir) fprintf(ff, "--METODO DE SELECAO--\n");
    printf("--METODO DE SELECAO--\n");
    if(imprimir) fprintf(ff, "\tOrdem Crescente:\n");

    printf("\tOrdem Crescente:\n");
    for(i=1; i<=20; i++){
        vetor = (int*)malloc((i*TAM+1)*sizeof(int));
        ordem_crescente(vetor, i*TAM);
        start = clock();
        SelectSort(vetor, i*TAM);
        end = clock();
        resultados[i] = end - start;
        if(imprimir) fprintf(ff, "\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC);
        printf("\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC);
        free(vetor);
    }
    if(imprimir) fprintf(ff, "\n\tOrdem Decrescente:\n");

    printf("\n\tOrdem Decrescente:\n");
    for(i=1; i<=20; i++){
        vetor = (int*)malloc((i*TAM+1)*sizeof(int));
        ordem_decrescente(vetor, i*TAM);
        start = clock();
        SelectSort(vetor, i*TAM);
        end = clock();
        resultados[i] = end - start;
        if(imprimir) fprintf(ff, "\t\tO tempo com %6d valores foi -> %2.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC);
        printf("\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC);
        free(vetor);
    }
    //zera o vetor para ser somados mais tarde
    for(i=1; i<=20;i++)
        resultados[i] = 0;

    fprintf(ff, "\n\tOrdem Aleatoria:\n");
    if(imprimir) printf("\n\tOrdem Aleatoria:\n");
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
        if(imprimir) printf("\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC/10);
        free(vetor);
    }
}

void MedirInsertSort(FILE *ff, bool imprimir){
    int i, j;
    int *vetor;
    clock_t start, end, resultados[21];

    if(imprimir) fprintf(ff, "--METODO DE INSERCAO--\n");
    printf("--METODO DE INSERCAO--\n");
    if(imprimir) fprintf(ff, "\tOrdem Crescente:\n");
    printf("\tOrdem Crescente:\n");
    for(i=1; i<=20; i++){
        vetor = (int*)malloc((i*TAM+1)*sizeof(int));
        ordem_crescente(vetor, i*TAM);
        start = clock();
        InsertSort(vetor, i*TAM);
        end = clock();
        resultados[i] = end - start;
        if(imprimir) fprintf(ff, "\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC);
        printf("\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC);
        free(vetor);
    }
    if(imprimir) fprintf(ff, "\n\tOrdem Decrescente:\n");
    printf("\n\tOrdem Decrescente:\n");
    for(i=1; i<=20; i++){
        vetor = (int*)malloc((i*TAM+1)*sizeof(int));
        ordem_decrescente(vetor, i*TAM);
        start = clock();
        InsertSort(vetor, i*TAM);
        end = clock();
        resultados[i] = end - start;
        if(imprimir) fprintf(ff, "\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC);
        printf("\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC);
        free(vetor);
    }

    for(i=1; i<=20;i++)
        resultados[i] = 0;

    if(imprimir) fprintf(ff, "\n\tOrdem Aleatoria:\n");
    printf("\n\tOrdem Aleatoria:\n");
    for(i=1; i<=20; i++){
        vetor = (int*)malloc((i*TAM+1)*sizeof(int));
        for(j=1; j<=10;j++){
            ordem_aleatoria(vetor, i*TAM);
            start = clock();
            InsertSort(vetor, i*TAM);
            end = clock();
            resultados[i] += end - start;
        }
        if(imprimir) fprintf(ff, "\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC/10);
        printf("\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC/10);
        free(vetor);
    }
}

void MedirBubbleSort(FILE *ff, bool imprimir){
    int i, j;
    int *vetor;
    clock_t start, end, resultados[21];

    if(imprimir) fprintf(ff, "--METODO DE BOLHA--\n");
    printf("--METODO DE BOLHA--\n");
    if(imprimir) fprintf(ff, "\tOrdem Crescente:\n");
    printf("\tOrdem Crescente:\n");
    for(i=1; i<=20; i++){
        vetor = (int*)malloc((i*TAM+1)*sizeof(int));
        ordem_crescente(vetor, i*TAM);
        start = clock();
        BubbleSort(vetor, i*TAM);
        end = clock();
        resultados[i] = end - start;
        if(imprimir) fprintf(ff, "\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC);
        printf("\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC);
        free(vetor);
    }
    if(imprimir) fprintf(ff, "\n\tOrdem Decrescente:\n");
    printf("\n\tOrdem Decrescente:\n");
    for(i=1; i<=20; i++){
        vetor = (int*)malloc((i*TAM+1)*sizeof(int));
        ordem_decrescente(vetor, i*TAM);
        start = clock();
        BubbleSort(vetor, i*TAM);
        end = clock();
        resultados[i] = end - start;
        if(imprimir) fprintf(ff, "\t\tO tempo com %6d valores foi -> %2.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC);
        printf("\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC);
        free(vetor);
    }

    for(i=1; i<=20;i++)
        resultados[i] = 0;

    if(imprimir) fprintf(ff, "\n\tOrdem Aleatoria:\n");
    printf("\n\tOrdem Aleatoria:\n");
    for(i=1; i<=20; i++){
        vetor = (int*)malloc((i*TAM+1)*sizeof(int));
        for(j=1; j<=10;j++){
            ordem_aleatoria(vetor, i*TAM);
            start = clock();
            BubbleSort(vetor, i*TAM);
            end = clock();
            resultados[i] += end - start;
        }
        if(imprimir) fprintf(ff, "\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC/10);
        printf("\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC/10);
        free(vetor);
    }
}

void MedirShellSort(FILE *ff, bool imprimir){
    int i, j;
    int *vetor;
    clock_t start, end, resultados[21];

    if(imprimir) fprintf(ff, "--METODO DE SHELL--\n");
    printf("--METODO DE SHELL--\n");
    if(imprimir) fprintf(ff, "\tOrdem Crescente:\n");
    printf("\tOrdem Crescente:\n");
    for(i=1; i<=20; i++){
        vetor = (int*)malloc((i*TAM+1)*sizeof(int));
        ordem_crescente(vetor, i*TAM);
        start = clock();
        ShellSort(vetor, i*TAM);
        end = clock();
        resultados[i] = end - start;
        if(imprimir) fprintf(ff, "\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC);
        printf("\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC);
        free(vetor);
    }
    if(imprimir) fprintf(ff, "\n\tOrdem Decrescente:\n");
    printf("\n\tOrdem Decrescente:\n");
    for(i=1; i<=20; i++){
        vetor = (int*)malloc((i*TAM+1)*sizeof(int));
        ordem_decrescente(vetor, i*TAM);
        start = clock();
        ShellSort(vetor, i*TAM);
        end = clock();
        resultados[i] = end - start;
        if(imprimir) fprintf(ff, "\t\tO tempo com %6d valores foi -> %2.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC);
        printf("\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC);
        free(vetor);
    }

    for(i=1; i<=20;i++)
        resultados[i] = 0;

    if(imprimir) fprintf(ff, "\n\tOrdem Aleatoria:\n");
    printf("\n\tOrdem Aleatoria:\n");
    for(i=1; i<=20; i++){
        vetor = (int*)malloc((i*TAM+1)*sizeof(int));
        for(j=1; j<=10;j++){
            ordem_aleatoria(vetor, i*TAM);
            start = clock();
            ShellSort(vetor, i*TAM);
            end = clock();
            resultados[i] += end - start;
        }
        if(imprimir) fprintf(ff, "\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC/10);
        printf("\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC/10);
        free(vetor);
    }
}

void MedirQuickSort(FILE *ff, bool imprimir){
    int i, j;
    int *vetor;
    clock_t start, end, resultados[21];

    if(imprimir) fprintf(ff, "--METODO DE QUICK--\n");
    printf("--METODO DE QUICK--\n");
    if(imprimir) fprintf(ff, "\tOrdem Crescente:\n");
    printf("\tOrdem Crescente:\n");
    for(i=1; i<=20; i++){
        vetor = (int*)malloc((i*TAM+1)*sizeof(int));
        ordem_crescente(vetor, i*TAM);
        start = clock();
        QuickSort(vetor, i*TAM);
        end = clock();
        resultados[i] = end - start;
        if(imprimir) fprintf(ff, "\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC);
        printf("\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC);
        free(vetor);
    }
    if(imprimir) fprintf(ff, "\n\tOrdem Decrescente:\n");
    printf("\n\tOrdem Decrescente:\n");
    for(i=1; i<=20; i++){
        vetor = (int*)malloc((i*TAM+1)*sizeof(int));
        ordem_decrescente(vetor, i*TAM);
        start = clock();
        QuickSort(vetor, i*TAM);
        end = clock();
        resultados[i] = end - start;
        if(imprimir) fprintf(ff, "\t\tO tempo com %6d valores foi -> %2.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC);
        printf("\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC);
        free(vetor);
    }

    for(i=1; i<=20;i++)
        resultados[i] = 0;

    if(imprimir) fprintf(ff, "\n\tOrdem Aleatoria:\n");
    printf("\n\tOrdem Aleatoria:\n");
    for(i=1; i<=20; i++){
        vetor = (int*)malloc((i*TAM+1)*sizeof(int));
        for(j=1; j<=10;j++){
            ordem_aleatoria(vetor, i*TAM);
            start = clock();
            QuickSort(vetor, i*TAM);
            end = clock();
            resultados[i] += end - start;
        }
        if(imprimir) fprintf(ff, "\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC/10);
        printf("\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC/10);
        free(vetor);
    }
}

void MedirHeapSort(FILE *ff, bool imprimir){
    int i, j;
    int *vetor;
    clock_t start, end, resultados[21];

    if(imprimir) fprintf(ff, "--METODO DE HEAP--\n");
    printf("--METODO DE HEAP--\n");
    if(imprimir) fprintf(ff, "\tOrdem Crescente:\n");
    printf("\tOrdem Crescente:\n");
    for(i=1; i<=20; i++){
        vetor = (int*)malloc((i*TAM+1)*sizeof(int));
        ordem_crescente(vetor, i*TAM);
        start = clock();
        HeapSort(vetor, i*TAM);
        end = clock();
        resultados[i] = end - start;
        if(imprimir) fprintf(ff, "\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC);
        printf("\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC);
        free(vetor);
    }
    if(imprimir) fprintf(ff, "\n\tOrdem Decrescente:\n");
    printf("\n\tOrdem Decrescente:\n");
    for(i=1; i<=20; i++){
        vetor = (int*)malloc((i*TAM+1)*sizeof(int));
        ordem_decrescente(vetor, i*TAM);
        start = clock();
        HeapSort(vetor, i*TAM);
        end = clock();
        resultados[i] = end - start;
        if(imprimir) fprintf(ff, "\t\tO tempo com %6d valores foi -> %2.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC);
        printf("\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC);
        free(vetor);
    }

    for(i=1; i<=20;i++)
        resultados[i] = 0;

    if(imprimir) fprintf(ff, "\n\tOrdem Aleatoria:\n");
    printf("\n\tOrdem Aleatoria:\n");
    for(i=1; i<=20; i++){
        vetor = (int*)malloc((i*TAM+1)*sizeof(int));
        for(j=1; j<=10;j++){
            ordem_aleatoria(vetor, i*TAM);
            start = clock();
            HeapSort(vetor, i*TAM);
            end = clock();
            resultados[i] += end - start;
        }
        if(imprimir) fprintf(ff, "\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC/10);
        printf("\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC/10);
        free(vetor);
    }
}

void MedirMergeSort(FILE *ff, bool imprimir){
    int i, j;
    int *vetor;
    clock_t start, end, resultados[21];

    if(imprimir) fprintf(ff, "--METODO DE MERGE--\n");
    printf("--METODO DE MERGE--\n");
    if(imprimir) fprintf(ff, "\tOrdem Crescente:\n");
    printf("\tOrdem Crescente:\n");
    for(i=1; i<=20; i++){
        vetor = (int*)malloc((i*TAM+1)*sizeof(int));
        ordem_crescente(vetor, i*TAM);
        start = clock();
        MergeSort(vetor, i*TAM);
        end = clock();
        resultados[i] = end - start;
        if(imprimir) fprintf(ff, "\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC);
        printf("\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC);
        free(vetor);
    }
    if(imprimir) fprintf(ff, "\n\tOrdem Decrescente:\n");
    printf("\n\tOrdem Decrescente:\n");
    for(i=1; i<=20; i++){
        vetor = (int*)malloc((i*TAM+1)*sizeof(int));
        ordem_decrescente(vetor, i*TAM);
        start = clock();
        MergeSort(vetor, i*TAM);
        end = clock();
        resultados[i] = end - start;
        if(imprimir) fprintf(ff, "\t\tO tempo com %6d valores foi -> %2.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC);
        printf("\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC);
        free(vetor);
    }

    for(i=1; i<=20;i++)
        resultados[i] = 0;

    if(imprimir) fprintf(ff, "\n\tOrdem Aleatoria:\n");
    printf("\n\tOrdem Aleatoria:\n");
    for(i=1; i<=20; i++){
        vetor = (int*)malloc((i*TAM+1)*sizeof(int));
        for(j=1; j<=10;j++){
            ordem_aleatoria(vetor, i*TAM);
            start = clock();
            MergeSort(vetor, i*TAM);
            end = clock();
            resultados[i] += end - start;
        }
        if(imprimir) fprintf(ff, "\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC/10);
        printf("\t\tO tempo com %6d valores foi -> %.3f segundos\n", i*TAM, (float)resultados[i]/CLOCKS_PER_SEC/10);
        free(vetor);
    }
}
