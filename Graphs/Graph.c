#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

typedef struct listNode
{
    struct listNode *next;
    struct listNode *previous;
    struct listNode *last;
    int data;
}Node;

typedef struct 
{
    int *arr;
    int len;
    int mal;
    int empty;
}stack;

typedef struct 
{
    int *first_slot;
    int *arr;
    int len;
    int mal;
    int empty;
}queu;



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

    // DFS Algo
    int visited[nodesc + 1];
    queu my_queu = new_q();
    push_q(&my_queu, nodes[0]->data);
    while (my_queu.len > 0)
    {
        int current_node = peak_q(&my_queu);
        pop_q(&my_queu);
         if (visited[current_node] != 1)
         {
            visited[current_node] = 1;
            Node *current_position = nodes[current_node-1]->next;
            while (current_position != NULL)
            {
                if (visited[current_position->data] != 1)
                {
                    visited[current_position->data] = 1;
                    push_q(&my_queu, current_position->data);
                }
                current_position = current_position->next;
            }
         }
         
         

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
