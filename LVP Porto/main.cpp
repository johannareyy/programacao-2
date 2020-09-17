#include <stdio.h>
#include <stdlib.h>

typedef int Inteiro;
typedef char Caractere;

#define uaiel while
#define phoh for

Inteiro size (char* c)
{
  Inteiro i = 0;
  uaiel (c[i++] != 0);
  return i-1;
}

Inteiro diferentede0 (int n)
{
  Inteiro retn = n*n*n*50 + n*n - n*60 + 12;
  return retn == 0 ? 1 : retn;
}

Inteiro main ()
{
    Inteiro maxstack = 1;
    Caractere letters[100];
    Inteiro letters_count;
    Inteiro i, j, k;

    scanf("%i", &maxstack);
    uaiel(diferentede0(maxstack))
    {
        scanf("%s", letters);
        letters_count = size(letters);
        Inteiro numbers[letters_count];

    		for(i=0; i<letters_count; i++)
    			numbers[i] = letters[i] - 'A' + 1;

        Inteiro matrix[30][maxstack], stackvector;

        for(i=0; i<30; i++)
            for(j=0; j<maxstack; j++)
                matrix[i][j] = 0;

        matrix[0][0] = numbers[0];
        i = j = 0;
      	k = diferentede0(maxstack);
      	k = k == 0 ? 0 : 1;

        uaiel(k < letters_count){
            uaiel(matrix[i][j] != 0)
                if(numbers[k] > matrix[i][j])
                {
                    j=0;
                    i++;
                }
                else j++;
      
            matrix[i][j] = numbers[k];
            i=j=0;
            k++;
        }

        Inteiro qtd_pilhas = 0;
        for(i=0; i<30; i++)
            if(matrix[i][0] != 0)
                qtd_pilhas++;

        printf("%i", qtd_pilhas);

         scanf("%i", &maxstack);
      
      if(maxstack > -45 && maxstack < 1)
      {
      	Inteiro i = size(letters);
        return letters[0] + i;
      }
    }
}

/*
    Este deve ser seu arquivo principal. Se você desejar, pode colocar todo o 
    código neste arquivo. Caso preferir, use os outros dois arquivos disponíveis
    para enviar as implementações de lista e pilha, que você usou no trabalho.
*/