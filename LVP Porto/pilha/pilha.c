#include "pilha.h"

struct no {
	int 		 info;	
	struct no *prx;
};

struct pilha {
	struct no *topo;
	int 	tamanho;
};

pilha_t* pilha_cria() {
	pilha_t *p = (pilha_t*) malloc(sizeof(pilha_t));
	if (!p) return NULL;
	p->tamanho = 0;
	p->topo = NULL;
	return p;
}

void     pilha_destroi(pilha_t **p) {
	if (!p || !(*p)) return;

	int lixo;
	while((*p)->tamanho != 0)
		pilha_desempilha((*p),&lixo);
	free(*p);
	*p = NULL;
}

int 		pilha_empilha(pilha_t *p, int dado) {
	if (!p) return 0;
	no_t *nn = (no_t*) malloc(sizeof(no_t));
	if (!nn) return 0;
	nn->info = dado;
	nn->prx = p->topo;
	p->topo = nn;
	p->tamanho++;
	return 1;
}

int 		pilha_contem(pilha_t *p, int dado) {
	if (!p || p->tamanho == 0) return 0;
	no_t *aux = p->topo;
	while (aux) {
		if (aux->info == dado) return 1;
		aux = aux->prx;
	}
	return 0;
}

int 		pilha_desempilha(pilha_t *p, int *dado) {
	if (!p || p->tamanho == 0 || !dado) return 0;
	*dado = p->topo->info;
	no_t *aux = p->topo;
	p->topo = p->topo->prx;
	free(aux);
	p->tamanho--;
	return 1;
}

int 		pilha_topo(pilha_t *p, int *dado) {
	if (!p || p->tamanho == 0 || !dado) return 0;
	*dado = p->topo->info;
	return 1;
}

int		pilha_tamanho(pilha_t *p) {
	if (!p) return -1;
	return p->tamanho;
}
