#include <stdio.h>
#include <stdlib.h>
int main()
{
printf("==========================================\n");
printf("= Sistema de Controle de Fluxo de Pedagio\n");
printf("==========================================\n");
int fluxo_carros[7];
const char *dias_semana[7] = {
"Segunda-feira", "Terca-feira", "Quarta-feira",
"Quinta-feira", "Sexta-feira", "Sabado", "Domingo"};
printf("Digite o fluxo de carros para cada dia da semana:\n");
for (int i = 0; i < 7; i++)
{
printf("%s: ", dias_semana[i]);
scanf("%d", &fluxo_carros[i]);
}
int maior_fluxo = 0;
int dia_pico = 0;
maior_fluxo = fluxo_carros[0];
for (int i = 0; i < 7; i++)
{
if (fluxo_carros[i] > maior_fluxo)
{
maior_fluxo = fluxo_carros[i];
dia_pico = i;
}
}
printf("\n\n=================================================\n");
printf(" RELATORIO DE FLUXO SEMANAL\n");
printf("=================================================\n");
// =================================================================
// RELATORIO DE FLUXO SEMANAL (Versão Simples com if/else)
// =================================================================
printf("\n\n=================================================\n");
printf(" RELATORIO DE FLUXO SEMANAL\n");
printf("=================================================\n");
for (int i = 0; i < 7; i++) {
if (i == dia_pico) {
printf("-> %-15s: %d carros (DIA DE PICO!)\n", dias_semana[i], fluxo_carros[i]);
} else {
printf(" %-15s: %d carros\n", dias_semana[i], fluxo_carros[i]);
}
}
printf("-------------------------------------------------\n");
printf("Resumo: O dia de maior fluxo foi %s com %d carros.\n", dias_semana[dia_pico],
maior_fluxo);
printf("=================================================\n");
return 0;
}
