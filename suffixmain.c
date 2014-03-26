#include "suffixtrie.h"

int main()
{
	char *str, *reverse, *auxforward, *auxreverse, *strbuffer;
	int i=0,nchar=0,maior=1;
	struct nodo *raiz = NULL;
	
	struct palindromo *lista=NULL;
	
	str = malloc(100000 * sizeof(char));
	
	
	scanf("%s",str);
	
	reverse = malloc(strlen(str) *sizeof(char));
	
	str = strncat(str,"$",1);
	
	i = strlen(str);
	
	auxforward = str;		
	
	while(i > 0)
	{
		raiz = insere(str,raiz); //(raiz, str);
		str++;
		i = strlen(str);
	}

	i = strlen(auxforward);	
	
	auxreverse = reverse;
	
	while(i >= 0) //inverte a string
	{
		str--;
		*reverse = *str;
		reverse++;
		i--;
	}
	i = strlen(str);
	
	free(auxforward);
	
	reverse = auxreverse;
	reverse[i-1] = '\0';
		
	i=strlen(reverse);
	
	strbuffer = malloc(sizeof(char));
	
	lista = malloc(sizeof(struct palindromo));
	lista->palavra = NULL;
	lista->prox = NULL;
	
	while(i > 0)
	{
		nchar=0;
		reverse++;
		raiz = busca(raiz,reverse,&nchar,strbuffer,&maior,lista);
		i = strlen(reverse);
	}
	while(lista!=NULL)
	{
		if(maior == lista->tamanho)
			printf("%s \n", lista->palavra);
		lista = lista->prox;
	}

	//printTree(raiz);

	return 0;
}
