#include "avl.h"
#include "manArq.h"
#include <sys/time.h>
#include <time.h>

int main(int argc, char **argv){
	
	
	time_t segundos = time(NULL);
	
	/*
	TpArvore *teste = criaArvoreVazia();
	inserir("abacate", teste->root, teste);
	inserir("aba", teste->root, teste);
	inserir("abac", teste->root, teste);
	inserir("abacat", teste->root, teste);
	inserir("aacate", teste->root, teste);
	inserir("bacate", teste->root, teste);
	imprimir(teste->root);
	*/
	// -- criar arvore aqui
		// criar arvore de A até E
		TpArvore *AateE = criaArvoreVazia();
		// criar arvore de F até J
		TpArvore *FateJ = criaArvoreVazia();
		// criar arvore de K ate O
		TpArvore *KateO = criaArvoreVazia();
		// criar arvore de P até T
		TpArvore *PateT = criaArvoreVazia();
		// criar arvore de U até Z
		TpArvore *UateZ = criaArvoreVazia();
	int nlinha;
	int op;
	char *pch;	
	FILE *pRank ;
	do{
		menu();
		scanf("%d", &op);
		switch(op){
			case 0: return 0;
				break;
			case 1:
				{
					if(argc < 2 || argc > 2) { // so continua se a entrada for 2, se for diferente para aqui e retorna NULL
						perror("INVALID INPUT\n");
						return 0;
					}
					FILE *pFileTable = NULL;
					pFileTable = fopen(argv[1], "r");
					if(pFileTable == NULL)
						perror("ARQUIVO DE ENTRADA VAZIO\n");
					
					//size_t result;	
					int nFiles;
					unsigned len;
					char *nomeArq = (char*) malloc(sizeof(char)); // para armazenar temporariamente o nome de cada arquivo
					char *quantArquivos = (char*) malloc(sizeof(char)); // necessario para poder guardar a quant de arquivos
					int i = 0;
					int j = 0;
							
					fgets(quantArquivos, 100, pFileTable); // pega a primeira linha do arquivo, que é o numero de arquivos
					nFiles = atoi(quantArquivos);	
					char *files[nFiles]; 
				
					while(fgets(nomeArq,100,pFileTable) != NULL && i < nFiles){// copia os nomes dos arquivos
							ajustaStr(nomeArq);
							len  = (unsigned)strlen(nomeArq);
							files[i] = (char*) malloc(sizeof(char) * ( len-1));
							strcpy(files[i], nomeArq);
							i++;
					}// nesse ponto files é um vetor de nomes válidos de arquivos a serem indexados (o ID de cada arquivo é sua posição em files + 1, ou seja i+1)
					fclose(pFileTable);
		
					FILE *pFile = NULL;
					for(j=0;j < i;j++){// analisa 1 arquivo por vez
						if(files[j] == NULL)
							continue;
						pFile = fopen(files[j], "r");
						if(pFile == NULL){
							puts("arq n encontrado");
							continue;
						}
						fseek(pFile, 0, SEEK_END); // posiciona para o final do arquivo
						long tamanhoArquivo = ftell(pFile); // retorna a ultima posicao do arquivo, ou seja o tamanho dele
						rewind(pFile); // volta arquivo para o começo
						char *buffer = (char*) malloc(sizeof(char) * tamanhoArquivo); // buffer do tamanho do arquivo
						
						nlinha = 0;
						while(fgets(buffer, tamanhoArquivo, pFile)){
							nlinha++;
							pch = strtok (buffer, ", .-?!,.:;");
							while(pch != NULL){
								if(((int)strlen(pch)) < 4){
									pch = strtok (NULL, ", .-?!,.:;");
									continue;
								}
								if(strncmp(pch, "A", 1) == 0 || strncmp(pch, "a", 1) == 0 || strncmp(pch, "B", 1) == 0 || strncmp(pch, "b", 1) == 0 || strncmp(pch, "C", 1) == 0 || strncmp(pch, "c", 1) == 0 || strncmp(pch, "D", 1) == 0 || strncmp(pch, "d", 1) == 0 || strncmp(pch, "E", 1) == 0 || strncmp(pch, "e", 1) == 0){
									//puts("A-E");									
									inserir(pch, AateE->root, AateE, j, nlinha);
								//	puts("A-E/");
								}else if(strncmp(pch, "F", 1) == 0 || strncmp(pch, "f", 1) == 0 || strncmp(pch, "G", 1) == 0 || strncmp(pch, "g", 1) == 0 || strncmp(pch, "H", 1) == 0 || strncmp(pch, "h", 1) == 0 || strncmp(pch, "I", 1) == 0 || strncmp(pch, "i", 1) == 0 || strncmp(pch, "J", 1) == 0 || strncmp(pch, "j", 1) == 0){
									//puts("F-J");
									inserir(pch, FateJ->root, FateJ,j, nlinha);
									//puts("F-J/");
								}else if(strncmp(pch, "K", 1) == 0 || strncmp(pch, "k", 1) == 0 || strncmp(pch, "L", 1) == 0 || strncmp(pch, "l", 1) == 0 || strncmp(pch, "M", 1) == 0 || strncmp(pch, "m", 1) == 0 || strncmp(pch, "N", 1) == 0 || strncmp(pch, "n", 1) == 0 || strncmp(pch, "O", 1) == 0 || strncmp(pch, "o", 1) == 0){
									//puts("K-O");
									inserir(pch, KateO->root, KateO,j, nlinha);
									//puts("K-O/");
								}else if(strncmp(pch, "P", 1) == 0 || strncmp(pch, "p", 1) == 0 || strncmp(pch, "Q", 1) == 0 || strncmp(pch, "q", 1) == 0 || strncmp(pch, "R", 1) == 0 || strncmp(pch, "r", 1) == 0 || strncmp(pch, "S", 1) == 0 || strncmp(pch, "s", 1) == 0 || strncmp(pch, "T", 1) == 0 || strncmp(pch, "t", 1) == 0){
									//puts("P-T");
									//imprimir(PateT->root);
									inserir(pch, PateT->root, PateT,j, nlinha);
									//puts("P-T/");
								}else if(strncmp(pch, "U", 1) == 0 || strncmp(pch, "u", 1) == 0 || strncmp(pch, "V", 1) == 0 || strncmp(pch, "v", 1) == 0 || strncmp(pch, "W", 1) == 0 || strncmp(pch, "w", 1) == 0 || strncmp(pch, "X", 1) == 0 || strncmp(pch, "x", 1) == 0 || strncmp(pch, "Y", 1) == 0 || strncmp(pch, "y", 1) == 0 || strncmp(pch, "|", 1) == 0 || strncmp(pch, "z", 1) == 0){
									//puts("U-Z");
									inserir(pch, UateZ->root, UateZ,j, nlinha);
								//	puts("U-Z/");
								}							
								pch = strtok (NULL, ", .-?!,.:;");			
							}
						}
										
					}
				fclose(pFile);
				int tempo_decorrido = time(NULL) - segundos;
				printf("TEMPO: %d\n", tempo_decorrido);
				}
				break;
			case 2 :
				pch= (char*) malloc(sizeof(char)*100);
				puts("entre com a palavra a ser inserida no indice invertido");
				fgets(pch,99, stdin);
				if(strncmp(pch, "A", 1) == 0 || strncmp(pch, "a", 1) == 0 || strncmp(pch, "B", 1) == 0 || strncmp(pch, "b", 1) == 0 || strncmp(pch, "C", 1) == 0 || strncmp(pch, "c", 1) == 0 || strncmp(pch, "D", 1) == 0 || strncmp(pch, "d", 1) == 0 || strncmp(pch, "E", 1) == 0 || strncmp(pch, "e", 1) == 0){
					//puts("A-E");
					inserir(pch, AateE->root, AateE, -1, -1);
				//	puts("A-E/");
				}else if(strncmp(pch, "F", 1) == 0 || strncmp(pch, "f", 1) == 0 || strncmp(pch, "G", 1) == 0 || strncmp(pch, "g", 1) == 0 || strncmp(pch, "H", 1) == 0 || strncmp(pch, "h", 1) == 0 || strncmp(pch, "I", 1) == 0 || strncmp(pch, "i", 1) == 0 || strncmp(pch, "J", 1) == 0 || strncmp(pch, "j", 1) == 0){
					//puts("F-J");
					inserir(pch, FateJ->root, FateJ,-1, -1);
					//puts("F-J/");
				}else if(strncmp(pch, "K", 1) == 0 || strncmp(pch, "k", 1) == 0 || strncmp(pch, "L", 1) == 0 || strncmp(pch, "l", 1) == 0 || strncmp(pch, "M", 1) == 0 || strncmp(pch, "m", 1) == 0 || strncmp(pch, "N", 1) == 0 || strncmp(pch, "n", 1) == 0 || strncmp(pch, "O", 1) == 0 || strncmp(pch, "o", 1) == 0){
					//puts("K-O");
					inserir(pch, KateO->root, KateO,-1, -1);
					//puts("K-O/");
				}else if(strncmp(pch, "P", 1) == 0 || strncmp(pch, "p", 1) == 0 || strncmp(pch, "Q", 1) == 0 || strncmp(pch, "q", 1) == 0 || strncmp(pch, "R", 1) == 0 || strncmp(pch, "r", 1) == 0 || strncmp(pch, "S", 1) == 0 || strncmp(pch, "s", 1) == 0 || strncmp(pch, "T", 1) == 0 || strncmp(pch, "t", 1) == 0){
					//puts("P-T");
					//imprimir(PateT->root);
					inserir(pch, PateT->root, PateT,-1, -1);
					//puts("P-T/");
				}else if(strncmp(pch, "U", 1) == 0 || strncmp(pch, "u", 1) == 0 || strncmp(pch, "V", 1) == 0 || strncmp(pch, "v", 1) == 0 || strncmp(pch, "W", 1) == 0 || strncmp(pch, "w", 1) == 0 || strncmp(pch, "X", 1) == 0 || strncmp(pch, "x", 1) == 0 || strncmp(pch, "Y", 1) == 0 || strncmp(pch, "y", 1) == 0 || strncmp(pch, "|", 1) == 0 || strncmp(pch, "z", 1) == 0){
					//puts("U-Z");
					inserir(pch, UateZ->root, UateZ,-1, -1);
				//	puts("U-Z/");
				}	
				break;
			
			case 3 : // adicionar palavra em arquivo
				
				pRank = fopen("wordtable.txt", "w+");
				imprimir(AateE->root,pRank);
				imprimir(FateJ->root,pRank);
				imprimir(KateO->root,pRank);
				imprimir(PateT->root,pRank);
				imprimir(UateZ->root,pRank);
				fclose(pRank);
				break;
		}		
	}while(op != 0);
	
	return 0;
}

