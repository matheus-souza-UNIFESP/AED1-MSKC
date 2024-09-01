#include <stdio.h>
#include <string.h>

#define MAX 30

int main() {
  char country[MAX];
  while(1) {
    if(fgets(country, sizeof(country), stdin) == NULL)
      break;

    country[strcspn(country, "\n")] = '\0';

    if(strlen(country) == 0)
      break;
    
    if(!strcmp(country, "brasil") || !strcmp(country, "portugal"))
      printf("Feliz Natal!\n");
    else if(!strcmp(country, "alemanha"))
      printf("Frohliche Weihnachten!\n");
    else if(!strcmp(country, "austria"))
      printf("Frohe Weihnacht!\n");
    else if(!strcmp(country, "coreia"))
      printf("Chuk Sung Tan!\n");
    else if(!strcmp(country, "espanha") || !strcmp(country, "argentina") || !strcmp(country, "chile")
    || !strcmp(country, "mexico"))
      printf("Feliz Navidad!\n");
    else if(!strcmp(country, "grecia"))
      printf("Kala Christougena!\n");
    else if(!strcmp(country, "estados-unidos") || !strcmp(country, "inglaterra")
    || !strcmp(country, "australia") || !strcmp(country, "antardida") || !strcmp(country, "canada"))
      printf("Merry Christmas!\n");
    else if(!strcmp(country, "suecia"))
      printf("God Jul!\n");
    else if(!strcmp(country, "turquia"))
      printf("Mutlu Noeller\n");
    else if(!strcmp(country, "irlanda"))
      printf("Nollaig Shona Dhuit!\n");
    else if(!strcmp(country, "belgica"))
      printf("Zalig Kerstfeest!\n");
    else if(!strcmp(country, "italia") || !strcmp(country, "libia"))
      printf("Buon Natale!\n");
    else if(!strcmp(country, "siria") || !strcmp(country, "marrocos"))
      printf("Milad Mubarak!\n");
    else if(!strcmp(country, "japao"))
      printf("Merii Kurisumasu!\n");
    else
      printf("--- NOT FOUND ---\n");
  }
  
  return 0;
}