#include <stdio.h>
#include <string.h>
#include <math.h>

void ondaQuadrada(int interacoes, char regra[], FILE *arquivo, int *quantidadeF, int *quantidadeSimbolos) {
    if (interacoes == 1) {
        fprintf(arquivo, "%s", regra);
        for (int i = 0; i < (int)strlen(regra); i++) {
            if (regra[i] == 'F') {
                (*quantidadeF)++; // Incrementa a quantidade de "F"
            }
            (*quantidadeSimbolos)++; // Incrementa a quantidade total de símbolos
        }
        
        return;
    }

    ondaQuadrada(interacoes - 1, regra, arquivo, quantidadeF, quantidadeSimbolos);
    fprintf(arquivo, "-");
    ondaQuadrada(interacoes - 1, regra, arquivo, quantidadeF, quantidadeSimbolos);
    fprintf(arquivo, "+");
    ondaQuadrada(interacoes - 1, regra, arquivo, quantidadeF, quantidadeSimbolos);
    fprintf(arquivo, "+");
    ondaQuadrada(interacoes - 1, regra, arquivo, quantidadeF, quantidadeSimbolos);
    ondaQuadrada(interacoes - 1, regra, arquivo, quantidadeF, quantidadeSimbolos);
    fprintf(arquivo, "-");
    ondaQuadrada(interacoes - 1, regra, arquivo, quantidadeF, quantidadeSimbolos);
    fprintf(arquivo, "-");
    ondaQuadrada(interacoes - 1, regra, arquivo, quantidadeF, quantidadeSimbolos);
    fprintf(arquivo, "+");
    ondaQuadrada(interacoes - 1, regra, arquivo, quantidadeF, quantidadeSimbolos);
    fprintf(arquivo, "\n");
}

void imprimirFractal(int interacoes, char regra[], FILE *arquivo) {
    fprintf(arquivo, "Fractal gerado a partir de %d interações:\n", interacoes);

    int quantidadeF = 0;
    int quantidadeSimbolos = 0;
    ondaQuadrada(interacoes, regra, arquivo, &quantidadeF, &quantidadeSimbolos);

    fprintf(arquivo, "Quantidade de 'F': %d\n", quantidadeF);
    fprintf(arquivo, "Quantidade de símbolos: %d\n", quantidadeSimbolos);
    fprintf(arquivo, "\n");
}

int main() {
    char regra[100];
    int interacoes = 4;
    char axioma[100];
    double angulo;
    FILE *arquivo = fopen("ondaQuadrada.txt", "w"); 
    FILE *entradas = fopen("entradas1.txt", "w");
    
    printf("Digite o número do fractal correspondente: ");
    int numeroFractal;
    scanf("%d", &numeroFractal);
    fprintf(entradas, "Número do fractal correspondente: ");
    fprintf(entradas, "%d", numeroFractal);
    fprintf(entradas, "\n");

    printf("Digite o axioma: ");
    scanf("%s", axioma);
    fprintf(entradas, "Axioma: ");
    fprintf(entradas, "%s", axioma);
    fprintf(entradas, "\n");

    printf("Digite o ângulo em graus: ");
    scanf("%lf", &angulo);
    fprintf(entradas, "Angulo: ");
    fprintf(entradas, "%lf", angulo);
    fprintf(entradas, "\n");

    printf("Digite a regra: ");
    scanf("%s", regra);
    fprintf(entradas, "Regra: ");
    fprintf(entradas, "%s", regra);
    fprintf(entradas, "\n");


    
    for (int i = 1; i <= interacoes; i++) {
        imprimirFractal(i, regra, arquivo);
    }

    fclose(arquivo); 

    printf("As saídas foram salvas no arquivo 'ondaQuadrada.txt'.\n");

    return 0;
}
