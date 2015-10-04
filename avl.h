#define AVL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _arvore{
	struct _nodo *root;
	int h;
}TpArvore;

typedef struct _nodo{
	char* info;
	int fat_b;
	struct _nodo *pai;
	struct _nodo *esq;
	struct _nodo *dir;
}TpNodo;

/* 1. Função para inserção de nodos em uma AVL que armazene números inteiros. */
TpNodo* inserir(char *palavra, TpNodo* root, TpArvore* tree);

// funcao que retorna TpNodo desbalanceado - fat_b > 1 ou < -1
TpNodo *busca_nodo_desbalanceado(TpNodo* root);

// Função para criação de árvore
TpArvore* criaArvoreVazia(); // retorna um nodo NULL, a raiz da arvore

// Função para criação de nodo
TpNodo* criaNodo(char *palavra);

// Função que pede o valor a ser inserido na árvore
//char* palavra();

// Função para imprimir a árvore
void imprimir(TpNodo* root);

// Função que calcula a altura da árvore
int altura(TpNodo* root);

// Função que calcula o fator de balanceamento de um nó 
void calcula_fator(TpNodo* root);

// rotacoes
void rotacaoSimplesDireita(TpArvore *AVL, TpNodo *desb);
void rotacaoSimplesEsquerda(TpArvore *AVL, TpNodo *desb);
void rotacaoDuplaDireita(TpArvore *AVL, TpNodo *desb);
void rotacaoDuplaEsquerda(TpArvore *AVL, TpNodo *desb);

