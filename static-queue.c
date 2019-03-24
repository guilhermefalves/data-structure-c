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
 *      isFull  (verifica se a fila está cheia)
 * 
 ******************************************************************************/
#include <stdio.h>
#define queueSize 2

/**
 * increment the first or last element count
 * @param int position - the value to be incremented
 * @return int - the value incremented
 */
int incrementPosition(int position)
{
    return (position != queueSize) ? position + 1 : 0;
}

/**
 * checks if the queue is full
 * @param int firstElement - the start of the queue
 * @param *int lastElement - the end of the queue
 */
int isFull(int firstElement, int lastElement)
{
    if (lastElement > firstElement) {
        return (lastElement - firstElement == queueSize);
    }

    int size = 0;
    while (firstElement != lastElement) {
        size++;
        firstElement = incrementPosition(firstElement);
    }
    return (size == queueSize);
}

/**
 * checks if the queue is empty
 * @param int firstElement - the start of the queue
 * @param *int lastElement - the end of the queue
 * @return int (bool)
 */
int isEmpty(int firstElement, int lastElement)
{
    return (firstElement == lastElement);
}

/**
 * add elements to queue
 * @param int **queue      - a pointer to array that stores the queue
 * @param int firstElement - the start of the queue
 * @param *int lastElement - a pointer to variable that stores the end of queue
 * @param int value        - the value to be inserted
 */
int enqueue(int (*queue)[queueSize], int firstElement, int *lastElement, int value)
{
    if (isFull(firstElement, (*lastElement))) {
        return -1;
    }

    (*queue)[(*lastElement)] = value;
    (*lastElement) = incrementPosition((*lastElement));
}

/**
 * remove an element of the queue and return your value
 * @param *int queue    - the array that stores the queue
 * @param *firstElement - a pointer to variable that stores the start of queue
 * @param lastElement   - the end of the queue
 */
int dequeue(int *queue, int *firstElement, int lastElement)
{
    if (isEmpty((*firstElement), lastElement)) {
        return -1;
    }

    (*firstElement) = incrementPosition((*firstElement));

    return queue[(*firstElement) - 1];
}

/**
 * prints the values stored in the queue
 * @param *int queue   - the array that stores the queue
 * @param firstElement - the start of the queue
 * @param lastElement  - the end of the queue
 */
void print(int *queue, int firstElement, int lastElement)
{
    if (isEmpty(firstElement, lastElement)) {
        printf("Queue is empty\n");
        return;
    }

    while (firstElement != lastElement) {
        printf("%d ", queue[firstElement]);
        firstElement = incrementPosition(firstElement);
    }
    printf("\n");
}

int main()
{
    int queue[queueSize];
    int firstElement = 0, lastElement = 0;
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
                int added = enqueue(&queue, firstElement, &lastElement, value);
                if (added == -1) {
                    printf("Queue is full\n");
                }
                break;
            case 2:
                removed = dequeue(queue, &firstElement, lastElement);
                if (removed == -1) {
                    printf("Queue is empty\n");
                    break;
                }
                printf("Removed: %d\n", removed);
                break;
            case 3:
                print(queue, firstElement, lastElement);
                break;
            default:
                return 0;
        }
    }

    return 0;
}

