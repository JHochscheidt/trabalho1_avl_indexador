#include "avl.h"
#include "manArq.h"

int main(int argc, char **argv){
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
	
	int op;
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
				//	printf("\nquantidade de arquivos >>>> %d \n", nFiles);
					// ok ate aqui
					char *files[nFiles];  //fseek(pFileTable, 1, SEEK_CUR);// posiciona 1 byte p frente forçando a descer a linha
					//ok ate aqui
					
					while(fgets(nomeArq,100,pFileTable) != NULL && i < nFiles){// copia os nomes dos arquivos
						//printf("arquivo >>>[%s]\n", nomeArq);
						//if(validNameFile(nomeArq)){ // fazer essa verificacao na valida nome, verificar tbm a ajustaStr
							ajustaStr(nomeArq);
							//printf("arquivo >>>[%s]\n", nomeArq);
							len  = (unsigned)strlen(nomeArq);
							files[i] = (char*) malloc(sizeof(char) * ( len-1));
							strcpy(files[i], nomeArq);
							//printf("nome novo >>>[%s]\n", files[i]);
							i++;
						//}
					}// nesse ponto files é um vetor de nomes válidos de arquivos a serem indexados (o ID de cada arquivo é sua posição em files + 1, ou seja i+1)
					fclose(pFileTable);
					/* 	int cont;
						printf("\nimprimindo o nome dos arquivos >>\n");
						for(cont = 0; cont < nFiles; cont++){ printf("[%s]\n", files[cont]); }
					*/
					//printf("analisando arquivo >>");
					FILE *pFile = NULL;
					for(j=0;j < i;j++){// analisa 1 arquivo por vez
						//printf("[%s]\n", files[j]);
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
						//puts("aqui");
						/*result = fread(buffer,1,tamanhoArquivo,pFile);
						if (result != tamanhoArquivo) {puts("Reading error"); exit (3);}*/
						//puts("test");
						
						//pFile = NULL;
						int x;
						puts("BUFFER VAZIO");
						for(x=0;x<tamanhoArquivo ;x++){
							buffer[x] = fgetc(pFile);
						}
						puts("BUFFER CHEIRO");
						//puts(buffer);
						//fclose(pFile);
						char *pch;
						//puts(buffer);
						pch = strtok (buffer, ", .-?!,.:;\n");
						//ajustaStr(buffer); 
						//printf("pchlen: %d\n", (int)strlen(pch));
						while(pch != NULL){//pega por linha ou o arquivo inteiro
							//analisar aqui e por na arvore a ocorrencia junto com o ID do arq 
							//printf("antes len:%d\n", (int)strlen(buffer));	
							/*feito, ta sem o \n no fim da string. 
													Temos que olhar p ela como se fosse uma sequencia de palavras independente da iteração
													* Ou seja, uma palavra pode começar em uma iteração e terminar em outra, abc*/
						//	printf("dps len:%d\n", (int)strlen(buffer));
							
						//	printf ("%s  em tokens: \n Splitting seqüência \n", buffer);
							
							if(((int)strlen(pch)) < 4){
								pch = strtok (NULL, ", .-?!,.:;\n");
								continue;
							}
						//	puts(pch);
							
								//while (pch != NULL){
								//	printf ("%s \n", pch);
									if(strncmp(pch, "A", 1) == 0 || strncmp(pch, "a", 1) == 0 || strncmp(pch, "B", 1) == 0 || strncmp(pch, "b", 1) == 0 || strncmp(pch, "C", 1) == 0 || strncmp(pch, "c", 1) == 0 || strncmp(pch, "D", 1) == 0 || strncmp(pch, "d", 1) == 0 || strncmp(pch, "E", 1) == 0 || strncmp(pch, "e", 1) == 0){
										//puts("A-E");
										inserir(pch, AateE->root, AateE);
									//	puts("A-E/");
									}else if(strncmp(pch, "F", 1) == 0 || strncmp(pch, "f", 1) == 0 || strncmp(pch, "G", 1) == 0 || strncmp(pch, "g", 1) == 0 || strncmp(pch, "H", 1) == 0 || strncmp(pch, "h", 1) == 0 || strncmp(pch, "I", 1) == 0 || strncmp(pch, "i", 1) == 0 || strncmp(pch, "J", 1) == 0 || strncmp(pch, "j", 1) == 0){
										//puts("F-J");
										inserir(pch, FateJ->root, FateJ);
										//puts("F-J/");
									}else if(strncmp(pch, "K", 1) == 0 || strncmp(pch, "k", 1) == 0 || strncmp(pch, "L", 1) == 0 || strncmp(pch, "l", 1) == 0 || strncmp(pch, "M", 1) == 0 || strncmp(pch, "m", 1) == 0 || strncmp(pch, "N", 1) == 0 || strncmp(pch, "n", 1) == 0 || strncmp(pch, "O", 1) == 0 || strncmp(pch, "o", 1) == 0){
										//puts("K-O");
										inserir(pch, KateO->root, KateO);
										//puts("K-O/");
									}else if(strncmp(pch, "P", 1) == 0 || strncmp(pch, "p", 1) == 0 || strncmp(pch, "Q", 1) == 0 || strncmp(pch, "q", 1) == 0 || strncmp(pch, "R", 1) == 0 || strncmp(pch, "r", 1) == 0 || strncmp(pch, "S", 1) == 0 || strncmp(pch, "s", 1) == 0 || strncmp(pch, "T", 1) == 0 || strncmp(pch, "t", 1) == 0){
										//puts("P-T");
										//imprimir(PateT->root);
										inserir(pch, PateT->root, PateT);
										//puts("P-T/");
									}else if(strncmp(pch, "U", 1) == 0 || strncmp(pch, "u", 1) == 0 || strncmp(pch, "V", 1) == 0 || strncmp(pch, "v", 1) == 0 || strncmp(pch, "W", 1) == 0 || strncmp(pch, "w", 1) == 0 || strncmp(pch, "X", 1) == 0 || strncmp(pch, "x", 1) == 0 || strncmp(pch, "Y", 1) == 0 || strncmp(pch, "y", 1) == 0 || strncmp(pch, "|", 1) == 0 || strncmp(pch, "z", 1) == 0){
										//puts("U-Z");
										inserir(pch, UateZ->root, UateZ);
									//	puts("U-Z/");

									}							
									pch = strtok (NULL, ", .-?!,.:;\n");
									
								}
								//isalpha(buffer[j]);
							//	puts(buffer);
							//	puts(".");
									
								//}
								/*--------------
								varrer os arquivos carregando as palavras  
								*/
								
							}
							/*
							for(i = 1; i < argc; i++){
								arq = fopen(argv[i], "r");
								if(!arq){
									printf("arquivo %s não existe\n", argv[i]);
									return NULL;
								}else{
									buffer = (char*) malloc(sizeof(char));
									fgets(buffer, 100,arq); // para pegar a primeira linha do arquivo ( quant Arquivos )
									int quantArquivos = atoi(buffer); // casting do numero de arquivos para um inteiro
									//printf("%d quant arquivos", quantArquivos);
									char **arquivos  = malloc(sizeof(char) * quantArquivos);
									int j;
									FILE *testeArq;
									for(j = 0; j < quantArquivos; j++){
										fgets(buffer, 100,arq);
										//puts(buffer);
										int tamBuffer = strlen(buffer);
										//printf("%d\n", tamBuffer);
										// gambiarra
										char *aux = (char*) malloc (sizeof(char));
										strncpy(aux, buffer, tamBuffer-1);
										tamBuffer = strlen(aux);
										//printf("%d\n", tamBuffer);
										// fim gambiarra	
										testeArq = fopen(aux, "r");
										// verificacao se arquivo existe
										if(!testeArq){
											printf("Arquivo %s nao existe!!!\n", aux);
											return NULL;
										}
										//printf("Arquivo %s existe!!!\n", aux);
										fclose(testeArq);
										arquivos[j] = (char*) malloc(sizeof(char));
										arquivos[j] = aux;
									}		
									*/
									/* verifica se o vetor possui os nomes dos arquivos
									 * int cont;
									 * for(cont = 0; cont < quantArquivos; cont++){
									 * 	puts(arquivos[cont]);
									 * }
									 */
									 /*		
									// apenas para verificar se os parametros estao corretos
									if(fgets(buffer, 100,arq)){
										printf("\nNumero de arquivos diferente que o numero passado por parametro!!!\n");
										return NULL;
									}else{
										printf("Arquivo de entrada verificado com sucesso!!!\n");
									}
									fclose(arq);
									
									return arquivos;
								}
							}*/
				
				imprimir(AateE->root);			
				imprimir(FateJ->root);	
				imprimir(KateO->root);
				imprimir(PateT->root);	
				imprimir(UateZ->root);
										


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

