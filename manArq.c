#include "manArq.h"


void menu(){
	// menu
	puts(
			"\n###############          MENU         ###############"
			"\n##############                        ###############"
			"\n#####                                           #####"
			"\n#####          0. Sair                          #####"
			"\n#####          1. Verificar arquivos            #####"
			"\n#####          2. Indexar arquivo               #####"
			"\n#####          3. Adicionar palavra em arquivo  #####"
			"\n#####                                           #####"
			"\n##############                        ###############"
			"\n#####################################################\n"
		);
	
	}


char **verifica_arquivos_entrada(int argc, char **argv){

	if(argc < 2 || argc > 2) { // so continua se a entrada for 2, se for diferente para aqui e retorna NULL
		perror("INVALID INPUT\n");
		return NULL;
	}
	FILE *pFileTable = NULL;
	pFileTable = fopen(argv[1], "r");
	if(pFileTable == NULL)
		perror("ARQUIVO DE ENTRADA VAZIO\n");

	//FILE *pFile = NULL;
	//char buffer[BUFFLEN];
	int nFiles;
	unsigned len;
	char *nomeArq = (char*) malloc(sizeof(char)); // para armazenar temporariamente o nome de cada arquivo
	char *quantArquivos = (char*) malloc(sizeof(char)); // necessario para poder guardar a quant de arquivos
	int i = 0;
	int j=0;
		
	fgets(quantArquivos, 100, pFileTable); // pega a primeira linha do arquivo, que é o numero de arquivos
	nFiles = atoi(quantArquivos);
	printf("\nquantidade de arquivos >>>> %d \n", nFiles);
	// ok ate aqui
	
	char *files[nFiles];
	//fseek(pFileTable, 1, SEEK_CUR);// posiciona 1 byte p frente forçando a descer a linha
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

	/*
	int cont;
	printf("\nimprimindo o nome dos arquivos >>\n");
	for(cont = 0; cont < nFiles; cont++){ printf("[%s]\n", files[cont]); }
	*/
	// ok ate aqui. Unico problema é q quando imprime o nome dos arquivos esta imprimindo lixo

	// -- criar arvore aqui
		// criar arvore de A até E
		//TpArvore *AateE = criaArvoreVazia();
		// criar arvore de F até J
		//TpArvore *FateJ = criaArvoreVazia();
		// criar arvore de K ate O
		//TpArvore *KateO = criaArvoreVazia();
		// criar arvore de P até T
		//TpArvore *PateT = criaArvoreVazia();
		// criar arvore de U até Z
		//TpArvore *UateZ = criaArvoreVazia();
	

	
	printf("analisando arquivo >>");
	for(j=0;j < i;j++){// analisa 1 arquivo por vez
		printf("[%s]\n", files[j]);
		if(files[j] == NULL)
			continue;

		FILE *pFile = fopen(files[j], "r");
		
		if(pFile == NULL){
			puts("arq n encontrado");
			continue;
		}
		fseek(pFile, 0, SEEK_END); // posiciona para o final do arquivo
		int tamanhoArquivo = ftell(pFile); // retorna a ultima posicao do arquivo, ou seja o tamanho dele
		rewind(pFile); // volta arquivo para o começo
		char *buffer = (char*) malloc(sizeof(char) * tamanhoArquivo); // buffer do tamanho do arquivo

		puts("aqui");
		while(fgets(buffer,tamanhoArquivo,pFile) != NULL){//pega por linha ou o arquivo inteiro
			//analisar aqui e por na arvore a ocorrencia junto com o ID do arq 
			printf("antes len:%d\n", (int)strlen(buffer));
			
			ajustaStr(buffer); /* feito, ta sem o \n no fim da string. 
								Temos que olhar p ela como se fosse uma sequencia de palavras independente da iteração
								* Ou seja, uma palavra pode começar em uma iteração e terminar em outra, abc*/
			printf("dps len:%d\n", (int)strlen(buffer));
			
			//isalpha(buffer[j]);
			puts(buffer);
			puts(".");
			
		}
		/*--------------
		varrer os arquivos carregando as palavras  
		*/
		//fclose(pFile);
		//pFile = NULL;
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
	return NULL;
}

void ler_arquivo(FILE *arq){
	char c;
	while(c != EOF){
		c = getc(arq);
		printf("%c", c);
	}
}

int validNameFile(char *fName){
		
	if(NULL != strstr(fName, ".txt") || NULL != strstr(fName, ".doc")){
		ajustaStr(fName);
		return 1;
	}else 
		return 0;
}
void ajustaStr(char *str){
	
	str[-1+(int)strlen(str)] = '\0'; // troca /n por /0
	//free((void*) str );//[(int)strlen(str)]);
	
	//return str;
}
