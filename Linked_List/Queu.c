#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int len;
    int mal;
    int empty;
    int *arr;
    int *first_slot;
}queu;

void *push(queu *my_arr, int elem)
{
    if (my_arr->len >= my_arr->mal)
    {
        my_arr->mal *= 2;
        int *new_arr =(int *) malloc(my_arr->mal * sizeof(int));
        for (int i = 0; i < my_arr->len; i++)
        {
            new_arr[i] = my_arr->arr[i];
        }
        free(my_arr->arr);
        my_arr->arr = new_arr;
    }
    my_arr->arr[my_arr->len] = elem;
    my_arr->len++;
}

void *pop(queu *my_arr)
{
    if (my_arr->len != 0)
    {
        my_arr->len--;
        my_arr->arr = my_arr->arr + 1;
        if (my_arr->mal - my_arr->len >= my_arr->empty)
        {
            my_arr->empty *= 2;
            int new_mal = my_arr->len;
            int *new_arr = (int *) malloc(new_mal * sizeof(int));
            for (int i = 0; i < my_arr->len; i++)
            {
                new_arr[i] = my_arr->arr[i];
            }
            free(my_arr->arr);
            my_arr->mal = new_mal;
            my_arr->arr = new_arr;
            my_arr->first_slot = new_arr;
        }
    }
}

int peak(queu *my_arr)
{
    int elem = my_arr->arr[0];
    return elem;
}

int main()
{
   queu my_q = {0, 1, 1,(int *) malloc(my_q.mal * sizeof(int)), my_q.arr};
   push(&my_q, 5);
   push(&my_q, 25);
   push(&my_q, 34);
   push(&my_q, 9);
   for (int i = 0; i<my_q.len; i++)
   {
    printf("%d\n", my_q.arr[i]);
   }
   printf("\n");
   pop(&my_q);
   pop(&my_q);
   for (int i = 0; i<my_q.len; i++)
   {
    printf("%d\n", my_q.arr[i]);
   }
}
