#include <stdio.h>

int main(void){
  double v[3];
  
  for(int i = 0; i < 3; i++){
    scanf("%lf", &v[i]);
  }
 
  printf("MEDIA = %.1lf\n", (2*v[0] + 3*v[1] + 5*v[2]) / 10);
  
  return 0;
}