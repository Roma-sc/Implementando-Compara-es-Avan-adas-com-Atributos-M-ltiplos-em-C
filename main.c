#include <stdio.h>

int main() {
    char nomePais1[50] = "Brasil";
    int populacao1 = 214000000;
    float area1 = 8515767.0;
    float pib1 = 1.6; 
    int pontosTuristicos1 = 42;
    float densidade1 = (float)populacao1 / area1;

    char nomePais2[50] = "Japao";
    int populacao2 = 125000000;
    float area2 = 377975.0;
    float pib2 = 4.9; 
    int pontosTuristicos2 = 50;
    float densidade2 = (float)populacao2 / area2;

    int atributo1, atributo2;
    float valAtrib1_C1, valAtrib1_C2;
    float valAtrib2_C1, valAtrib2_C2;
    char *nomeAtrib1, *nomeAtrib2;
    
    int vencedorAtrib1, vencedorAtrib2;

    printf("=========================================\n");
    printf("       SUPER TRUNFO - PRIMEIRO ATRIBUTO   \n");
    printf("=========================================\n");
    printf("1 - Populacao\n2 - Area Territorial\n3 - PIB\n4 - Pontos Turisticos\n5 - Densidade Demografica\n");
    printf("Escolha o 1o Atributo: ");
    scanf("%d", &atributo1);

    
    switch(atributo1) {
        case 1: nomeAtrib1 = "Populacao"; valAtrib1_C1 = populacao1; valAtrib1_C2 = populacao2; break;
        case 2: nomeAtrib1 = "Area"; valAtrib1_C1 = area1; valAtrib1_C2 = area2; break;
        case 3: nomeAtrib1 = "PIB"; valAtrib1_C1 = pib1; valAtrib1_C2 = pib2; break;
        case 4: nomeAtrib1 = "Pontos Turisticos"; valAtrib1_C1 = pontosTuristicos1; valAtrib1_C2 = pontosTuristicos2; break;
        case 5: nomeAtrib1 = "Densidade Demografica"; valAtrib1_C1 = densidade1; valAtrib1_C2 = densidade2; break;
        default:
            printf("Opcao Invalida! O programa sera encerrado.\n");
            return 0;
    }

    printf("\n=========================================\n");
    printf("       SUPER TRUNFO - SEGUNDO ATRIBUTO    \n");
    printf("=========================================\n");
    
    if (atributo1 != 1) printf("1 - Populacao\n");
    if (atributo1 != 2) printf("2 - Area Territorial\n");
    if (atributo1 != 3) printf("3 - PIB\n");
    if (atributo1 != 4) printf("4 - Pontos Turisticos\n");
    if (atributo1 != 5) printf("5 - Densidade Demografica\n");
    
    printf("Escolha o 2o Atributo: ");
    scanf("%d", &atributo2);

    if (atributo2 == atributo1 || atributo2 < 1 || atributo2 > 5) {
        printf("Erro: Escolha invalida ou repetida! O jogo foi cancelado.\n");
        return 0;
    }

    switch(atributo2) {
        case 1: nomeAtrib2 = "Populacao"; valAtrib2_C1 = populacao1; valAtrib2_C2 = populacao2; break;
        case 2: nomeAtrib2 = "Area"; valAtrib2_C1 = area1; valAtrib2_C2 = area2; break;
        case 3: nomeAtrib2 = "PIB"; valAtrib2_C1 = pib1; valAtrib2_C2 = pib2; break;
        case 4: nomeAtrib2 = "Pontos Turisticos"; valAtrib2_C1 = pontosTuristicos1; valAtrib2_C2 = pontosTuristicos2; break;
        case 5: nomeAtrib2 = "Densidade Demografica"; valAtrib2_C1 = densidade1; valAtrib2_C2 = densidade2; break;
    }

    if (atributo1 == 5) { 
        vencedorAtrib1 = (valAtrib1_C1 < valAtrib1_C2) ? 1 : ((valAtrib1_C1 > valAtrib1_C2) ? 2 : 0);
    } else { 
        vencedorAtrib1 = (valAtrib1_C1 > valAtrib1_C2) ? 1 : ((valAtrib1_C1 < valAtrib1_C2) ? 2 : 0);
    }

    if (atributo2 == 5) {
        vencedorAtrib2 = (valAtrib2_C1 < valAtrib2_C2) ? 1 : ((valAtrib2_C1 > valAtrib2_C2) ? 2 : 0);
    } else {
        vencedorAtrib2 = (valAtrib2_C1 > valAtrib2_C2) ? 1 : ((valAtrib2_C1 < valAtrib2_C2) ? 2 : 0);
    }

    float pontosC1 = (atributo1 == 5) ? (1.0f / valAtrib1_C1) : valAtrib1_C1;
    pontosC1 += (atributo2 == 5) ? (1.0f / valAtrib2_C1) : valAtrib2_C1;

    float pontosC2 = (atributo1 == 5) ? (1.0f / valAtrib1_C2) : valAtrib1_C2;
    pontosC2 += (atributo2 == 5) ? (1.0f / valAtrib2_C2) : valAtrib2_C2;

    printf("\n=========================================\n");
    printf("          RESULTADO DA COMPARACAO        \n");
    printf("=========================================\n");
    printf("Cartas: %s vs %s\n\n", nomePais1, nomePais2);

    printf("Atributo 1 [%s]:\n", nomeAtrib1);
    printf(" - %s: %.2f\n", nomePais1, valAtrib1_C1);
    printf(" - %s: %.2f\n", nomePais2, valAtrib1_C2);
    printf(" Vencedor do Atributo 1: %s\n\n", (vencedorAtrib1 == 1) ? nomePais1 : ((vencedorAtrib1 == 2) ? nomePais2 : "Empate"));

    printf("Atributo 2 [%s]:\n", nomeAtrib2);
    printf(" - %s: %.2f\n", nomePais1, valAtrib2_C1);
    printf(" - %s: %.2f\n", nomePais2, valAtrib2_C2);
    printf(" Vencedor do Atributo 2: %s\n\n", (vencedorAtrib2 == 1) ? nomePais1 : ((vencedorAtrib2 == 2) ? nomePais2 : "Empate"));

    printf("-----------------------------------------\n");
    printf("Soma dos Atributos Calculada (Score):\n");
    printf(" - %s: %.2f pontos\n", nomePais1, pontosC1);
    printf(" - %s: %.2f pontos\n", nomePais2, pontosC2);
    printf("-----------------------------------------\n");

    if (pontosC1 > pontosC2) {
        printf("RESULTADO FINAL: %s E O VENCEDOR DA RODADA!\n", nomePais1);
    } else if (pontosC2 > pontosC1) {
        printf("RESULTADO FINAL: %s E O VENCEDOR DA RODADA!\n", nomePais2);
    } else {
        printf("RESULTADO FINAL: Empate!\n");
    }
    printf("=========================================\n");

    return 0;
}