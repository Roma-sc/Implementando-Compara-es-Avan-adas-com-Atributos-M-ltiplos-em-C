#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int resultado1, resultado2;
    char primeiroatributo1, segundoatributo2;
    int Espada1, Espada2, Arcoeflecha1, Arcoeflecha2, Lanca1, Lanca2;

    // Números Aleátorios
    srand(time(0));
    Espada1 = 1; //rand () % 100 + 1; // Número entre 1 a 100
    Espada2 = 0; //rand () % 100 + 1; // Número entre 1 a 100
    Arcoeflecha1 = 0; //rand () % 100 + 1; // Número entre 1 a 100
    Arcoeflecha2 =1; //rand () % 100 + 1; // Número entre 1 a 100
     Lanca1 = 1; //rand () % 100 + 1; // Número entre 1 a 100
     Lanca2 = 0; //rand () % 100 + 1; // Número entre 1 a 100

    // Que começe os Jogos Vorazes Edição 13
    printf("Bem Vindo ao Jogos Vorazes 13!\n");
    printf("Escolha seu Primeiro Atributo para a batalha.\n");
    printf("E. Espada\n");
    printf("A. Arcoeflecha\n");
    printf("L. Lanca\n");

    printf("Escolha a comparação: ");
    scanf("%c", &primeiroatributo1);

    switch (primeiroatributo1)
    {
    case 'E':
    case 'e':
        printf("Você escolheu o atributo Espada!\n");
        resultado1 = Espada1 > Espada2 ? 1 : 0;
        break;
    case 'A' :
    case 'a':
       printf("Você escolheu o atributo Arcoeflecha!\n");
        resultado1 = Arcoeflecha1 > Arcoeflecha2 ? 0 : 1;
        break;
    case 'L':
    case 'l':
       printf("Você escolheu o atributo Lanca!\n");
        resultado1 = Lanca1 > Lanca2 ? 1 : 0;         
    default:
        printf("Opção de Atributo Invalida.\n");
        break;
    }
          
    printf("Bem Vindo ao Jogos Vorazes 13!\n");
    printf("Escolha seu Segundo Atributo para a batalha.\n");
    printf("A escolha do seu Segundo Atributo para a batalha deve ser difrente do Primeiro Atributo.\n");
    printf("E. Espada\n");
    printf("A. Arcoeflecha\n");
    printf("L. Lanca\n");

    printf("Escolha a comparação: ");
    scanf("%c", &segundoatributo2);

    if (primeiroatributo1 == segundoatributo2)
    {
        printf("Você escolheu o mesmo Atributo!");
    }else{
        switch (segundoatributo2)
        {
        case 'E':
        case 'e':
            printf("Você escolheu o atributo Espada!\n");
            resultado2 = Espada1 > Espada2 ? 1 : 0;
            break;
        case 'A' :
        case 'a':
            printf("Você escolheu o atributo Arcoeflecha!\n");
            resultado2 = Arcoeflecha1 > Arcoeflecha2 ? 0 : 1;
            break;
        case 'L':
        case 'l':
             printf("Você escolheu o atributo Lanca!\n");
             resultado2 = Lanca1 > Lanca2 ? 1 : 0;
        default:
        printf("Opção de Atributo Invalida.\n");
            break;
        }

        if (resultado1 && resultado2)
        {
            printf("Parabéns, Você venceu!\n");
        }else if (resultado1 != resultado2){
            printf("Empatou!\n");
        } else { 
            printf("Infelizmente, Você Perdeu!\n");
        }
        
        
        
       
    }
    
    



}
