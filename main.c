#include <stdio.h>
#include "pilha.h"


int main() {
    struct pilha minhapilha; // define o nome do registrador que será utilizado no programa;

    int capacidade, op = 0, elemento, valor, qtdvalores, verificador;

    printf ("Informe a capacidade da pilha: ");
    scanf ("%d", &capacidade);

    criarpilha (&minhapilha, capacidade); // criação da pilha

    while (op != 7) { // menu de opcções, na qual o usuário escolhe o que deseja fazer
        printf("Informe a opção desejada:\n");
        printf("1. Incluir elemento.\n");
        printf("2. Retirar elemento.\n");
        printf("3. Verificar se a pilha está vazia.\n");
        printf("4. Imprimir os valores que estão dentro da pilha.\n");
        printf("5. Mostrar o último elemento da pilha.\n");
        printf("6. Encerrar o programa.\n");

        scanf("%d", &op);

        switch (op) {

            case 1: { // inclui o elemento

                verificador = full(&minhapilha);

                if (verificador == -1) {
                    printf("Não será possível incluir mais elementos, a pilha está cheia!\n");
                }
                else {
                    printf("A pilha contém %d espaços vazios.\n", verificador);

                    printf("Informe um valor para ser inserido na pilha: \n");
                        scanf("%d", &elemento);
                        push(&minhapilha, elemento);
                }
                break;

            }

            case 2: { // retira o primeiro elemento (LIFO)
                valor = pop(&minhapilha);

                if (valor == -1) {
                    printf("A pilha está vazia! Não será possível retirar nenhum elemento.\n");
                }
                else {
                    printf("O valor retirado foi: %d\n", valor);
                }
                break;
            }

            case 3: { // verifica-se se a pilha está vazia
                verificador = empty(&minhapilha);

                if (verificador == -1) {
                    printf("A pilha está vazia!\n");
                }
                else {
                    printf("A pilha contém %d elementos.\n", verificador);
                }
                break;
            }

            case 4: { // imprime os valores na tela
                verificador = empty(&minhapilha);

                if (verificador == -1) {
                    printf("A pilha está vazia, não há valores para serem imprimidos.\n");
                }
                else {
                    imprime(&minhapilha);
                }
                break;
            }

            case 5: { // mostra o último elemento
                valor = stackptop(&minhapilha);

                printf("O último valor presente na pilha é: %d.\n", valor);
                break;
            }

            case 6: { // encerra o programa
                op = 7;
                break;
            }
        }
    }

    return 0;
}
