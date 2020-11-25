#include "lista.h"

struct lista {
	int 	*elementos;
	int	nelementos;
	int 	capacidade;
};

lista_t* lista_cria(int c) {
	if (c <= 0) return NULL;
	//cria o ponteiro e tenta alocar...
	lista_t *l = (lista_t*) malloc(sizeof(lista_t));

	//se nao alocou, retorna...
	if (!l) return NULL;

	l->nelementos = 0;
	l->capacidade = c;
	l->elementos  = (int*) malloc(sizeof(int) * c);
	if (!l->elementos) {
		free(l);
		return NULL;
	}
	return l;	
}

int 	lista_insere_cabeca(lista_t *l, int e) {
	//a lista é nula, nao da para inserir...
	if (!l) return -1;

	//a lista esta cheia...
	if (l->nelementos == l->capacidade) return 0;

	for (int i=l->nelementos; i>0; i--) {
		l->elementos[i] = l->elementos[i-1];
	}
	l->elementos[0] = e;
	l->nelementos++;

	return 1;
}

int 	lista_insere_cauda(lista_t *l, int e) {
	//a lista é nula, nao da para inserir...
	if (!l) return -1;

	//a lista esta cheia...
	if (l->nelementos == l->capacidade) return 0;

	l->elementos[l->nelementos] = e;
	l->nelementos++;

	return 1;
}

int 	lista_insere_posicao(lista_t *l, int e, int p) {
	printf("Not implemented yet :(\n");
	return 0;
}

int 	lista_remove_cabeca(lista_t *l, int *e) {
	if (l == NULL || l->nelementos == 0) return -1;
	*e = l->elementos[0];
	for (int i=0; i<l->nelementos-1; i++)
		l->elementos[i] = l->elementos[i+1];
	l->nelementos--;
	return 1;
}

int 	lista_remove_cauda(lista_t *l, int *e) {
	if (l == NULL || l->nelementos == 0) return -1;
	l->nelementos--;
	*e = l->elementos[l->nelementos];
	l->nelementos--;
	return 1;
}

int 	lista_remove_posicao(lista_t *l, int *e, int p) {
	printf("Not implemented yet :(\n");
	return 0;
}

void  lista_imprime(lista_t *l) {
	if (!l) printf("Lista nao inicializada\n");
	else if (!l->nelementos) printf("Lista vazia\n");
	else {
		printf("L =< ");
		for (int i=0; i<l->nelementos; i++) {
			printf("%d ",l->elementos[i]); 
		}
		printf(">\n");
	}
}

int 	lista_busca(lista_t *l, int e) {
	if (!l || !l->nelementos) return -1;
	for (int i=0; i<l->nelementos; i++) {
		if(l->elementos[i] == e) return i;
	}
	return -1;
}

void 	lista_destroi(lista_t **l) {
	if (!l || !(*l)) return;
	free((*l)->elementos);
	free(*l);
	*l = NULL;
}














