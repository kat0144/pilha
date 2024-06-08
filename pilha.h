#ifndef BINARIO_DECIMAL_H
#define BINARIO_DECIMAL_H
#include <stdlib.h>


struct pilha { // usa-se registradores para facilitar as informações sobre a pilha
    int topo; // posição de um elemento
    int c; // capacidade máxima da pilha
    int *pilha; // vetor pilha que será manipulado
};

void criarpilha (struct pilha *p, int capacidade) { // criação dos elementos
    p->topo = -1; // vazio
    p->c = capacidade;
    p->pilha = (int *) malloc(capacidade * sizeof(int));// alocação dinâmica da memória para o vetor pilha, cria um vetor de n capacidades

    if (p->pilha == NULL) { // verificar se a alocação foi bem-sucedida*
        printf("Erro ao alocar memória para a pilha\n");
        exit(EXIT_FAILURE);
    }
}

void imprime (struct pilha *p) { // imprime os valores da tela
    printf ("Os valores que estão na pilha são:\n");

    for (int i = 0; i < (p->topo+1); i++) {
        printf("Posição %d: %d.\n", i+1, p->pilha[i]);
    }
}

int full (struct pilha *p) { // verificação da pilha - tratamento do stackoverflow
    if ((p->topo) == (p->c - 1)) { // pilha está cheia
        return -1;
    }
    else {
        return (p->c - (p->topo + 1)); // retorna a qtd de espaços vazios na pilha
    }
}

int empty (struct pilha *p) { // verificação da pilha - tratamento do stackunderflow
    if (p->topo == -1) {
        return -1; // pilha está vazia
    }
    else {
        return (p->topo+1); // pilha contém elementos, logo ela retornará a qtd de elementos
        }
    }

int stackptop (struct pilha *p) { // determina o valor do topo da pilha
    int verificador;

    verificador = empty (p);

    if (verificador == -1) { // verifica se pilha está vazia
        return -1; // pilha está vazia
    }
        else {
            return p->pilha [p->topo]; // retorna o valor que está no posição topo
        }
    }

void push (struct pilha *p, int numeroincluido) { // inclui novos elementos na pilha

    p->topo++; // aumenta a posição do vetor pilha
    p->pilha [p->topo] = numeroincluido; // inclui o novo numero na pilha
}

int pop (struct pilha *p) {  // retira elementos da pilha (topo)
    int aux;

     if (p->topo == -1) {
         return -1; // não tem elementos para serem retirados
     }
     else {
        aux = p->pilha [p->topo]; // aux recebe o valor retirado
        p->topo--; // decrementa a pilha
        return aux; // retorna o valor retirado
     }
}

#endif //PILHA_PILHA_H
