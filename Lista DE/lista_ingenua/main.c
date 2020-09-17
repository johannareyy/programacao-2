#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {

	lista_t *l = lista_cria(20);

	for (int i=0; i<5; i++) {
		lista_insere_cauda(l,i*i);
		lista_insere_cabeca(l,i+10);
		lista_imprime(l);
	}

	int valor;
	lista_remove_cabeca(l,&valor);
	printf("Removeu %d\n",valor);
	lista_imprime(l);

	valor = lista_busca(l,0);
	if (valor == -1)
		printf("Nao achou :(\n");
	else 
	printf("Achou na posicao %d.\n",valor);

	//se nao chamar deve ter vazado 96bytes em 2 blocos
	//1 bloco de 16bytes e outro de 80bytes...
	lista_destroi(&l);

	return 0;
}








