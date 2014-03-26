#ifndef SUFFIXTRIE_H_
#define SUFFIXTRIE_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct nodo
{
	char caractere;
	struct nodo *prox, *filho;
};
struct palindromo
{
	char *palavra;
	int tamanho;
	struct palindromo *prox;
};
struct nodo * iterativo(struct nodo *raiz, char *str);
//insere de modo iterativo;
struct nodo * insere(char *str, struct nodo *raiz);
//insere na arvore de sufixo

struct nodo * busca(struct nodo *raiz, char *str, int *nchar, char *bufferstr, int *maior, struct palindromo *lista);
//busca os palindromos
struct nodo * printTree(struct nodo *raiz);
//Imprime a arvore

struct palindromo * inserelista(char *str, struct palindromo *first, int *nchar);
//Faz uma lista encadeada com os resutados.

#endif
