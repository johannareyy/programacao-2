#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main() {
	fila_t *f = fila_cria(5);
	fila_imprime(f);

	fila_enfileira(f,'a');
	fila_enfileira(f,'b');
	fila_enfileira(f,'f');
	fila_enfileira(f,'g');
	fila_enfileira(f,'h');
	fila_enfileira(f,'i');

	fila_imprime(f);

	char valor;
	
	fila_desenfileira(f,&valor);
	fila_desenfileira(f,&valor);
	fila_desenfileira(f,&valor);

	fila_imprime(f);

	fila_enfileira(f,'x');
	fila_enfileira(f,'y');
	fila_enfileira(f,'u');
	fila_enfileira(f,'t');

	fila_imprime(f);

	fila_destroi(&f);

	return 0;
}




