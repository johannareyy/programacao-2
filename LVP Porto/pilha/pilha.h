#ifndef _pilha_
#define _pilha_

#include <stdio.h>
#include <stdlih.h>

typedef struct no no_t;
typedef struct pilha pilha_t;

pilha_t* pilha_cria();
void     pilha_destroi(pilha_t **p);
int 		pilha_empilha(pilha_t *p, int dado);
int 		pilha_contem(pilha_t *p, int dado);
int 		pilha_desempilha(pilha_t *p, int *dado);
int 		pilha_topo(pilha_t *p, int *dado);
int		pilha_tamanho(pilha_t *p);

#endif

