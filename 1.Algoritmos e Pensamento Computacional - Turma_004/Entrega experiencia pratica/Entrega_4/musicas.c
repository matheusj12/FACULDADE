#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimirLista(const char* titulo, const char* musicas[], int audicao[], int tamanho) {
    printf("%s\n", titulo);
    for (int i = 0; i < tamanho; i++) {
        printf("%s - %d\n", musicas[i], audicao[i]);
    }
    printf("\n");

}

int main(){

  const char* musicas[] = {
      "Imagine - John Lennon",
      "Bohemian Rhapsody - Queen",
      "Stairway to Heaven - Led Zeppelin",
      "Hotel California - Eagles",
      "Hey Jude - The Beatles",
      "Like a Rolling Stone - Bob Dylan",
      "Smells Like Teen Spirit - Nirvana",
      "Billie Jean - Michael Jackson",
      "Sweet Child O' Mine - Guns N' Roses",
      "Rolling in the Deep - Adele"
  };

int audicao[] = {150, 200, 180, 220, 300, 250, 275, 400, 350, 320};
int N = sizeof(musicas) / sizeof(musicas[0]);

  imprimirLista("================audicoes================", musicas, audicao, N);

  for (int i = 0; i < N - 1; i++) {
      for (int j = 0; j < N - i - 1; j++) {
          if (audicao[j] < audicao[j + 1]) {

              int tempAudicao = audicao[j];
              audicao[j] = audicao[j + 1];
              audicao[j + 1] = tempAudicao;

              const char* tempMusica = musicas[j];
              musicas[j] = musicas[j + 1];
              musicas[j + 1] = tempMusica;
        }
    }
}

 imprimirLista("\n===== AUDIÊNCIA EM ORDEM DECRESCENTE (RANKING) =====", musicas, audicao, N);

    printf("\n===== AUDIÊNCIA EM ORDEM CRESCENTE (MENOS OUVIDAS) ====\n");
    for (int i = N - 1; i >= 0; i--) {
        printf("  %-25s: %d reproduções\n", musicas[i], audicao[i]);
    }
    printf("------------------------------------------------------\n");

    return 0;
}
