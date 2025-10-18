#include <stdio.h>

enum opcao {
    informe_gastos = 1,
    calculadora_gastos_adicionais,
    saldo_mensal_atual,
    gastos_futuros,
    sair
};

int main() {
    double aluguel, energia, internet, agua, compras_supermercado;
    double saldo_final, gastos_adicionais, total_gastos_mes;
    double salario, renda_extra;
    double gastos_basicos;
    int escolha;
    double gasto1, gasto2;
    char adicionar_gasto ;
    char gasto1Nome[100], gasto2Nome[100]; 


    printf("Digite o valor do seu salario: ");
    scanf("%lf", &salario);
    printf("Digite o valor da renda extra: ");
    scanf("%lf", &renda_extra);

    gastos_adicionais = 0.0;
    saldo_final = salario + renda_extra;
    
    do
    {
        printf ("\n\nSelecione a opcao: \n"); 
        printf ("1. Informe gastos\n2. Calculadora de gastos (Em-breve)\n3.gastos mensais atuais\n4.gastosfuturos\n5.sair\n");
        scanf ("%d", &escolha);

    switch (escolha)
        {
    case informe_gastos:
    printf("Digite o valor do aluguel: ");
    scanf("%lf", &aluguel);
    printf("Digite o valor da conta de energia: ");
    scanf("%lf", &energia);
    printf("Digite o valor da conta de agua: ");
    scanf("%lf", &agua);
    printf("Digite o valor da conta de internet: ");
    scanf("%lf", &internet);
    printf("Digite o valor das compras supermercado do mes: ");
    scanf("%lf", &compras_supermercado);
    if (gastos_adicionais == 0)
    {
        printf ("informe os valor total de gastos adicionais: ");
        scanf ("%lf", &gastos_adicionais);
    }

    gastos_basicos = aluguel + energia + agua + internet + compras_supermercado;
    total_gastos_mes = gastos_basicos + gastos_adicionais;
    saldo_final = (salario + renda_extra) - total_gastos_mes;

    printf ("O seu total de gastos no valor de R$ %2.lf foi Informado com sucesso!!", total_gastos_mes);
        break;
    
    case calculadora_gastos_adicionais:
        printf ("\n--- Calculadora de Gastos Adicionais ---\n");
        printf ("informe o nome do Gasto adicional 1: ");
        scanf ("%s", gasto1Nome); 
        printf ("digite o valor do gasto 1: ");
        scanf ("%lf", &gasto1);

        do
        {
            printf ("você tem mais um Gasto a adicionar? (s/n): ");
            scanf (" %c", &adicionar_gasto); 

            if (adicionar_gasto == 's') 
            {
                printf ("digite o nome do seu segundo Gasto: ");
                scanf ("%s", gasto2Nome); 
                printf ("digite o valor do seu outro gasto: ");
                scanf ("%lf", &gasto2);
                printf("Gastos informados!\n");
            }

            else if (adicionar_gasto == 'n') 
            {
                printf ("Ok, gastos finalizados.\n");
            }
            else 
            {
                printf ("Erro!!! Responda apenas com 's' ou 'n'.\n");
            }
            
        } while (adicionar_gasto != 's' && adicionar_gasto != 'n'); 
        
        gastos_adicionais = gasto1 + gasto2;
        total_gastos_mes = gastos_basicos + gastos_adicionais;
        saldo_final = (salario + renda_extra) - total_gastos_mes;

        printf ("\n====================================\n");
        printf ("Gastos adicionais (R$ %.2f) atualizados!\n", gastos_adicionais); 
        printf ("Saldo recalculado!\n");
        printf ("\n====================================\n");
        break;

    case saldo_mensal_atual:
    if (saldo_final == (salario + renda_extra))
    {
        printf ("\n====================================\n");
        printf ("voce nao informou seus gastos!!!");
        printf ("\n====================================\n");

    } else if (saldo_final != (salario + renda_extra))
    {
    printf ("\n====================================\n");
    printf ("\nseus gastos atuais: %2.lf \n", total_gastos_mes);
    printf ("\nSeu saldo atual e de: %2.lf \n", saldo_final);
    printf ("\n====================================\n");

    }else {
        printf ("\n=====================================\n");
        printf ("\n======= Erro Desconhecido!! =========\n");
        printf ("\n=====================================\n");
    }
        break;
    case gastos_futuros:
    printf ("Esta opcao, nao esta disponivel!! em breve sera implementada!!");
        break;
    case sair:
        printf ("Obrigado por utilizar nosso sistema!!!\n");
        break;
    default:
    printf ("Opcao invalida! Tente novamente.\n");
        break;
    }
    } while (escolha != sair); 

    return 0;
}