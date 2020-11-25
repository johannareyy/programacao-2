#include "lista.h"

struct no {
	int 			dado;
	struct no 	*prox;
};

struct lista {
	no_t *primeiro;	
	int 	nelementos;
};	

lista_t* lista_cria() {
	lista_t *l = (lista_t*) malloc(sizeof(lista_t));
	if (!l) return NULL;
	l->nelementos = 0;
	l->primeiro = NULL;
	return l;
}

int 	lista_insere_cabeca(lista_t *l, int e) {
	if (!l) return 0;
	no_t *n = (no_t*) malloc(sizeof(no_t));
	if (!n) return 0;
	n->dado = e;
	n->prox = l->primeiro;
	l->primeiro = n;
	l->nelementos++;
	return 1;	
}

int 	lista_insere_cauda(lista_t *l, int e) {
	if (!l) return 0;
	
//	if (l->nelementos == 0) 
//		return lista_insere_cabeca(l,e);

	no_t *n = (no_t*) malloc(sizeof(no_t));
	if (!n) return 0;
	n->dado = e;
	n->prox = NULL;

	no_t *aux = l->primeiro;
	while(aux != NULL && aux->prox != NULL)
		aux = aux->prox;
	
	if (aux == NULL)
		l->primeiro = n;
	else
		aux->prox = n;
	l->nelementos++;
	return 1;
}

int 	lista_remove_cabeca(lista_t *l, int *e) {
	if (!l || !l->primeiro) return 0;
	no_t *aux = l->primeiro;
	l->primeiro = l->primeiro->prox;
	*e = aux->dado;
	free(aux);
	l->nelementos--;
	return 1;
}

int 	lista_remove_cauda(lista_t *l, int *e) {
	if (!l || !l->primeiro) return 0;
//	if (l->nelementos == 1) Opção 1 - para 1 elemento
//		return lista_remove_cabeca(l,e);
	no_t *aux = l->primeiro;
	
/*	if (aux->prox == NULL) { Opção 2 - para 1 elemento
		*e = aux->dado;
		free(aux);
		l->primeiro = NULL;
		l->nelementos--;
		return 1;
	}*/
	
	while(aux->prox != NULL && aux->prox->prox != NULL)
		aux = aux->prox;

	if (aux->prox == NULL) {
		*e = aux->dado;
		free(aux);
		l->primeiro = NULL;

	} else {
		*e = aux->prox->dado;
		free(aux->prox);
		aux->prox = NULL;
	}
	l->nelementos--;
	return 1;
}

void  lista_imprime(lista_t *l) {
	if (!l) {
		printf("Lista nao inicializada\n");
	} else {
		if (!l->nelementos) {
			printf("L = <>\n");
		} else {
			no_t *aux = l->primeiro;
			printf("L = < ");
			while (aux != NULL) {
				printf("%d ", aux->dado);
				aux = aux->prox;
			}
			printf(">\n");
		}
	}
}

int 	lista_busca(lista_t *l, int e) {
	if (!l || l->nelementos == 0) return -1;
	
	no_t *aux = l->primeiro;
	while (aux != NULL && aux->dado != e)
		aux = aux->prox;

	if (aux == NULL)
		return -1;
	return 1;
}

void 	lista_destroi(lista_t **l) {
	if (!l || !*l) return;

	no_t *aux;
	while(!(*l)->primeiro) {
		aux = (*l)->primeiro;
		(*l)->primeiro = (*l)->primeiro->prox;
		free(aux);
	}
	free(*l);
	*l = NULL;
}

/* Versao 1
void 	lista_destroi(lista_t **l) {
	if (!l || !*l) return;
	
	int lixo;	

	while((*l)->nelementos != 0)
		lista_remove_cabeca(*l,&lixo);
	free(*l);
	*l = NULL;
}*/















