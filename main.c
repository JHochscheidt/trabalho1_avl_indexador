#include "avl.h"
//#include "avl.c"

int main(){

	TpArvore *AVL = criaArvoreVazia();

	inserir(10, AVL->root, AVL);
	//imprimir(AVL->root);
	//puts("\n");
	inserir(20, AVL->root, AVL);
	imprimir(AVL->root);
	//imprimir(AVL->root);
	puts("\n");
	inserir(30, AVL->root, AVL);
	imprimir(AVL->root);
	inserir(40, AVL->root, AVL);
	inserir(50, AVL->root, AVL);
	inserir(60, AVL->root, AVL);
	inserir(70, AVL->root, AVL);
	inserir(80, AVL->root, AVL);
	inserir(90, AVL->root, AVL);
	inserir(100, AVL->root, AVL);
	inserir(110, AVL->root, AVL);
	inserir(120, AVL->root, AVL);
	inserir(130, AVL->root, AVL);
	inserir(140, AVL->root, AVL);
	inserir(150, AVL->root, AVL);
	
	puts("\n");
	imprimir(AVL->root);

	puts("\n");
	printf("altura da arvore %d", altura(AVL->root));
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
