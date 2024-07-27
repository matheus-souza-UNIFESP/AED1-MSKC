#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **splitString(char *str, int *count){
  char **result = 0;
  char *temp = strtok(str, " ");
  int spaces = 0;

  while(temp){
    result = realloc(result, sizeof(char*) * ++spaces);
    if(result == NULL)
      exit(-1);
    result[spaces-1] = temp;
    temp = strtok(NULL, " ");
  }
  *count = spaces;
  return result;
}

int main(){
  char linha1[256], linha2[256], linha3[256];

  fgets(linha1, 256, stdin);
  linha1[strcspn(linha1, "\n")] = 0;

  fgets(linha2, 256, stdin);
  linha2[strcspn(linha2, "\n")] = 0;

  fgets(linha3, 256, stdin);
  linha3[strcspn(linha3, "\n")] = 0;

  int countL, countN;
  char **listaAtual = splitString(linha1, &countL);
  char **novaLista = splitString(linha2, &countN);

  int indicadoIndex = -1;
  if(strcmp(linha3, "nao") != 0){
    for(int i = 0; i < countL; i++){
      if(strcmp(listaAtual[i], linha3) == 0){
        indicadoIndex = i;
        break;
      }
    }
  }

  for(int i = 0; i < countL; i++){
    if(i == indicadoIndex){
      for(int j = 0; j < countN; j++){
        printf("%s ", novaLista[j]);
      }
      
    }
    if(i == countL - 1 && indicadoIndex != -1){
      printf("%s", listaAtual[i]);
    }else{
      printf("%s ", listaAtual[i]);
    }
  }

  if(indicadoIndex == -1){
    for(int j = 0; j < countN; j++){
      if(j == countN - 1){
        printf("%s", novaLista[j]);
      }else{
        printf("%s ", novaLista[j]);
      }
    }
  }

  printf("\n");

  free(listaAtual);
  free(novaLista);

  return 0;
}