#include <stdio.h>
#include <limits.h>

#define MAX_FUNCIONARIOS 10000
#define MAX_CLIENTES 10000

typedef struct{
  int tempoDisponivel;
  int tempoPorItem;
} Funcionario;

Funcionario funcionarios[MAX_FUNCIONARIOS];
int N, M;

void inicializaFuncionarios(){
  for(int i = 0; i < N; i++){
    funcionarios[i].tempoDisponivel = 0;
    scanf("%d", &funcionarios[i].tempoPorItem);
  }
}

void processaClientes(int clientes[]){
  for(int j = 0; j < M; j++){
    int funcionarioIndex = 0;
    for(int i = 1; i < N; i++){
      if(funcionarios[i].tempoDisponivel < funcionarios[funcionarioIndex].tempoDisponivel){
        funcionarioIndex = i;
      }
    }

    funcionarios[funcionarioIndex].tempoDisponivel += funcionarios[funcionarioIndex].tempoPorItem * clientes[j];
  }
}

int calculaTempoTotal(){
  int tempoTotal = 0;
  for(int i = 0; i < N; i++){
    if(funcionarios[i].tempoDisponivel > tempoTotal){
      tempoTotal = funcionarios[i].tempoDisponivel;
    }
  }
  return tempoTotal;
}

int main(){
  scanf("%d %d", &N, &M);

  int clientes[M];

  inicializaFuncionarios();

  for(int j = 0; j < M; j++){
    scanf("%d", &clientes[j]);
  }

  processaClientes(clientes);

  int tempoTotal = calculaTempoTotal();
  printf("%d\n", tempoTotal);

  return 0;
}