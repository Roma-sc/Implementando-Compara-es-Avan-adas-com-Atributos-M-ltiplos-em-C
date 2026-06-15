#include <stdio.h>

int main() {
    // ==========================================
    // 1. DECLARAÇÃO DE VARIÁVEIS (O ALMOXARIFADO DO JOGO)
    // ==========================================
    
    // VARIÁVEIS DA CARTA 1
    char estado1;
    char codigo1[4];
    char nomePais1[50];
    int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densidade1;

    // VARIÁVEIS DA CARTA 2
    char estado2;
    char codigo2[4];
    char nomePais2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidade2;

    // VARIÁVEIS DE CONTROLE DO JOGO
    int atributo1, atributo2;
    float valAtrib1_C1, valAtrib1_C2;
    float valAtrib2_C1, valAtrib2_C2;
    char *nomeAtrib1, *nomeAtrib2;
    int vencedorAtrib1, vencedorAtrib2;
    float pontosC1, pontosC2;

    // ==========================================
    // 2. CADASTRO DAS CARTAS (NÍVEL NOVATO)
    // ==========================================
    
    // Cadastro - Carta 1
    printf("=== CADASTRO DA CARTA 1 ===\n");
    printf("Letra do Estado (A-H): ");
    scanf(" %c", &estado1);
    printf("Codigo da Carta (ex: A01): ");
    scanf("%s", codigo1);
    printf("Nome do Pais/Cidade: ");
    scanf(" %[^\n]", nomePais1);
    printf("Populacao: ");
    scanf("%d", &populacao1);
    printf("Area (in km²): ");
    scanf("%f", &area1);
    printf("PIB: ");
    scanf("%f", &pib1);
    printf("Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos1);
    printf("\n");

    // Cadastro - Carta 2
    printf("=== CADASTRO DA CARTA 2 ===\n");
    printf("Letra do Estado (A-H): ");
    scanf(" %c", &estado2);
    printf("Codigo da Carta (ex: B02): ");
    scanf("%s", codigo2);
    printf("Nome do Pais/Cidade: ");
    scanf(" %[^\n]", nomePais2);
    printf("Populacao: ");
    scanf("%d", &populacao2);
    printf("Area (in km²): ");
    scanf("%f", &area2);
    printf("PIB: ");
    scanf("%f", &pib2);
    printf("Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos2);
    printf("\n");

    // ==========================================
    // 3. PROCESSAMENTO AUTOMÁTICO (AVENTUREIRO)
    // ==========================================
    // Cálculo da Densidade Demográfica
    densidade1 = (float)populacao1 / area1;
    densidade2 = (float)populacao2 / area2;

    // ==========================================
    // 4. MENUS DINÂMICOS DE ESCOLA (NÍVEL MESTRE)
    // ==========================================
    
    // MENU 1
    printf("=========================================\n");
    printf("       ESCOLHA O PRIMEIRO ATRIBUTO       \n");
    printf("=========================================\n");
    printf("1 - Populacao\n2 - Area\n3 - PIB\n4 - Pontos Turisticos\n5 - Densidade Demografica\n");
    printf("Sua opcao: ");
    scanf("%d", &atributo1);

    switch(atributo1) {
        case 1: nomeAtrib1 = "Populacao"; valAtrib1_C1 = populacao1; valAtrib1_C2 = populacao2; break;
        case 2: nomeAtrib1 = "Area"; valAtrib1_C1 = area1; valAtrib1_C2 = area2; break;
        case 3: nomeAtrib1 = "PIB"; valAtrib1_C1 = pib1; valAtrib1_C2 = pib2; break;
        case 4: nomeAtrib1 = "Pontos Turisticos"; valAtrib1_C1 = pontosTuristicos1; valAtrib1_C2 = pontosTuristicos2; break;
        case 5: nomeAtrib1 = "Densidade Demografica"; valAtrib1_C1 = densidade1; valAtrib1_C2 = densidade2; break;
        default:
            printf("Opcao invalida! Jogo encerrado.\n");
            return 0;
    }

    // MENU 2 (DINÂMICO - Esconde o que já foi escolhido)
    printf("\n=========================================\n");
    printf("       ESCOLHA O SEGUNDO ATRIBUTO        \n");
    printf("=========================================\n");
    if (atributo1 != 1) printf("1 - Populacao\n");
    if (atributo1 != 2) printf("2 - Area\n");
    if (atributo1 != 3) printf("3 - PIB\n");
    if (atributo1 != 4) printf("4 - Pontos Turisticos\n");
    if (atributo1 != 5) printf("5 - Densidade Demografica\n");
    printf("Sua opcao: ");
    scanf("%d", &atributo2);

    // Validação de segurança
    if (atributo2 == atributo1 || atributo2 < 1 || atributo2 > 5) {
        printf("Escolha repetida ou invalida! Jogo encerrado.\n");
        return 0;
    }

    switch(atributo2) {
        case 1: nomeAtrib2 = "Populacao"; valAtrib2_C1 = populacao1; valAtrib2_C2 = populacao2; break;
        case 2: nomeAtrib2 = "Area"; valAtrib2_C1 = area1; valAtrib2_C2 = area2; break;
        case 3: nomeAtrib2 = "PIB"; valAtrib2_C1 = pib1; valAtrib2_C2 = pib2; break;
        case 4: nomeAtrib2 = "Pontos Turisticos"; valAtrib2_C1 = pontosTuristicos1; valAtrib2_C2 = pontosTuristicos2; break;
        case 5: nomeAtrib2 = "Densidade Demografica"; valAtrib2_C1 = densidade1; valAtrib2_C2 = densidade2; break;
    }

    // ==========================================
    // 5. REGRAS DE COMPARAÇÃO (OPERADOR TERNÁRIO)
    // ==========================================
    
    // Comparação do Atributo 1 (Densidade inverte: menor ganha)
    if (atributo1 == 5) {
        vencedorAtrib1 = (valAtrib1_C1 < valAtrib1_C2) ? 1 : ((valAtrib1_C1 > valAtrib1_C2) ? 2 : 0);
    } else {
        vencedorAtrib1 = (valAtrib1_C1 > valAtrib1_C2) ? 1 : ((valAtrib1_C1 < valAtrib1_C2) ? 2 : 0);
    }

    // Comparação do Atributo 2
    if (atributo2 == 5) {
        vencedorAtrib2 = (valAtrib2_C1 < valAtrib2_C2) ? 1 : ((valAtrib2_C1 > valAtrib2_C2) ? 2 : 0);
    } else {
        vencedorAtrib2 = (valAtrib2_C1 > valAtrib2_C2) ? 1 : ((valAtrib2_C1 < valAtrib2_C2) ? 2 : 0);
    }

    // ==========================================
    // 6. CÁLCULO DA SOMA DOS ATRIBUTOS
    // ==========================================
    // Ajuste da densidade para a soma: usamos (1.0 / densidade) para premiar o menor valor
    pontosC1 = (atributo1 == 5) ? (1.0f / valAtrib1_C1) : valAtrib1_C1;
    pontosC1 += (atributo2 == 5) ? (1.0f / valAtrib2_C1) : valAtrib2_C1;

    pontosC2 = (atributo1 == 5) ? (1.0f / valAtrib1_C2) : valAtrib1_C2;
    pontosC2 += (atributo2 == 5) ? (1.0f / valAtrib2_C2) : valAtrib2_C2;

    // ==========================================
    // 7. EXIBIÇÃO DO PLACAR FINAL
    // ==========================================
    printf("\n=========================================\n");
    printf("          CONFRONTO: %s VS %s\n", nomePais1, nomePais2);
    printf("=========================================\n");
    
    printf("Atributo 1: %s\n", nomeAtrib1);
    printf(" - %s: %.2f | %s: %.2f\n", nomePais1, valAtrib1_C1, nomePais2, valAtrib1_C2);
    printf(" Vencedor parcial: %s\n\n", (vencedorAtrib1 == 1) ? nomePais1 : ((vencedorAtrib1 == 2) ? nomePais2 : "Empate"));

    printf("Atributo 2: %s\n", nomeAtrib2);
    printf(" - %s: %.2f | %s: %.2f\n", nomePais1, valAtrib2_C1, nomePais2, valAtrib2_C2);
    printf(" Vencedor parcial: %s\n\n", (vencedorAtrib2 == 1) ? nomePais1 : ((vencedorAtrib2 == 2) ? nomePais2 : "Empate"));

    printf("-----------------------------------------\n");
    printf("PONTUACAO TOTAL DE SOMA:\n");
    printf(" - %s: %.2f pontos totais\n", nomePais1, pontosC1);
    printf(" - %s: %.2f pontos totais\n", nomePais2, pontosC2);
    printf("-----------------------------------------\n");

    // Decisão do grande campeão
    if (pontosC1 > pontosC2) {
        printf("VEREDITO: %s E O VENCEDOR FINAL!\n", nomePais1);
    } else if (pontosC2 > pontosC1) {
        printf("VEREDITO: %s E O VENCEDOR FINAL!\n", nomePais2);
    } else {
        printf("VEREDITO: Deu Empate na rodada!\n");
    }
    printf("=========================================\n");

    return 0;
}