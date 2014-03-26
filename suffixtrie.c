#include "suffixtrie.h"

struct nodo * insere(char *str, struct nodo *raiz)
{
	struct nodo *new;
	
	if(*(str)!='\0')
	{
		if(raiz==NULL || raiz->caractere != *(str) )
		{
			if(raiz == NULL || raiz->caractere >  *(str) ) //Se não existe o caractere no nivel
			{											  //cria um novo nodo com o caractere no nivel					
				 if(!(new = malloc( sizeof (struct nodo) )))
				 {
					 return raiz;
				 }
				 new->caractere = *str;
				 new->prox = raiz; //insere o proximo valido ou null (que eh a raiz se for o ultimo do nivel)
				 new->filho = NULL;
				 str++;
				 new->filho = insere(str, new->filho); 
				 return new;
			}
			else
			{
				raiz->prox = insere(str, raiz->prox); //Verifica se existe o caractere no nivel
				return raiz;
			}
		}
		
		else //o nodo e o caractere coincidem
		{
			str++;
			raiz->filho = insere(str, raiz->filho); //Manda o proximo caractere para o nivel debaixo
			return raiz;
		}
			
	}
	return raiz;
}

struct nodo * busca(struct nodo *raiz, char *str, int *nchar, char *strbuffer, int *maior, struct palindromo *lista)
{
	int temp;

	if(raiz!=NULL)
	{
		if(raiz->caractere == *str)
		{
			strbuffer = realloc(strbuffer,1+(*nchar)*sizeof(char));
			strbuffer[*nchar] = raiz->caractere;
			(*nchar)++;
			str++;
			raiz->filho = busca(raiz->filho,str,nchar,strbuffer,maior,lista);
		}
		else if(raiz->caractere < *str)
		{
			raiz->prox = busca(raiz->prox,str,nchar,strbuffer,maior,lista);
		}
		else if(*nchar >= *maior)
		{
			*maior = *nchar;
			strbuffer = realloc(strbuffer,1+(*nchar)*sizeof(char));
			strbuffer[*nchar] = '\0';
			
			if(*strbuffer == strbuffer[*nchar-1])
			{
				lista = inserelista(strbuffer,lista,nchar);
			}
		}
		
	}
	else if(*nchar >= *maior)
	{
		*maior = *nchar;
		strbuffer = realloc(strbuffer,1+(*nchar)*sizeof(char));
		strbuffer[*nchar] = '\0';
		if(*strbuffer == strbuffer[*nchar-1])
		{
			lista = inserelista(strbuffer,lista,nchar);
		}
		
	}
	return raiz;
}

struct palindromo * inserelista(char *str, struct palindromo *first, int *nchar)
{
	struct palindromo *new;
	//printf("%s\n",str);
	if(first==NULL)
	{
		first = malloc(sizeof(struct palindromo));
		first->palavra = NULL;
		first->prox = NULL;
		first->tamanho = 0;
	}
	if(first->palavra == NULL)
	{
		first->tamanho = (int) *nchar;
		first->palavra = malloc(*nchar * sizeof(char));
		strcpy(first->palavra,str);
	}
	else
	{
		first->prox = inserelista(str,first->prox,nchar);
	}
	
	
	return first;
}

struct nodo * printTree(struct nodo *raiz)
{
	if(raiz!=NULL)
	{
		printf("%p - %c   - %p - %p\n",raiz, raiz->caractere, raiz->prox, raiz->filho);
		if(raiz->filho!=NULL)
		{
			raiz->filho = printTree(raiz->filho);
		}
		if(raiz->prox!=NULL)
		{
			raiz->prox = printTree(raiz->prox);
		}
	}
	return raiz;
}




