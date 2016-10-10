#include <time.h>
#include "Ordenacao.h"
#define CAP 5000

void SelectSort(int *vet, int n, clock_t *resultados){
    int i, j, min;
    int aux;
    clock_t start, end;

    start = clock();
    for (i=1; i <= n - 1; i++, end = clock()){
        min = i;
        for (j = i + 1; j <= n; j++)
            if(vet[j] < vet[min])
                min = j;
        aux = vet[min];
        vet[min] = vet[i];
        vet[i] = aux;
        if(i%CAP == 0){
            resultados[i/CAP] = end;
        }
    }
    resultados[(i+1)/CAP] = end = clock();
}

void InsertSort(int *vet, int n, clock_t *resultados){
    int i, j;
    int aux;
    clock_t start, end;

    start = clock();
    for(i=2; i<= n; i++, end = clock()){
        aux = vet[i];
        j = i - 1;
        vet[0] = aux;
        while(aux < vet[j]){
            vet[j+1] = vet[j];
            j--;
        }
        vet[j+1] = aux;
        if(i%CAP == 0){
            resultados[i/CAP] = end;
        }
    }
    resultados[(i+1)/CAP] = end;
}

void BubbleSort(int *vet, int n, clock_t *resultados){
    int i, j;
    int aux;
    clock_t start, end;

    start = clock();
    for(i = n; i >= 2; i--, end = clock()){
        for (j = 2; j <= i; j++)
        if(vet[j] < vet[j-1]){
            aux = vet[j];
            vet[j] = vet[j-1];
            vet[j-1] = aux;
        }
        if(i%CAP == 0){
            resultados[i/CAP] = end;
        }
    }
    resultados[(i+1)/CAP] = end;
}

void MergeSort(int *vet, int n, clock_t *resultados){
    MSort(1, n, vet, resultados);
}

void MSort(int ini, int fim, int *vet, clock_t *resultados){
    int i, j, k, meio;
    int *aux;

    if (ini<fim){
        meio = (ini + fim) / 2;
        MSort(ini, meio, vet, resultados);
        MSort(meio + 1, fim, vet, resultados);
        Merge(vet, ini, meio, fim, resultados);
    }
}

void Merge(int *vet, int ini, int meio, int fim, clock_t *resultados){
    int i = ini, j = meio + 1, k = 0;
    clock_t start, end;
    int *aux = (int*)malloc(sizeof(int)*(fim-ini + 1));

    start = clock();
    while ((i < meio + 1)||(j < fim + 1)){
        if(i == meio + 1){
            aux[k] = vet[j];
            j++;
            k++;
        }
        else{
            if(j == fim + 1){
                aux[k] = vet[i];
                i++;
                k++;
            }
            else{
                if(vet[i]<vet[j]){
                    aux[k] = vet[i];
                    i++;
                    k++;
                }
                else{
                    aux[k] = vet[j];
                    j++;
                    k++;
                }
            }
        }
    }

    for(i=ini; i<=fim; i++){
        vet[i] = aux[i-ini];
    }

    free(aux);
}

void ShellSort(int *vet, int n){
    int i, j, h = 1;
    int item;

    do
        h = h * 3 + 1;
    while (h < n);

    do{
        h /= 3;
        for(i = h + 1; i <= n; i++){
            item = vet[i];
            j = i;
            while(vet[j - h] > item){
                vet[j] = vet[j - h];
                j -= h;
                if (j <= h)
                    break;
            }
            vet[j] = item;
        }

    }while(h != 1);
}

void Partition(int esq, int dir, int *i, int *j, int *vet){
    int pivo, item;

    *i = esq;
    *j = dir;
    pivo = vet[(*i + *j)/2];

    do{
        while(pivo > vet[*i])
            (*i)++;
        while(pivo < vet[*j])
            (*j)--;

        if(*i <= *j){
            item = vet[*i];
            vet[*i] = vet[*j];
            vet[*j] = item;
            (*i)++;
            (*j)--;
        }
    }while(*i <= *j);
}

void QSort(int esq, int dir, int *vet){
    int i, j;

    Partition(esq, dir, &i, &j, vet);
    if(esq < j){
        QSort(esq, j, vet);
    }
    if(i < dir){
        QSort(i, dir, vet);
    }
}

void QuickSort(int *vet, int n){
    QSort(1, n, vet);
}

void Construct(int *vet, int n){
    int esq;

    esq = n / 2 + 1;
    while(esq > 1){
        esq--;
        Reconstruct(esq, n, vet);
    }
}

void Reconstruct(int esq, int dir, int *vet){
    int j, i = esq;
    int item;

    j = i * 2;
    item = vet[i];
    while(j <= dir){
        if(j < dir){
            if(vet[j] < vet[j+1]){
                j++;
            }
        }
        if (item >= vet[j]){
            break;
        }else{
            vet[i] = vet[j];
            i = j;
            j = i * 2;
        }
        vet[i] = item;
    }
}

void HeapSort(int *vet, int n){
    int esq, dir;
    int item;

    Construct(vet, n);
    esq = 1;
    dir = n;

    while(dir > 1){
        item = vet[1];
        vet[1] = vet[dir];
        vet[dir] = item;
        dir--;
        Reconstruct(esq, dir, vet);
    }
}
