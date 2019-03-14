#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char val;
    struct node* next;
} node;

#define sizePilha
int len(char *string);
void push(node **pilha, char value);
char pop(node **pilha);
void imprime(node *pilha);
int isOperator(char c);
int getPriority(char c);

int main()
{
    node *p = NULL;

    char expr[30];
    scanf("%s", expr);
    int exprLen = len(expr);

    node *pOperandos = NULL, *pOperadores = NULL;
    node *pExpr = NULL;
    int inParenthese = 0;
    
    /**
     * Percorre os caracteres lidos, sendo possível um dos seguintes casos:
     *  1) operando  -> deve ser impresso
     *  2) '('       -> push
     *  3) ')'       -> pop até encontrar o '('
     *  4) operador mais prioritario que o elemento da pilha  -> pop e imprime até ter menos prioridade
     *  4.1) chegou em um operador com menos prioridade -> push
     */
    for (int i = 0; i < exprLen; i++) {
        char c = expr[i];
        // 1) imprime direto operando
        if (!isOperator(c)) {
            printf("%c", c);
            continue;
        }

        // 2) adiciona o parentese na pilha
        if (c == '(') {
            push(&pOperadores, c);
            continue;
        }

        // 3) remove e imprime os operadores até encontrar o '('
        if (c == ')') {
            // removo os operadores até encontrar o )
            while(pOperadores != NULL && pOperadores->val != '(') {
                printf("%c", pop(&pOperadores));
            }

            // removo o (
            pop(&pOperadores);
            continue;
        }

        // 4.1) Imprimo elementos da pilha até chegar em um com maior prioridade
        while (pOperadores != NULL && getPriority(pOperadores->val) >= getPriority(c)) {
            printf("%c", pop(&pOperadores));
        }

        // 4.2) Adiciono o elemento na pilha
        push(&pOperadores, c);
    }

    // imprime os operadores que ainda estão na pilha
    while (pOperadores != NULL) {
        printf("%c", pop(&pOperadores));
    }
}

/**
 * Returns the size of pointer of char received 
 * Retorna o tamanho do ponteiro de char recebido
 */
int len(char *string)
{
    int len = 0;
    while(string[len] != '\0') {
        len++;
    }
    return len;
}

/**
 * Add an element to a stack
 * Adiciona um elemento (value) na pilha
 */
void push(node **pilha, char value)
{
    node *new = (node *) malloc(sizeof(node *));
    new->val = value;
    
    new->next = (*pilha);
    (*pilha) = new;
}

/**
 * Remove an elemento to a stack and returns your value
 * Remove um elemento de uma pilha e retorna deu valor
 */
char pop(node **pilha)
{
    node *bin = (*pilha);
    char val  = (*pilha)->val;
    (*pilha)  = (*pilha)->next;
    free(bin);

    return val;
}

/**
 * Checks if the element received is an operator
 * Verifica se o elemento recebido é um operador
 */
int isOperator(char c)
{
    return
        c == '^' ||
        c == '*' || c == '/' ||
        c == '-' || c == '+' ||
        c == '(' || c == ')';
}

/**
 * From an operator returns your priority
 * A partir de um operador, retorna sua prioridade
 */
int getPriority(char c)
{
    switch(c) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '-':
        case '+':
            return 1;
        default:
            return 0;
    }
}
