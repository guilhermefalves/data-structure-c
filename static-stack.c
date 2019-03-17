/*******************************************************************************
 * Uma pilha é uma estrutura de dados simples, que obedece a seguinte regra:
 *  LIFO - Last In First Out
 * 
 * Uma pilha dinamica pode ser vista como um lista linear simplesmente encadeada
 * assim não possui um tamanho definido e é necessário
 * 
 * Tendo as seguintes operações básicas:
 *      push  (insere um elemento no topo da pilha)
 *      pop   (remove o elemento do topo da pilha)
 *      empty (verifica se a pilha está vazia)
 *      full  (verifica se a pilha está cheia)
 * 
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int value;
    struct _node *next;
} node;

int empty(node *pilha)
{
    return (pilha == NULL) ? 1 : 0;
}

void push(node **pilha, int val)
{
    node *aux = (node *) malloc(sizeof(node *));
    aux->value = val;

    if (empty(*pilha)) {
        (*pilha) = aux;
    } else {
        aux->next = (*pilha);
        (*pilha) = aux;
        // free(aux);
    }
}

int pop(node **pilha)
{
    if ((*pilha)->next == NULL) {
        (*pilha) = NULL;
        return 0;
    }

    node *l  = (*pilha);
    (*pilha) = (*pilha)->next;
    free(l);

    return (*pilha)->value;
}

void imprime(node *pilha)
{
    if (empty(pilha)) {
        printf("empty");
        return;
    }

    printf("stack: ");
    do {
        printf("%d ", pilha->value);
        pilha = pilha->next;
    } while(pilha != NULL);
}

int main()
{
    node *pilha = NULL;

    push(&pilha, 5);
    push(&pilha, 3);
    push(&pilha, 1);
    push(&pilha, 1);

    // pop(&pilha);
    // pop(&pilha);
    // pop(&pilha);
    // pop(&pilha);

    imprime(pilha);
    return 0;
}