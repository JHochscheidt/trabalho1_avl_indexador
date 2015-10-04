#include "avl.h"

int main(){

	TpArvore *AVL = criaArvoreVazia();

	inserir(10, AVL->root, AVL);
	//imprimir(AVL->root);
	//puts("\n");
	inserir(15, AVL->root, AVL);
	//imprimir(AVL->root);
	//puts("\n");
	inserir(12, AVL->root, AVL);
	inserir(20, AVL->root, AVL);
	inserir(17, AVL->root, AVL);
	inserir(125, AVL->root, AVL);
	inserir(175, AVL->root, AVL);
	inserir(3, AVL->root, AVL);
	inserir(4, AVL->root, AVL);
	
	imprimir(AVL->root);
	//inserir(1, AVL->root, AVL);
	//inserir(3, AVL->root, AVL);

	printf("altura da arvore", altura(AVL->root);
	
	puts("\n");
	//imprimir(AVL->root);
	/*inserir(-3, AVL->root, AVL);
	imprimir(AVL->root);
	inserir(-7, AVL->root, AVL);
	imprimir(AVL->root);
	puts("\n");
	imprimir(AVL->root);
	inserir(0, AVL->root, AVL);
	inserir(-1, AVL->root, AVL);
	imprimir(AVL->root);
	*/
return 0;
}
