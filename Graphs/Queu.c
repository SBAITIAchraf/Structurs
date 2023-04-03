#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int *first_slot;
    int *arr;
    int len;
    int mal;
    int empty;
}queu;

void push_q(queu *my_arr, int elem)
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

void pop_q(queu *my_arr)
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
            free(my_arr->first_slot);
            my_arr->mal = new_mal;
            my_arr->arr = new_arr;
            my_arr->first_slot = new_arr;
        }
    }
}

int peak_q(queu *my_arr)
{
    int elem = my_arr->arr[0];
    return elem;
}

queu new_q()
{
    queu my_q = {(int *) malloc(my_q.mal * sizeof(int)), my_q.first_slot, 0, 1, 1};
    return my_q;
}
