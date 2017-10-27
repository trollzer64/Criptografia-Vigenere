#include <stdio.h>
#include <stdlib.h>

enum boolean {
  true = 1, false = 0
};
typedef  enum boolean  bool;
int main(){

  bool exit=false;
  int l, m, n, o;
  char malha[26][26];
  char chave[255], frase[255];
  char menu;
  int num_chave, num_frase;

  for (m = 0; m < 26; m++) {//Alfabeto//
    malha[m][0]=97+m;
  }

  for (n = 0; n < 26; n++) {//Malha de criptografia//
    for (m = 0; m < 26; m++) {
      if (m+n<26) {
        malha[m][n]=malha[m+n][0];
      }
      else{
        malha[m][n]=malha[m+n-26][0];
      }
    }
  }

  while (exit==false) {
    printf("Digite a chave (at%c 254 caracteres): ", 130);
    scanf(" %[^\n]s", chave);
    setbuf(stdin, NULL);
    num_chave=0;
    while(chave[num_chave]!='\0'){
       num_chave++;
    }
    for (o = 0; o < num_chave; o++) {
      if ((chave[o]>64)&&(chave[o]<91)) {
        chave[o]+=32;
      }
    }

    printf("Digite a frase (at%c 254 caracteres): ", 130);
    scanf(" %[^\n]s", frase);
    setbuf(stdin, NULL);
    num_frase=0;
    while(frase[num_frase]!='\0'){
       num_frase++;
    }
    bool varia_frase[num_frase];
    for (o = 0; o < num_frase; o++) {
      if ((frase[o]>64)&&(frase[o]<91)) {
        varia_frase[o]=true;
        frase[o]+=32;
      } else {
        varia_frase[o]=false;
      }
    }

    printf("\nCriptografar ou descriptografar? (C/D)\nEscolha: ");
    scanf(" %c", &menu);
    setbuf(stdin, NULL);
    if ((menu=='C')||(menu=='c')) {
      printf("\nCriptografando...\n");
      l=0;
      for (o = 0; frase[o]!='\0'; o++) {
        if (l==num_chave) {
          l=0;
        }
        if ((frase[o]>96)&&(frase[o]<123)) {
          while ((chave[l]<97)&&(chave[l]>122)) {
            l++;
          }
          for (m = 0; m < 26; m++) {
            if (malha[m][0]==chave[l]) {
              for (n = 0; n < 26; n++) {
                if (malha[0][n]==frase[o]) {
                  frase[o]=malha[m][n];
                  m=26;
                  n=26;
                }
              }
            }
          }
          l++;
        }
      }

      printf("\nFrase criptografada: ");
    }
    else if ((menu=='D')||(menu=='d')) {
      printf("\nDescriptografando...\n");
      l=0;
      for (o = 0; frase[o]!='\0'; o++) {
        if (l==num_chave) {
          l=0;
        }
        if ((frase[o]>96)&&(frase[o]<123)) {
          while ((chave[l]<97)&&(chave[l]>122)) {
            l++;
          }
          for (m = 0; m < 26; m++) {
            if (malha[m][0]==chave[l]) {
              for (n = 0; n < 26; n++) {
                if (malha[m][n]==frase[o]) {
                  frase[o]=malha[0][n];
                  m=26;
                  n=26;
                }
              }
            }
          }
          l++;
        }
      }
      printf("\nFrase descriptografada: ");
    }

    for (o = 0; o < num_frase; o++) {
      if (varia_frase[o]==true) {
        frase[o]-=32;
      }
    }
    for (o = 0; o < num_frase; o++) {
      printf("%c", frase[o]);
    }

    printf("\n\nContinuar? (S/N)\nEscolha: ");
    scanf(" %c", &menu);
    setbuf(stdin, NULL);
    if ((menu=='S')||(menu=='s')) {
      printf("\n");
    } else {
      exit=true;
    }
    system("cls");
  }

  return 0;
}
