#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {

	lista_t *l = lista_cria();

	for (int i=0; i<5; i++) {
		lista_insere_cauda(l,i*i);
		lista_insere_cabeca(l,i+10);
		lista_imprime(l);
	}

	int valor;
	lista_remove_cabeca(l,&valor);
	printf("Removeu %d\n",valor);
	lista_imprime(l);

/*	while(lista_remove_cauda(l,&valor)) {
		printf("Removeu %d\n",valor);
		lista_imprime(l);
	}*/

	valor = lista_busca(l,15);
	if (valor == -1)
		printf("Nao achou :(\n");
	else 
	printf("Achou na posicao %d.\n",valor);

	lista_destroi(&l);

	return 0;
}








