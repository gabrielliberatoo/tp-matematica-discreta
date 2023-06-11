#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void expandirPeano(const char *entrada, char *saida) {
    int len = strlen(entrada);
    int j = 0;
    
    for (int i = 0; i < len; i++) {
        if (entrada[i] == 'X') {
            strcat(saida, "-YF+XFX+FY-");
            j += 20;
        } else if (entrada[i] == 'Y') {
            strcat(saida, "+XF-YFY-FX+");
            j += 20;
        } else {
            saida[j] = entrada[i];
            j++;
        }
    }
    
    saida[j] = '\0';
}

int main() {
    int max_iteracoes = 4;
    const char *axioma = "X";
    char *sequencia = (char *)malloc(2 * sizeof(char));
    strcpy(sequencia, axioma);
    
    FILE *arquivo = fopen("curvaMoore.txt", "w");
    FILE *entradas = fopen("entradas3.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    printf("Digite o axioma: ");
    char axiomaa[100];
    scanf("%s", axiomaa);
    fprintf(entradas, "Axioma: ");
    fprintf(entradas, "%s", axiomaa);
    fprintf(entradas, "\n");

    printf("Digite o ângulo em graus: ");
    int angulo;
    scanf("%d", &angulo);
    fprintf(entradas, "Angulo: ");
    fprintf(entradas, "%d", angulo);
    fprintf(entradas, "\n");

    printf("Digite a regra X-> ");
    char regraX[100];
    scanf("%s", regraX);
    fprintf(entradas, "Regra para X -> ");
    fprintf(entradas, "%s", regraX);
    fprintf(entradas, "\n");

    printf("Digite a regra Y-> ");
    char regraY[100];
    scanf("%s", regraY);
    fprintf(entradas, "Regra para Y -> ");
    fprintf(entradas, "%s", regraY);
    fprintf(entradas, "\n");

    
    for (int i = 0; i <= max_iteracoes; i++) {
        fprintf(arquivo, "Fractal gerado a partir de %d interações:\n", i);
        
        fprintf(arquivo, "Sequência de símbolos: ");
        int len = strlen(sequencia);
        for (int j = 0; j < len; j++) {
            if (sequencia[j] != 'X' && sequencia[j] != 'Y') {
                fprintf(arquivo, "%c", sequencia[j]);
            }
        }
        fprintf(arquivo, "\n");
        
        char *nova_sequencia = (char *)malloc((20 * len + 1) * sizeof(char));
        expandirPeano(sequencia, nova_sequencia);
        
        free(sequencia);
        sequencia = nova_sequencia;
    }

    fprintf(arquivo, "\n");

    fclose(arquivo);
    free(sequencia);
    
    printf("As sequências foram salvas no arquivo 'curvaMoore.txt'.\n");
    
    return 0;
}
