#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[50];
    char codigo[20];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} CartaCidade;

float densidade_populacional(CartaCidade c) {
    return c.area > 0 ? (float)c.populacao / c.area : -1;
}

CartaCidade cadastrar_carta() {
    CartaCidade c;
    printf("Estado: ");
    scanf(" %49[^"]", c.estado);
    printf("Código da Carta: ");
    scanf(" %19s", c.codigo);
    printf("Nome da Cidade: ");
    scanf(" %49[^"]", c.nome);
    printf("População: ");
    scanf("%d", &c.populacao);
    printf("Área (km²): ");
    scanf("%f", &c.area);
    printf("PIB (milhões): ");
    scanf("%f", &c.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &c.pontos_turisticos);
    return c;
}

void comparar_cartas(CartaCidade c1, CartaCidade c2, char atributo[]) {
    float valor1, valor2;
    
    if (strcmp(atributo, "populacao") == 0) {
        valor1 = c1.populacao;
        valor2 = c2.populacao;
    } else if (strcmp(atributo, "area") == 0) {
        valor1 = c1.area;
        valor2 = c2.area;
    } else if (strcmp(atributo, "pib") == 0) {
        valor1 = c1.pib;
        valor2 = c2.pib;
    } else if (strcmp(atributo, "pontos_turisticos") == 0) {
        valor1 = c1.pontos_turisticos;
        valor2 = c2.pontos_turisticos;
    } else if (strcmp(atributo, "densidade_populacional") == 0) {
        valor1 = densidade_populacional(c1);
        valor2 = densidade_populacional(c2);
    } else {
        printf("Atributo inválido!\n");
        return;
    }
    
    CartaCidade vencedor = (strcmp(atributo, "densidade_populacional") == 0) ?
                            (valor1 < valor2 ? c1 : c2) :
                            (valor1 > valor2 ? c1 : c2);
    
    printf("\nComparação pelo atributo: %s\n", atributo);
    printf("%s: %.2f\n", c1.nome, valor1);
    printf("%s: %.2f\n", c2.nome, valor2);
    printf("Cidade vencedora: %s\n", vencedor.nome);
}

int main() {
    printf("Cadastro da primeira carta:\n");
    CartaCidade carta1 = cadastrar_carta();
    printf("\nCadastro da segunda carta:\n");
    CartaCidade carta2 = cadastrar_carta();
    
    char atributo[30];
    printf("\nAtributos disponíveis para comparação: populacao, area, pib, pontos_turisticos, densidade_populacional\n");
    printf("Escolha um atributo para comparar: ");
    scanf(" %29s", atributo);
    
    comparar_cartas(carta1, carta2, atributo);
    return 0;
}
