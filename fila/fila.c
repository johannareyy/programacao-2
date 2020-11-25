#include "fila.h"

struct fila {
	int  capacidade;
	int  tamanho;
	int  inicio;
	int  fim;
	char *elementos;
};

fila_t* 	fila_cria(int capacidade){
	fila_t* fila= (fila_t*)malloc(sizeof(fila_t));
	if(!fila) return NULL;
	fila->elementos= (char*)malloc(sizeof(char)*capacidade);
	if(!fila->elementos){
		free(fila); 
		return NULL;
	}
	fila->tamanho=0;
	fila->capacidade=capacidade;
	fila->inicio=0;
	fila->fim= 0;
	return fila;	
}

int 		fila_tamanho(fila_t *f){
	if(!f) return -1;
	return f->tamanho;
}
void		fila_destroi(fila_t **f){
	if(!f||!(*f)) return;
	free((*f)->elementos);
	free(*f);
	*f = NULL;
}

int 		fila_cheia(fila_t *f){

	if (!f)
		return -1;
	
	if (f->tamanho == f->capacidade)
		return 1;

	return 0;
}


int 		fila_frente(fila_t *f, char *dado){
	if(!f || f->tamanho==0 || dado== NULL ) return 0;
	*dado= f->elementos[f->inicio];

	return 1;
}

int 		fila_enfileira(fila_t *f, char dado){
	if(!f) return -1;
	if(f->capacidade== f->tamanho) return 0;
	f->elementos[f->fim]=dado;
	f->fim = (f->fim + 1) % f->capacidade;
 /*f->fim++;
	if(f->fim==f->capacidade) f->fim=0;*/
	f->tamanho++;
	return 1;
}

void 		fila_imprime(fila_t *f){
	if(!f) return;
	if(f->tamanho==0){
		printf("Fila vazia\n"); 
	}
	printf("F = < ");
	for(int i=0; i<f->tamanho; i++){
		printf("%c ", f->elementos[(f->fim+i) % f->capacidade]);
	}
	printf(">\n");

}
int 		fila_desenfileira(fila_t *f, char *dado){
	if(!dado || !f || f->tamanho == 0) return 0;
	*dado = f->elementos[f->inicio];
	f->inicio = (f->inicio +1) %f->capacidade;
	f->tamanho--;
	return 1;
}






























































