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
    if(next_node != NULL)
    {
        delete(next_node, elem);
    }
} 

int main(int argc, char *argv[])
{
    int nodesc = atoi(argv[1]), edgesc = atoi(argv[2]);

    Node *nodes[nodesc];

    for (int i = 0; i <nodesc; i++)
    {
        nodes[i] =(Node *) malloc(sizeof(Node));
        nodes[i]->data = i+1;
        nodes[i]->next = NULL;
        nodes[i]->previous = NULL;
        nodes[i]->last = nodes[i];
    }

    int first_node, second_node;
    for (int edge = 0; edge < edgesc; edge++)
    {
        scanf("%d %d", &first_node, &second_node);
        append(nodes[first_node - 1], second_node);
        append(nodes[second_node - 1], first_node);
    }

     

    // Print Graph
    /*for (int j = 0; j<nodesc; j++)
    {
        Node *current_node = nodes[j];
        while (current_node != NULL)
        {
            if(current_node->next != NULL)
            {
                printf("%d->", current_node->data);
            }
            else
            {
                printf("%d", current_node->data);
            }
            current_node = current_node->next;
        }
        printf("\n");
        
    }*/

}