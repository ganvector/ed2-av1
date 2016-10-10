#include "ArrayCreator.h"

void ordem_crescente(int *vet, int tamanho){
	int i;
	for (i=0; i <= tamanho; i++){
		vet[i] = i;
	}
}

void ordem_decrescente(int *vet, int tamanho){
	int i;
	for (i=0; i <= tamanho; i++){
		vet[i] = (tamanho + 1) - i;
	}
}

void trocar(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void ordem_aleatoria(int *vet, int tamanho){
    int i, j;
    srand((unsigned)time(NULL));

    for (i = tamanho; i > 0; i--){
        int j = 1 + (rand() % (i + 1));

        trocar(&vet[i], &vet[j]);
    }
}
