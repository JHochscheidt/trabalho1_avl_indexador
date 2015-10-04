#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFLEN 10

void menu();
char **verifica_arquivos_entrada(int argc, char **argv);
void ler_arquivo(FILE *arq);
int validNameFile(char *fName);//testa se os nomes dos arquivos sao válidos
void ajustaStr(char *str);

