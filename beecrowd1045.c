#include <stdio.h>

int main(){
  double a, b, c, greater, smaller, mid;
  scanf("%lf %lf %lf", &a, &b, &c);

  if(a >= b && a >= c){
    greater = a;
    mid = (b >= c) ? b : c;
    smaller = (b >= c) ? c : b;
  }
  else if(b >= a && b >= c){
    greater = b;
    mid = (a >= c) ? a : c;
    smaller = (a >= c) ? c : a;
  }
  else{
    greater = c;
    mid = (a >= b) ? a : b;
    smaller = (a >= b) ? b : a;
  }

  if(greater >= mid + smaller){
    printf("NAO FORMA TRIANGULO\n");
  }
  else{
    if(greater * greater == mid * mid + smaller * smaller){
      printf("TRIANGULO RETANGULO\n");
    }
    if(greater * greater > mid * mid + smaller * smaller){
      printf("TRIANGULO OBTUSANGULO\n");
    }
    if(greater * greater < mid * mid + smaller * smaller){
      printf("TRIANGULO ACUTANGULO\n");
    }
    if(greater == mid && greater == smaller){
      printf("TRIANGULO EQUILATERO\n");
    }
    if((greater == mid && greater != smaller) || (mid == smaller && greater != smaller) || (greater == smaller && mid != smaller)){
      printf("TRIANGULO ISOSCELES\n");
    }
  }

  return 0;
}