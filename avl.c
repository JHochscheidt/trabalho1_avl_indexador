#include "avl.h"

// retorna o novo nodo inserido
TpNodo* inserir(int chave, TpNodo* root, TpArvore* tree){
	
	if(tree->root == NULL){ // arvore vazia - inserir primeiro nodo
		TpNodo *new = (TpNodo*) malloc(sizeof(TpNodo));
		new->info = chave;
		tree->root = new;
		return new; 
	}else{
		TpNodo *new;
		if(chave < root->info){
			if(root->esq == NULL){ // alocar e inserir nodo lado esquerdo
				new = (TpNodo*) malloc(sizeof(TpNodo));
				new->info = chave;
				new->pai = root;
				root->esq = new;

				TpNodo *desb = new->pai;
				while(desb != NULL){
					calcula_fator(desb);
					if(desb->fat_b == 2 || desb->fat_b == -2){
						// achado o nodo que desbalanceou - fazer rotacao
						break;
					}else{
						desb = desb->pai;
					}
				}
				// foi inserido , entao pode-se fazer o calculo do fator da arvore e verificar desbalanceamento
				if(desb != NULL){
					// desb é o nodo desbalanceado
					puts("// insercao desbalanceou a arvore>>");
					//calcula_fator(aux->esq);
					//calcula_fator(aux->dir);
					if(desb->fat_b == 2){ // rotacao a direita
						puts("rotacao a direita>>");
						if(desb->esq->fat_b == 1){ // rotacao simples
							puts("rotacao simples>>\n");
							rotacaoSimplesDireita(tree, desb);
						}else if(desb->esq->fat_b == -1){ // rotacao dupla
							puts("rotacao dupla>>\n");
							rotacaoDuplaDireita(tree,desb);
						}
					}else if(desb->fat_b == -2){ // rotacao a esquerda
						puts("rotacao a esquerda>>");
						if(desb->dir->fat_b == -1){ // rotacao simples
							puts("rotacao simples>>\n");
							rotacaoSimplesEsquerda(tree, desb);
						}else if(desb->dir->fat_b == 1){ // rotacao dupla
							puts("rotacao dupla>>\n");
							rotacaoDuplaEsquerda(tree,desb);
						}
					}
					calcula_fator(tree->root);
				}
			}else{
				inserir(chave, root->esq, tree);
			}
		}else if(chave > root->info){
			if(root->dir == NULL){ // alocar e inserir nodo lado direito
				new = (TpNodo*) malloc(sizeof(TpNodo));
				new->info = chave;
				new->pai = root;
				root->dir = new;

				/* codigo replicado do if(chave < root->info) */
				TpNodo *desb = new->pai;
				while(desb != NULL){
					calcula_fator(desb);
					if(desb->fat_b == 2 || desb->fat_b == -2){
						// achado o nodo que desbalanceou - fazer rotacao
						break;
					}else{
						desb = desb->pai;
					}
				}
				// foi inserido , entao pode-se fazer o calculo do fator da arvore e verificar desbalanceamento
				if(desb != NULL){
					// desb é o nodo desbalanceado
					puts("// insercao desbalanceou a arvore>>");
					//calcula_fator(aux->esq);
					//calcula_fator(aux->dir);
					if(desb->fat_b == 2){ // rotacao a direita
						puts("rotacao a direita>>");
						if(desb->esq->fat_b == 1){ // rotacao simples
							puts("rotacao simples>>\n");
							rotacaoSimplesDireita(tree, desb);
						}else if(desb->esq->fat_b == -1){ // rotacao dupla
							puts("rotacao dupla>>\n");
							rotacaoDuplaDireita(tree,desb);
						}
					}else if(desb->fat_b == -2){ // rotacao a esquerda
						puts("rotacao a esquerda>>");
						if(desb->dir->fat_b == -1){ // rotacao simples
							puts("rotacao simples>>\n");
							rotacaoSimplesEsquerda(tree, desb);
						}else if(desb->dir->fat_b == 1){ // rotacao dupla
							puts("rotacao dupla>>\n");
							rotacaoDuplaEsquerda(tree,desb);
						}
					}
					calcula_fator(tree->root);
				}		
			}else{
				inserir(chave,root->dir, tree);
			}
		}else{
			// ja existe nodo com esse valor
			puts("\t\tVALOR JA EXISTE NA ARVORE\n\n");
		}
		calcula_fator(tree->root); // acho q aqui garante que ja nao existe mais desbalanceamento apos a insercao
		return new;
	}	
}

// rotacao simples a direita
void rotacaoSimplesDireita(TpArvore *AVL, TpNodo *desb){
	puts("fazendo rotacao simples a direita\n");
	//printf("nodos envolvidos %d %d %d", desb->info, desb->esq->info, desb->esq->esq->info);
	TpNodo *aux;
	aux = desb->esq;
	if(aux->dir){
		desb->esq = aux->dir;
		aux->dir->pai = desb;
	}else{
		desb->esq = NULL;
	}	
	aux->dir = desb;
	
	if(desb->pai == NULL){ // desb é a raiz da arvore
		AVL->root = aux;
		aux->pai = NULL;
	}else{
		if(aux->info < desb->pai->info){ // pai esta a direita de aux
			desb->pai->esq = aux;
		}else if(aux->info > desb->pai->info){ // pai esta a esquerda de aux
			desb->pai->dir = aux;
		}
		aux->pai = desb->pai;
	}
}

// rotacao simples a esquerda
void rotacaoSimplesEsquerda(TpArvore *AVL, TpNodo *desb){
	puts("fazendo rotacao simples a esquerda\n");
	//printf("nodos envolvidos %d %d %d", desb->info, desb->dir->info, desb->dir->dir->info);
	TpNodo *aux;
	aux = desb->dir;

	if(aux->esq != NULL){
		desb->dir = aux->esq;
		aux->esq->pai = desb;
	}else{
		desb->dir = NULL;
	}
	aux->esq = desb;

	if(desb->pai == NULL){ // desb é a raiz da arvore
		AVL->root = aux;
		aux->pai = NULL;
	}else{
		if(aux->info > desb->pai->info){ // pai esta a esquerda de aux
			desb->pai->dir = aux;
		}else if(aux->info < desb->pai->info){ // pai esta a direita de aux
			desb->pai->esq = aux;
		}
		aux->pai = desb->pai;
	}
}

// rotacao dupla direita
void rotacaoDuplaDireita(TpArvore *AVL, TpNodo *desb){
	puts("fazendo rotacao DUPLA a direita\n");
	//printf("nodos envolvidos %d %d %d", desb->info, desb->esq->info, desb->esq->dir->info);
	TpNodo *aux;
	TpNodo *aux2;

	aux = desb->esq;
	aux2 = aux->dir;

	if(aux2->esq != NULL){
		aux->dir = aux2->esq;
		aux2->esq->pai = aux;
		aux2->esq = aux;
	}else{
		aux->dir = NULL;
	}

	aux2->pai = desb;
	if(aux2->info < desb->info){
		desb->esq = aux2;
	}else{
		desb->dir = aux2;
	}
	aux->pai = aux2;
	if(aux->info < aux2->info){
		aux2->esq = aux;
	}else{
		aux->dir = aux;
	}
	rotacaoSimplesDireita(AVL, desb);
	
}

// rotacao dupla esquerda
void rotacaoDuplaEsquerda(TpArvore *AVL, TpNodo *desb){
	puts("fazendo rotacao DUPLA a esquerda\n");
	//printf("nodos envolvidos %d %d %d", desb->info, desb->dir->info, desb->dir->esq->info);
	TpNodo *aux;
	TpNodo *aux2;

	aux = desb->dir;
	aux2 = aux->esq;

	if(aux2->dir != NULL){
		aux->esq = aux2->dir;
		aux2->dir->pai = aux;
		aux2->dir = aux;
		aux->pai = aux2;
	}else{
		aux->esq = NULL;
	}
	aux2->pai = desb;
	if(aux2->info < desb->info){
		desb->esq = aux2;
	}else{
		desb->dir = aux2;
	}
	if(aux->info < aux2->info){
		aux2->esq = aux;
	}else{
		aux->dir = aux;
	}	
	rotacaoSimplesEsquerda(AVL, desb);
	
}

// calcula o fator de balanceamento de um nodo qualquer e retorna se existe nodo com fator desbalanceado
void calcula_fator(TpNodo* root){
	if(!root)
		return; 
	root->fat_b = (altura(root->esq) - altura(root->dir));
	//if(root->fat_b == 2 || root->fat_b == -2)
	//	return root; // nodo está desbalanceado
		
	calcula_fator(root->esq);
	calcula_fator(root->dir);
	
}

// retorna a altura de um nodo qualquer
int altura(TpNodo* root){
	if(!root) return 0;
	int Hd = 0, He = 0;
	Hd = altura(root->dir);
	He = altura(root->esq);
	
	if(He > Hd) return He + 1;
	else return Hd + 1; 
}

// retorna um nodo desbalanceado ou NULL caso nao tenho nodo desbalanceado
TpNodo *busca_nodo_desbalanceado(TpNodo* root){
	if(!root) return NULL; 
	
	else if(root->fat_b < -1 || root->fat_b > 1)
			return root;
	else{
		if(root->esq) return busca_nodo_desbalanceado(root->esq);
		if(root->dir) return busca_nodo_desbalanceado(root->dir);

		return NULL;
	}
}

// retorna um TpArvore com o campo root NULL , a raiz da arvore
TpArvore* criaArvoreVazia(){
	TpArvore *arv = (TpArvore*) malloc(sizeof (TpArvore));
	if(arv){
		arv->root = NULL;
		arv->h = 0;
		//puts("arvore criada com sucesso");
		return arv;
	}
	return NULL;	
}

// aloca nodo e insere informacao, retorna o novo TpNodo
TpNodo* criaNodo(int key){
	TpNodo *new = (TpNodo*) malloc(sizeof(TpNodo));
	new->dir = NULL;
	new->esq = NULL;
	new->pai = NULL;
	new->fat_b = 0;
	new->info = key;
	return new;
}

// retorna valor da entrada padrao
int valor(){
	int valor;
	printf("Informe o valor:\n");
	scanf("%d", &valor);
	return valor;
}

void imprimir(TpNodo* root){
	if(root){
		printf("<");
		imprimir(root->esq);
		printf("([%d]fb%d)", root->info, root->fat_b);
		imprimir(root->dir);
		printf(">");
	}
}




