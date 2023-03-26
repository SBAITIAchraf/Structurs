#include <stdio.h>
#include <stdlib.h>

typedef struct listNode
{
    int data;
    struct listNode *next;
    struct listNode *previous;
    struct listNode *last;
}Node;

void append(Node *head, int elem)
{
    Node *new = (Node *) malloc(sizeof(Node));

    new->data = elem;
    new->next = NULL;
    
    head->last->next = new;
    new->previous = head->last;
    head->last = new;

}

void pop(Node *head)
{
    Node *poped = head->last;
    poped->previous->next = NULL;
    head->last = poped->previous;
    free(poped);
}

void delete(Node *head, int elem)
{
    if(head->data == elem)
    {
        if(head->previous != NULL)
        {
            head->previous->next = head->next;
        }
        if(head->next != NULL)
        {
            head->next->previous = head->previous;
        }
        free(head);
    }
    else if(head->next != NULL)
    {
        delete(head->next, elem);
    }
}

int main()
{
    Node header = {5, NULL, NULL, &header};
    append(&header, 25);
    append(&header, 75);
    append(&header, 56);
    append(&header, 89);


    Node *current = &header;
    do
    {
        printf("%d\n", current->data);
        current = current->next;
    }while (current != NULL);
    
    return 0;
}