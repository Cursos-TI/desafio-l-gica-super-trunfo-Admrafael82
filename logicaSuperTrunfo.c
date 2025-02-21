#include <stdio.h>

#define ESTADOS 8
#define CIDADES_POR_ESTADO 4

typedef struct {
    char codigo[4];
    int populacao;
    float area;
    double pib;
    int pontos_turisticos;
} Carta;

void cadastrarCartas(Carta cartas[ESTADOS * CIDADES_POR_ESTADO]) {
    char estados[ESTADOS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int index = 0;
    
    for (int i = 0; i < ESTADOS; i++) {
        for (int j = 1; j <= CIDADES_POR_ESTADO; j++) {
            sprintf(cartas[index].codigo, "%c%02d", estados[i], j);
            
            printf("Cadastro da carta %s:\n", cartas[index].codigo);
            printf("Populacao: ");
            scanf("%d", &cartas[index].populacao);
            printf("Area (km2): ");
            scanf("%f", &cartas[index].area);
            printf("PIB (em bilhões): ");
            scanf("%lf", &cartas[index].pib);
            printf("Número de pontos turísticos: ");
            scanf("%d", &cartas[index].pontos_turisticos);
            
            index++;
        }
    }
}

void exibirCartas(Carta cartas[ESTADOS * CIDADES_POR_ESTADO]) {
    printf("\nCartas cadastradas:\n");
    for (int i = 0; i < ESTADOS * CIDADES_POR_ESTADO; i++) {
        printf("Código: %s\n", cartas[i].codigo);
        printf("População: %d\n", cartas[i].populacao);
        printf("Área: %.2f km²\n", cartas[i].area);
        printf("PIB: %.2lf bilhões\n", cartas[i].pib);
        printf("Pontos turísticos: %d\n", cartas[i].pontos_turisticos);
        printf("-------------------------\n");
    }
}

double calcularDensidadePopulacional(Carta carta) {
    return (double)carta.populacao / carta.area;
}

double calcularPibPerCapita(Carta carta) {
    return carta.pib / carta.populacao;
}

// Função para comparar as cartas com base no atributo escolhido
void compararCartas(Carta carta1, Carta carta2, const char* atributo) {
    double atributoCarta1 = 0, atributoCarta2 = 0;
    
    if (strcmp(atributo, "População") == 0) {
        atributoCarta1 = carta1.populacao;
        atributoCarta2 = carta2.populacao;
    } else if (strcmp(atributo, "Área") == 0) {
        atributoCarta1 = carta1.area;
        atributoCarta2 = carta2.area;
    } else if (strcmp(atributo, "PIB") == 0) {
        atributoCarta1 = carta1.pib;
        atributoCarta2 = carta2.pib;
    } else if (strcmp(atributo, "Densidade Populacional") == 0) {
        atributoCarta1 = calcularDensidadePopulacional(carta1);
        atributoCarta2 = calcularDensidadePopulacional(carta2);
    } else if (strcmp(atributo, "PIB per Capita") == 0) {
        atributoCarta1 = calcularPibPerCapita(carta1);
        atributoCarta2 = calcularPibPerCapita(carta2);
    }

    printf("\nComparação de cartas (Atributo: %s):\n", atributo);
    printf("Carta 1 - Código: %s, %s: %.2f\n", carta1.codigo, atributo, atributoCarta1);
    printf("Carta 2 - Código: %s, %s: %.2f\n", carta2.codigo, atributo, atributoCarta2);
    
    if (strcmp(atributo, "Densidade Populacional") == 0) {
        // Para Densidade Populacional, a carta com a menor densidade vence
        if (atributoCarta1 < atributoCarta2) {
            printf("Resultado: Carta 1 venceu!\n");
        } else if (atributoCarta1 > atributoCarta2) {
            printf("Resultado: Carta 2 venceu!\n");
        } else {
            printf("Resultado: Empate!\n");
        }
    } else {
        // Para os outros atributos, a carta com o maior valor vence
        if (atributoCarta1 > atributoCarta2) {
            printf("Resultado: Carta 1 venceu!\n");
        } else if (atributoCarta1 < atributoCarta2) {
            printf("Resultado: Carta 2 venceu!\n");
        } else {
            printf("Resultado: Empate!\n");
        }
    }
}

int main() {
    Carta cartas[ESTADOS * CIDADES_POR_ESTADO];
    cadastrarCartas(cartas);
    
    // Vamos comparar duas cartas específicas
    Carta carta1 = cartas[0]; // Carta 1: A01
    Carta carta2 = cartas[1]; // Carta 2: A02
    
    // Comparar as cartas com base no atributo escolhido
    compararCartas(carta1, carta2, "População"); // Exemplo: Comparando a população
    
    return 0;
}
