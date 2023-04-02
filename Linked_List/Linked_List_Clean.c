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
    Node *next_node = head->next;
    if(head->data == elem)
    {

        head->previous->next = head->next;
        
        if(head->next != NULL)
        {
            head->next->previous = head->previous;
        }
        free(head);
    }
    if(next_node != NULL)
    {
        delete(next_node, elem);
    }
}

int main()
{   
    return 0;
}