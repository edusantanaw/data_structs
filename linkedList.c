#include <stdio.h>;
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
} Node;

typedef struct List
{
    struct Node *head;
    struct Node *tail;
} List;

void append(List *list, Node *v);
void printList(List *list);
void removeListItem(int value, List *list);

void main()
{
    List list = {head : NULL, tail : NULL};
    int val;
    bool read = true;
    while (read)
    {
        printf("Digite um numero para inserir na lista!\n");
        scanf("%d", &val);
        if (val == 0)
        {
            read = false;
            continue;
        }
        Node *node = (Node *)malloc(sizeof(Node));
        node->val = val;
        node->next = NULL;
        append(&list, node);
    }
    printf("Vc deseja apagar algum item? Digite o numero para sim ou digite 0 para não\n");
    scanf("%d", &val);
    if (val != 0)
        removeListItem(val, &list);
    printList(&list);
}

void removeListItem(int value, List *list)
{
    Node *currentNode = list->head;
    Node *aux;
    while (currentNode != NULL)
    {
        if (currentNode->val == value)
        {
            if (currentNode == list->head)
            {
                list->head = currentNode->next;
                free(currentNode);
                return;
            }
            if (currentNode == list->tail)
            {
                aux->next = NULL;
                list->tail = aux;
                free(currentNode);
                return;
            }
            aux->next = currentNode->next;
            free(currentNode);
            return;
        }
        aux = currentNode;
        currentNode = currentNode->next;
    }
}

void printList(List *list)
{
    Node *node = list->head;
    while (node != NULL)
    {
        printf("%d\n", node->val);
        node = node->next;
    }
}

void append(List *List, Node *node)
{
    if (List->head == NULL)
    {
        List->head = node;
        return;
    }
    if (List->tail == NULL)
    {
        List->head->next = node;
        List->tail = node;
        return;
    }
    Node *aux = List->tail;
    List->tail = node;
    aux->next = node;
};