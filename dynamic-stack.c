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

/**
 * Check if the stack is empty
 * @param stack - the stack to be verified
 */
int empty(node *stack)
{
    return (stack == NULL) ? 1 : 0;
}

/**
 * Add element to a stack
 * @param stack - the stack to be incremented
 * @param val   - the new value
 */
void push(node **stack, int val)
{
    node *aux = (node *) malloc(sizeof(node *));
    aux->value = val;

    if (empty(*stack)) {
        (*stack) = aux;
    } else {
        aux->next = (*stack);
        (*stack) = aux;
    }
}

/**
 * Remove and return the last element of a stack
 */
int pop(node **stack)
{
    if ((*stack)->next == NULL) {
        (*stack) = NULL;
        return 0;
    }

    node *bin  = (*stack);
    (*stack) = (*stack)->next;
    free(bin);

    return (*stack)->value;
}

/**
 * shows the stack on screen
 */
void print(node *stack)
{
    if (empty(stack)) {
        printf("empty");
        return;
    }

    printf("stack: ");
    do {
        printf("%d ", stack->value);
        stack = stack->next;
    } while(stack != NULL);
}

int main()
{
    node *stack = NULL;

    push(&stack, 5);
    push(&stack, 3);
    push(&stack, 1);
    push(&stack, 1);

    pop(&stack);
    pop(&stack);
    pop(&stack);

    print(stack);
    return 0;
}