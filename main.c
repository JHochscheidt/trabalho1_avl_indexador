#include "avl.h"
#include "manArq.h"

int main(int argc, char **argv){
	char **arquivos; // para armazenar o nome dos arquivos
	//int i = 0;
	int op;
	//char *aux;
	do{
		menu();
		scanf("%d", &op);
		switch(op){
			case 0: return 0;
				break;
			case 1: arquivos = verifica_arquivos_entrada(argc,argv);
				if(!arquivos) return 0;
				else{
					puts("arquivos verificados com sucesso>>\n");
				}
				break;
			case 2 :
				puts("Nome d arquivo que deseja indexar");//Indexar arquivo
				
				break;
			case 3 : // adicionar palavra em arquivo
				break;
			
		}		
	}while(op != 0);
return 0;
}

