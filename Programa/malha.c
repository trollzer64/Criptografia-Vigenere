#include <stdio.h>

int main() {

  int m, n, o;
  char malha[26][26], alfabeto[26], chave[255], frase[255];

  for (m = 0; m < 26; m++) {
    alfabeto[m]=97+m;
  }

  for (n = 0; n < 26; n++) {
    for (m = 0; m < 26; m++) {
      if (m+n<26) {
        malha[m][n]=alfabeto[m+n];
      }
      else{
        malha[m][n]=alfabeto[m+n-26];
      }
    }
  }

  printf("\n\n   ");
  for (m = 0; m < 26; m++) {
    printf("%c ", alfabeto[m]);
  }
  printf("\n  %c", 197);
  for (m = 0; m < 26; m++) {
    printf("%c%c", 196, 196);
  }
  printf("\n");
  for (n = 0; n < 26; n++) {
    printf("%c %c", alfabeto[n], 179);
    for (m = 0; m < 26; m++) {
      printf("%c ", malha[m][n]);
    }
    printf("\n  %c\n", 179);
  }

  return 0;
}
