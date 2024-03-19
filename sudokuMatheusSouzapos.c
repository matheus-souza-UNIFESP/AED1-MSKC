#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>


bool checkRange(int sudokuBoard[9][9]);
bool checkLine(int sudokuBoard[9][9]);
bool checkColumn(int sudokuBoard[9][9]);
bool checkBlock(int sudokuBoard[9][9]);
bool checkSudoku(int sudokuBoard[9][9]);

int main(void) {

  int k = 0 ;
  scanf("%d", &k);
  
  int sudokuBoard[k][9][9]; //k sendo o numero de instancias 
  for(int n = 0; n < k; n++){
    for(int i = 0; i < 9; i++){
      for(int j = 0; j < 9; j++){
        scanf("%d", &sudokuBoard[n][i][j]);
      }
    }
  }

  for(int n = 0; n < k; n++){
    if(checkSudoku(sudokuBoard[n])){
      printf("Instancia %d\nSIM\n\n", n+1);
    }
    else{
      printf("Instancia %d\nNAO\n\n", n+1);
    }
  }
  
  return 0;
}


bool checkRange(int sudokuBoard[9][9]){
  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      if(sudokuBoard[i][j] < 1 || sudokuBoard[i][j] > 9){
        return false;
      }
    }
  }

  return true;
}

bool checkLine(int sudokuBoard[9][9]){
  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      for(int k = j+1; k < 9; k++){
        if(sudokuBoard[i][j] == sudokuBoard[i][k]){ //verifica se o numero se repete na linha
          return false;
        }
      }
    }
  }

  return true;
}

bool checkColumn(int sudokuBoard[9][9]){
  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      for(int k = j+1; k < 9; k++){
        if(sudokuBoard[j][i] == sudokuBoard[k][i]){ //verifica se o numero se repete na coluna
          return false;
        }
      }
    }
  }

  return true;
}

bool checkBlock(int sudokuBoard[9][9]){
  for(int a = 0; a < 9; a+=3){
    for(int b = 0; b < 9; b+=3){
      bool numberCounter[9] = {false};
      for(int i = a; i < a+3; i++){
        for(int j = b; j < b+3; j++){
          if(!numberCounter[sudokuBoard[i][j] - 1]){
            numberCounter[sudokuBoard[i][j] - 1] = true;
          }
          else{
            return false;
          }
        }
      }
    }
  }
  return true;
}

bool checkSudoku(int sudokuBoard[9][9]){
  if(!checkRange(sudokuBoard)){
    return false;
  }

  if(!checkLine(sudokuBoard)){
    return false;
  }

  if(!checkColumn(sudokuBoard)){
    return false;
  }

  if(!checkBlock(sudokuBoard)){
    return false;
  }

  return true;
}