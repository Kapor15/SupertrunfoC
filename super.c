#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    float populacao;  // Em milhões
    float area;       // Em km²
    float pib;        // Em bilhões
    int pontosTuristicos;
    float densidadeDemografica; // População / Área
} Carta;


int menuAtributos(char *atributoNome) {
    int escolha;
    printf("Escolha um atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Escolha: ");
    scanf("%d", &escolha);

    
    switch (escolha) {
        case 1: strcpy(atributoNome, "População"); break;
        case 2: strcpy(atributoNome, "Área"); break;
        case 3: strcpy(atributoNome, "PIB"); break;
        case 4: strcpy(atributoNome, "Pontos Turísticos"); break;
        case 5: strcpy(atributoNome, "Densidade Demográfica"); break;
        default: printf("Escolha inválida!\n"); break;
    }
    return escolha;
}

// Função para retornar o valor de um atributo escolhido
float getAtributoValor(Carta carta, int atributo) {
    switch (atributo) {
        case 1: return carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return carta.pontosTuristicos;
        case 5: return carta.densidadeDemografica;
        default: return -1; 
    }
}

// Função para comparar os dois atributos
void compararCartas(Carta carta1, Carta carta2) {
    char atributo1Nome[30], atributo2Nome[30];
    int atributo1, atributo2;
    float valor1Carta1, valor1Carta2, valor2Carta1, valor2Carta2;
    float somaCarta1, somaCarta2;

    // Escolher o primeiro atributo
    atributo1 = menuAtributos(atributo1Nome);

    // Escolher o segundo atributo, sem ser o primeiro
    do {
        atributo2 = menuAtributos(atributo2Nome);
        if (atributo2 == atributo1) {
            printf("Você não pode escolher o mesmo atributo duas vezes! Escolha outro.\n");
        }
    } while (atributo2 == atributo1);

    // Obter os valores dos atributos escolhidos
    valor1Carta1 = getAtributoValor(carta1, atributo1);
    valor1Carta2 = getAtributoValor(carta2, atributo1);
    valor2Carta1 = getAtributoValor(carta1, atributo2);
    valor2Carta2 = getAtributoValor(carta2, atributo2);

    // Imprimir os valores dos atributos
    printf("\nComparando os atributos das cartas:\n");
    printf("%s: %.2f (Carta 1) vs %.2f (Carta 2)\n", atributo1Nome, valor1Carta1, valor1Carta2);
    printf("%s: %.2f (Carta 1) vs %.2f (Carta 2)\n", atributo2Nome, valor2Carta1, valor2Carta2);

    // Verificar quem venceu em cada atributo
    if (atributo1 == 5) {  // Densidade Demográfica (menor valor vence)
        printf("Densidade Demográfica: %s venceu!\n", (valor1Carta1 < valor1Carta2) ? carta1.nome : carta2.nome);
    } else {
        printf("%s: %s venceu!\n", atributo1Nome, (valor1Carta1 > valor1Carta2) ? carta1.nome : carta2.nome);
    }

    if (atributo2 == 5) {  // Densidade Demográfica (menor valor vence)
        printf("Densidade Demográfica: %s venceu!\n", (valor2Carta1 < valor2Carta2) ? carta1.nome : carta2.nome);
    } else {
        printf("%s: %s venceu!\n", atributo2Nome, (valor2Carta1 > valor2Carta2) ? carta1.nome : carta2.nome);
    }

    // Somar os valores dos atributos
    somaCarta1 = valor1Carta1 + valor2Carta1;
    somaCarta2 = valor1Carta2 + valor2Carta2;

    // Verificar quem venceu pela soma dos atributos
    printf("\nSoma dos Atributos: %.2f (Carta 1) vs %.2f (Carta 2)\n", somaCarta1, somaCarta2);
    if (somaCarta1 > somaCarta2) {
        printf("A Carta 1 (%s) venceu!\n", carta1.nome);
    } else if (somaCarta1 < somaCarta2) {
        printf("A Carta 2 (%s) venceu!\n", carta2.nome);
    } else {
        printf("Empate!\n");
    }
}

int main() {
    // Cartas pré-definidas
    Carta carta1 = {"Brasil", 212.6, 8515767, 1443, 20, 212.6 / 8515767};
    Carta carta2 = {"Argentina", 45.38, 2780400, 388.4, 15, 45.38 / 2780400};

    // Comparar as cartas
    compararCartas(carta1, carta2);

    return 0;
}

