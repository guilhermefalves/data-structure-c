/*******************************************************************************
 * Uma fila é uma estrutura de dados simples, que obedece a seguinte regra:
 *  FIFO - Firts In First Out
 * 
 * Uma fila estática pode ser entendida como um vetor, trabalhando em conjunto
 * com uma variavel que indicará o primeiro elemento da fila.
 * 
 * Tendo as seguintes operações básicas:
 *      enqueue (insere um elemento no final da fila)
 *      dequeue (remove o primeiro elemento da fila)
 *      isEmpty (verifica se a fila está vazia)
 * 
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} node;

/**
 * checks if the queue is empty
 * @param node *queue - the queue to be verified
 * @return int (bool)
 */
int isEmpty(node *queue)
{
    return (queue == NULL);
}

/**
 * add elements to queue
 * @param node **queue - the queue to be incremented
 * @param int value    - the value to be inserted
 */
void enqueue(node **queue, int value)
{
    node *new  = (node *)malloc(sizeof(node));
    new->next  = NULL;
    new->value = value;
    if (isEmpty((*queue))) {
        (*queue) = new;
        return;
    }

    (*queue)->next = new;
}

/**
 * remove an element of the queue and return your value
 * @param **node queue - the queue to be decremented
 * @return int valeu   - the value removed
 */
int dequeue(node **queue)
{
    node *bin = (*queue);
    int value = (*queue)->value;
    (*queue)  = (*queue)->next;
    free(bin);
    return value;
}

/**
 * prints the values stored in the queue
 * @param *node queue - the queue to printed
 */
void print(node *queue)
{
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    while(queue != NULL) {
        printf("%d ", queue->value);
        queue = queue->next;
    }
    printf("\n");
}

int main()
{
    node *queue = NULL;
    int option, value, removed, added;
    while (1==1) {
        printf("1) add element to queue\n");
        printf("2) remove element of queue\n");
        printf("3) print queue\n");
        printf("*) exit\n");
        scanf("%d", &option);
        switch (option)
        {
            case 1:
                printf("Insert the element: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;
            case 2:
                removed = dequeue(&queue);
                if (removed == -1) {
                    printf("Queue is empty\n");
                    break;
                }
                printf("Removed: %d\n", removed);
                break;
            case 3:
                print(queue);
                break;
            default:
                return 0;
        }
    }

    return 0;
}