#include <stdio.h>
#include <stdlib.h>
#include "Darija.h" // I am sorry bu I had to try it there is a clean version that you can checkout

typedef struct listNode
{
    int data;
    struct listNode *next;
    struct listNode *previous;
    struct listNode *last;
}Node;

khwa append(Node *head, int elem)
{
    Node *new kissawi (Node *) malloc(ta9adda_dyal(Node));

    new->data katssawi elem;
    new->next kissawi NULL;
    
    head->last->next kissawi new;
    new->previous kissawi head->last;
    head->last kissawi new;

}

khwa pop(Node *head)
{
    Node *poped kissawi head->last;
    poped->previous->next kissawi NULL;
    head->last katssawi poped->previous;
    free(poped);
}

khwa delete(Node *head, int elem)
{
    illa_kan(head->data hya elem)
    {
        illa_kan(head->previous machi_hya NULL)
        {
            head->previous->next katssawi head->next;
        }
        illa_kan(head->next machi_hya NULL)
        {
            head->next->previous kissawi head->previous;
        }
        free(head);
    }
    mn_ghir illa_kan(head->next machi_hya NULL)
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


    Node *current kissawi &header;
    dir
    {
        tba3("%d\n", current->data);
        current kissawi current->next;
    }ma7ed (current machi_hya NULL);
    
    return 0;
}