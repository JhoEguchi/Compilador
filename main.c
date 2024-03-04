#include <stdio.h>
#include "globals.h"
#include "util.h"
#include "assembly.h"
#include "binario.h"
#include "yacc.h"
#include "semantico.h"
#include "cgen.h"

extern FILE *yyin;
int ERRO = 0;
int lineno = 1;
TokenType GetToken();
void analise_lexica();


int main(){
    FILE *entrada, *saida, *saida1, *saida2, *saida3;
    TreeNode *arvore_sintatica;
    QuadList *Q;
    AssemblyList *A;
    BinaryList *B;
    entrada = fopen("entrada.txt","r");
    yyin = entrada;
    printf("\nCriando arquivo de saída da Análise léxica...\n" );
    analise_lexica();
    if(ERRO){
        printf("\nErro ao criar arquivo de saída da Análise léxica\n" );
        return 0;
    }
    else{
      printf("\nCriado com Sucesso!\n" );
    }
    saida = fopen("./Saidas/arvoresintatica.txt","w+");
    rewind(yyin);
    lineno = 1;
    printf("\nCriando arquivo de saída da Árvore Sintática...\n" );
    arvore_sintatica = parse();
    if(ERRO){
        printf("\nErro ao criar arquivo de saída da Árvore Sintática\n" );
        return 0;
    }
    else{
      printf("\nCriado com Sucesso!\n" );
    }
    printTree(arvore_sintatica, saida);
    printf("\nCriando arquivo de saída da Tabela de Símbolos...\n" );
    buildSymtab(arvore_sintatica);
    if(ERRO){
        printf("\nErro ao criar arquivo de saída da Tabela de Símbolos\n" );
        return 0;
    }
    else{
      printf("\nCriado com Sucesso!\n" );
    }
    typeCheck(arvore_sintatica);
    printf("\nCriando arquivo de saída das quadruplas...\n" );
    Q = codeGen(arvore_sintatica);
    saida1 = fopen("./Saidas/cgen.txt","w+");
    printQuad(Q, saida1);
    printf("\nCriado com Sucesso!\n" );
    while(Q->last != NULL)
	Q = Q->last;
    printf("\nCriando arquivo de saída do codigo Assembly...\n" );
    A = AssemblyGenerator(Q);
    saida2 = fopen("./Saidas/assembly.txt","w+");
    printAssembly(A, saida2);
    printf("\nCriado com Sucesso!\n" );
    printf("\nCriando arquivo de saída do codigo Binario...\n" );
    B = BinaryGenerator(A);
    saida3 = fopen("./Saidas/binario.txt", "w+");
    printBinario(B, saida3);
     printf("\nCriado com Sucesso!\n" );
    return 0;
}
