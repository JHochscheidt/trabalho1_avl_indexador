#include "avl.h"
//#include "avl.c"

int main(){

	TpArvore *AVL = criaArvoreVazia();

	inserir(20, AVL->root, AVL);
	//imprimir(AVL->root);
	//puts("\n");
	inserir(70, AVL->root, AVL);
	imprimir(AVL->root);
	//imprimir(AVL->root);
	puts("\n");
	inserir(25, AVL->root, AVL);
	imprimir(AVL->root);
	inserir(100, AVL->root, AVL);
	inserir(80, AVL->root, AVL);
	inserir(110, AVL->root, AVL);
	puts("\n");
	imprimir(AVL->root);
	/*inserir(30, AVL->root, AVL);
	inserir(10, AVL->root, AVL);
	imprimir(AVL->root);
	puts("\n");
	
	inserir(20, AVL->root, AVL);
	imprimir(AVL->root);
	puts("\n");
	
	inserir(17, AVL->root, AVL);
	imprimir(AVL->root);
	puts("\n");
	
	inserir(125, AVL->root, AVL);
	imprimir(AVL->root);
	puts("\n");
	
	inserir(175, AVL->root, AVL);
	imprimir(AVL->root);
	puts("\n");
	
	inserir(3, AVL->root, AVL);
	imprimir(AVL->root);
	puts("\n");
	
	inserir(4, AVL->root, AVL);
	imprimir(AVL->root);
	puts("\n");
	
	imprimir(AVL->root);
	//inserir(1, AVL->root, AVL);
	//inserir(3, AVL->root, AVL);

	printf("altura da arvore %d ", altura(AVL->root));
	imprimir(AVL->root);
	
	puts("\n");
	//imprimir(AVL->root);
	inserir(-3, AVL->root, AVL);
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
