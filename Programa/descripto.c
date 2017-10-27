#include <stdio.h>
#include <stdlib.h>

enum boolean {
    true = 1, false = 0
};
typedef  enum boolean  bool;
int main(){

  bool exit=false;
  int l, m, n, o;
  char malha[26][26], alfabeto[26];
  char chave[255], frase[255];
  int num_chave, num_frase;


  for (m = 0; m < 26; m++) {
    alfabeto[m]=97+m;
  }//Alfabeto//

  for (n = 0; n < 26; n++) {
    for (m = 0; m < 26; m++) {
      if (m+n<26) {
        malha[m][n]=alfabeto[m+n];
      }
      else{
        malha[m][n]=alfabeto[m+n-26];
      }
    }
  }//Malha de criptografia//

  while (exit==false) {
    printf("Digite a chave (at%c 254 caracteres): ", 130);
    scanf(" %[^\n]s", chave);
    setbuf(stdin, NULL);
    num_chave=0;
    while(chave[num_chave]!='\0'){
       num_chave++;
    }
    bool case_chave[num_chave];
    for (o = 0; o < num_chave; o++) {
      if ((chave[o]>64)&&(chave[o]<91)) {
        case_chave[o]=true;
        chave[o]+=32;
      } else {
        case_chave[o]=false;
      }
    }

    printf("Digite a frase (at%c 254 caracteres): ", 130);
    scanf(" %[^\n]s", frase);
    setbuf(stdin, NULL);
    num_frase=0;
    while(frase[num_frase]!='\0'){
       num_frase++;
    }
    bool case_frase[num_frase];
    for (o = 0; o < num_frase; o++) {
      if ((frase[o]>64)&&(frase[o]<91)) {
        case_frase[o]=true;
        frase[o]+=32;
      } else {
        case_frase[o]=false;
      }
    }

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

    printf("\nFrase criptografada: ");
    for (o = 0; o < num_frase; o++) {
      if (case_frase[o]==true) {
        printf("%c", frase[o]-32);
      } else {
        printf("%c", frase[o]);
      }
    }

    printf("\nContinuar? (S/N)\n");
    scanf("%s", chave);
    if ((chave[0]=='S')||(chave[0]=='s')) {
    } else if ((chave[0]=='N')||(chave[0]=='n')) {
      exit=true;
    } else {
      printf("Considerarei que esta saindo\n");
      exit=true;
    }


    //Verificação//

    printf("\n\nCaracteres na Chave: %d", num_chave);
    printf("\nCaracteres na Frase: %d", num_frase);
    printf("\nChave convertida: %s", chave);
    printf("\nChave transformada: ");
    for (o = 0; o < num_chave; o++) {
      if (case_chave[o]==true) {
        printf("%c", chave[o]-32);
      } else {
        printf("%c", chave[o]);
      }
    }
    printf("\nFrase convertida: %s", frase);
    printf("\nFrase transformada: ");
    for (o = 0; o < num_frase; o++) {
      if (case_frase[o]==true) {
        printf("%c", frase[o]-32);
      } else {
        printf("%c", frase[o]);
      }
    }
  }

  return 0;
}
