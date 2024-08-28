#include <stdio.h>

int main(){
  int size, row, col;

  while(1){

    scanf("%d", &size);
    int matrix[size][size];

    if(size == 0)
      return 0;

    for(row = 0; row < size; row++){
      for(col = 0; col < size; col++){
        if(row == col)
          matrix[row][col] = 1;
        else if(row < col)
          matrix[row][col] = col - row + 1;
        else
          matrix[row][col] = row - col + 1;
      }
    }

    for(row = 0; row < size; row++){
      for(col = 0; col < size; col++){
        if(col == 0)
          printf("%3d", matrix[row][col]);
        else
          printf(" %3d", matrix[row][col]);
      }
      printf("\n");
    }

    printf("\n");
  }
}