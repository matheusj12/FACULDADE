#include <stdio.h>

int main() {
    // Variáveis para armazenar as atividades de cada dia da semana
    int atividade_segunda, atividade_terca, atividade_quarta, atividade_quinta, atividade_sexta, atividade_sabado, atividade_domingo;
    int opcao;

    printf("Rotina de atividade fisica semanal\n");
    printf("Este programa registra quantas atividades fisicas voce fez em cada dia da semana.\n");

    // Entrada de dados com validação para impedir números negativos
    do {
        printf("Escreva quantas atividades voce executou na segunda-feira: ");
        scanf("%d", &atividade_segunda);
        if (atividade_segunda < 0) printf("Digite um valor valido (maior ou igual a zero).\n");
    } while (atividade_segunda < 0);

    do {
        printf("Escreva quantas atividades voce executou na terca-feira: ");
        scanf("%d", &atividade_terca);
        if (atividade_terca < 0) printf("Digite um valor valido (maior ou igual a zero).\n");
    } while (atividade_terca < 0);

    do {
        printf("Escreva quantas atividades voce executou na quarta-feira: ");
        scanf("%d", &atividade_quarta);
        if (atividade_quarta < 0) printf("Digite um valor valido (maior ou igual a zero).\n");
    } while (atividade_quarta < 0);

    do {
        printf("Escreva quantas atividades voce executou na quinta-feira: ");
        scanf("%d", &atividade_quinta);
        if (atividade_quinta < 0) printf("Digite um valor valido (maior ou igual a zero).\n");
    } while (atividade_quinta < 0);

    do {
        printf("Escreva quantas atividades voce executou na sexta-feira: ");
        scanf("%d", &atividade_sexta);
        if (atividade_sexta < 0) printf("Digite um valor valido (maior ou igual a zero).\n");
    } while (atividade_sexta < 0);

    do {
        printf("Escreva quantas atividades voce executou no sabado: ");
        scanf("%d", &atividade_sabado);
        if (atividade_sabado < 0) printf("Digite um valor valido (maior ou igual a zero).\n");
    } while (atividade_sabado < 0);

    do {
        printf("Escreva quantas atividades voce executou no domingo: ");
        scanf("%d", &atividade_domingo);
        if (atividade_domingo < 0) printf("Digite um valor valido (maior ou igual a zero).\n");
    } while (atividade_domingo < 0);

    // Loop principal do menu
    do {
        printf("\nMenu\n");
        printf("1 - Mostrar atividades da segunda\n");
        printf("2 - Mostrar atividades da terca\n");
        printf("3 - Mostrar atividades da quarta\n");
        printf("4 - Mostrar atividades da quinta\n");
        printf("5 - Mostrar atividades da sexta\n");
        printf("6 - Mostrar atividades do sabado\n");
        printf("7 - Mostrar atividades do domingo\n");
        printf("8 - Mostrar atividades da semana e Top Day\n");
        printf("9 - Sair\n");

        // Validação da opção do menu
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        if (opcao < 1 || opcao > 9) {
            printf("Opcao invalida. Tente novamente.\n");
            continue; // Volta para o início do loop se a opção for inválida
        }

        // Estrutura de decisão para tratar as opções do menu
        switch (opcao) {
            case 1:
                printf("Atividades da segunda-feira: %d\n", atividade_segunda);
                break;
            case 2:
                printf("Atividades da terca-feira: %d\n", atividade_terca);
                break;
            case 3:
                printf("Atividades da quarta-feira: %d\n", atividade_quarta);
                break;
            case 4:
                printf("Atividades da quinta-feira: %d\n", atividade_quinta);
                break;
            case 5:
                printf("Atividades da sexta-feira: %d\n", atividade_sexta);
                break;
            case 6:
                printf("Atividades do sabado: %d\n", atividade_sabado);
                break;
            case 7:
                printf("Atividades do domingo: %d\n", atividade_domingo);
                break;
            case 8: {
                // Calcula o total de atividades e identifica o Top Day
                int total = atividade_segunda + atividade_terca + atividade_quarta + atividade_quinta + atividade_sexta + atividade_sabado + atividade_domingo;
                int atividades[7] = {atividade_segunda, atividade_terca, atividade_quarta, atividade_quinta, atividade_sexta, atividade_sabado, atividade_domingo};
                char *dias[7] = {"Segunda-feira", "Terca-feira", "Quarta-feira", "Quinta-feira", "Sexta-feira", "Sabado", "Domingo"};
                int i, max = atividades[0], top_day = 0;
                for (i = 1; i < 7; i++) {
                    if (atividades[i] > max) {
                        max = atividades[i];
                        top_day = i;
                    }
                }
                printf("Total de atividades da semana: %d\n", total);
                printf("Top Day: %s com %d atividades!\n", dias[top_day], max);
                break;
            }
            case 9:
                printf("Obrigado por usar o programa! Ate a proxima.\n");
                break;
        }
    } while (opcao != 9);

    return 0;
}
