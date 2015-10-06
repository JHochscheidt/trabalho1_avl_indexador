#include "avl.h"
#include <ctype.h>
// retorna o novo nodo inserido
TpNodo* inserir(char* palavra, TpNodo* root, TpArvore* tree, int arqID, int linhaID){
	if(palavra == NULL) return NULL;
	if(tree->root == NULL){ // arvore vazia - inserir primeiro nodo
		TpNodo *new = criaNodo(palavra);
		if(new != NULL){
			new->info = (char*) malloc(sizeof(char) * ((int)strlen(palavra)));
			strcpy(new->info, palavra);
			tree->root = new;
			insereNodo(new, arqID, linhaID);
			return new;
		}
	}else{
		TpNodo *new;
		int cmp; // pra pegar o resultado do strcmp
		cmp = strcmp(palavra,root->info);
		if(cmp < 0){ // palavra é menor que o root->atual, entao vai pra esquerda
			if(root->esq == NULL){ // alocar e inserir nodo lado esquerdo
				new = (TpNodo*) malloc(sizeof(TpNodo));
				if(new != NULL){
					new->info = (char*) malloc(sizeof(char)*((int)strlen(palavra)));
					strcpy(new->info, palavra);
					new->pai = root;
					root->esq = new;
					insereNodo(new, arqID, linhaID);
				}
				TpNodo *desb = new->pai;
				while(desb != NULL){
					desb->fat_b = (altura(desb->esq) - altura(desb->dir));
					//calcula_fator(desb);
					if(desb->fat_b == 2 || desb->fat_b == -2){
						break;
					}
					desb = desb->pai;
				}
				if(desb != NULL){
					if(desb->fat_b == 2){ // rotacao a direita	
						if(desb->esq->fat_b == 1){ // rotacao simples
							rotacaoSimplesDireita(tree, desb);
						}else if(desb->esq->fat_b == -1){ // rotacao dupla
							rotacaoDuplaDireita(tree,desb);
						}
					}else if(desb->fat_b == -2){ // rotacao a esquerda
						if(desb->dir->fat_b == -1){ // rotacao simples
							rotacaoSimplesEsquerda(tree, desb);
						}else if(desb->dir->fat_b == 1){ // rotacao dupla
							rotacaoDuplaEsquerda(tree,desb);
						}
					}
				}
			}else{
				inserir(palavra, root->esq, tree, arqID, linhaID);
			}
		}else if(cmp > 0){ // palavra é maior que o root->atual, entao vai pro lado direito
			if(root->dir == NULL){ // alocar e inserir nodo lado direito
				new = (TpNodo*) malloc(sizeof(TpNodo));
				if(new != NULL){
					new->info = (char*) malloc(sizeof(char)* ((int)strlen(palavra)));
					strcpy(new->info, palavra);
					new->pai = root;
					root->dir = new;
					insereNodo(new, arqID, linhaID);
				}			
				/* codigo replicado do if(chave < root->info) */
				TpNodo *desb = new->pai;
				
				while(desb != NULL){
					//puts("teucu");
					//calcula_fator(desb);
					desb->fat_b = (altura(desb->esq) - altura(desb->dir));
					if(desb->fat_b == 2 || desb->fat_b == -2){
						break;
					}
					desb = desb->pai;
				}
				if(desb != NULL){

					if(desb->fat_b == 2){ // rotacao a direita
						if(desb->esq->fat_b == 1){ // rotacao simples
							rotacaoSimplesDireita(tree, desb);
						}else if(desb->esq->fat_b == -1){ // rotacao dupla
							rotacaoDuplaDireita(tree,desb);
						}
					}else if(desb->fat_b == -2){ // rotacao a esquerda
						if(desb->dir->fat_b == -1){ // rotacao simples
							rotacaoSimplesEsquerda(tree, desb);
						}else if(desb->dir->fat_b == 1){ // rotacao dupla
							rotacaoDuplaEsquerda(tree,desb);
						}
					}
				}		
			}else{
				inserir(palavra, root->dir, tree, arqID, linhaID);
			}
		}else{ // palavra ja existe, deve-se inserir ela na lista do nodo atual que é ROOT
			insereNodo(root, arqID, linhaID);
		}
		return new;
	}
	return NULL;
}

// rotacao simples a direita
void rotacaoSimplesDireita(TpArvore *AVL, TpNodo *desb){
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
		int cmp = strcmp(desb->info ,desb->pai->info);
		if(cmp < 0){ // pai esta a direita de aux
			desb->pai->esq = aux;
			aux->pai = desb->pai;
		}else if( cmp > 0 ){ // pai esta a esquerda de aux
			desb->pai->dir = aux;
			aux->pai = desb->pai;			
		}	
	}
	desb->pai = aux;
}


// rotacao simples a esquerda
void rotacaoSimplesEsquerda(TpArvore *AVL, TpNodo *desb){
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
		int cmp = strcmp(desb->info , desb->pai->info); 
		if(cmp > 0){ // pai esta a esquerda de aux
			desb->pai->dir = aux;
			aux->pai = desb->pai;
		}else if(cmp < 0){ // pai esta a direita de aux
			desb->pai->esq = aux;
			aux->pai = desb->pai;
		}	
	}
	desb->pai = aux;
}

// rotacao dupla direita
void rotacaoDuplaDireita(TpArvore *AVL, TpNodo *desb){
	TpNodo *aux = desb->esq;
	TpNodo *aux2 = aux->dir;

	if(aux2->esq != NULL){
		aux->dir = aux2->esq;
		aux2->esq->pai = aux;
	}else{
		aux->dir = NULL;
	}
	aux2->esq = aux;
	aux->pai = aux2;
	desb->esq = aux2;
	aux2->pai = desb;	

	rotacaoSimplesDireita(AVL, desb);
}

// rotacao dupla esquerda
void rotacaoDuplaEsquerda(TpArvore *AVL, TpNodo *desb){
	TpNodo *aux = desb->dir;
	TpNodo *aux2 = aux->esq;

	if(aux2->dir != NULL){
		aux->esq = aux2->dir;
		aux2->dir->pai = aux;
	}else{
		aux->esq = NULL;
	}
	aux2->dir = aux;
	aux->pai = aux2;
	desb->dir = aux2;
	aux2->pai = desb;
	rotacaoSimplesEsquerda(AVL, desb);
}

// calcula o fator de balanceamento de um nodo qualquer e retorna se existe nodo com fator desbalanceado
void calcula_fator(TpNodo* root){
	if(root == NULL)
		return;
	//	puts("cf in1"); 
	root->fat_b = (altura(root->esq) - altura(root->dir));
//	puts("cf in2");
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
TpNodo* criaNodo(char *palavra){
	TpNodo *new = (TpNodo*) malloc(sizeof(TpNodo));
	if(new != NULL){
		new->info = (char*) malloc(sizeof(char));
		strcpy(new->info, palavra);
	}
	new->dir = NULL;
	new->esq = NULL;
	new->pai = NULL;
	new->fat_b = 0;
	new->occ = NULL;
	return new;
}

void imprimir(TpNodo* root, FILE *pFile){

	if(root){
		//printf("<");
		imprimir(root->esq, pFile);
		//printf("([%s] fb= %d)\n", root->info, root->fat_b);
		fprintf(pFile,"[%s] ", root->info);
		TplNodo *atual = root->occ->first;
	//	fprintf(pFile, "%s: ", root->info);
		while(atual != NULL){
			fprintf(pFile, "{%d, %d}, ", atual->arquivo, atual->linha);
			atual = atual->next;
		}	
		fputc('\n',pFile);
		imprimir(root->dir, pFile);
		//printf(">");
	}
}



//------ listas \/  ------
TpLista *criaLista(){
    TpLista *l=NULL;
     
    l= (TpLista*) malloc(sizeof(TpLista));
    if(l == NULL) return NULL;
    l->first=NULL;
    l->last=NULL;
    l->nItems=0;
    return l;
} 

TplNodo *crialNodo(int arqID, int l){
    TplNodo *new=NULL;   
    new= (TplNodo*)malloc(sizeof(TplNodo));   
    new->next=NULL;
    new->ant=NULL;
    new->linha = l;
    new->arquivo = arqID;
    return new;
}



void insereNodo(TpNodo *root, int arqID, int linha){//l== lista a ser inseridos os nodos e, n o numero de nodos a ser inserido
    
    TplNodo *new=NULL;
    if(root->occ == NULL){ /*caso do primeiro nodo*/
		
		root->occ = criaLista();
	
		new= crialNodo(arqID, linha);
		root->occ->first=new;
		root->occ->last=new;
		root->occ->nItems++;
	}else{          
/*no fim da lista*/
		new= crialNodo(arqID, linha);
		
		root->occ->last->next=new;
        new->ant=root->occ->last;
        root->occ->last=new;
        root->occ->nItems++;
    }  
}


void ajustaStr(char *str){
	
	
	if(str[-1 + (int)strlen(str)] == '\n'){
		str[-1 + (int)strlen(str)] = '\0'; 
		
	}
	
}

void menu(){
	// menu
	puts(
			"\n###############          MENU         ###############"
			"\n##############                        ###############"
			"\n#####                                           #####"
			"\n#####          0. Sair                          #####"
			"\n#####          1. Indexar arquivos              #####"
			"\n#####          2. Adicionar palavra no indice   #####"
			"\n#####          3. Gerar Rank      		#####"
			"\n#####                                           #####"
			"\n##############                        ###############"
			"\n#####################################################\n"
		);
	
}
