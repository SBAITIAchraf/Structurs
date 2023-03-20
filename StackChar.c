#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char *arr;
    int len;
    int mal;
    int empty;
}stack;

void *push(stack *my_arr, char elem)
{
    if (my_arr->len >= my_arr->mal)
    {
        my_arr->mal *= 2;
        char *new_arr =(char *) malloc(my_arr->mal * sizeof(int));
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

void *pop(stack *my_arr)
{
    if (my_arr->len != 0)
    {
        my_arr->len--;
        if (my_arr->mal - my_arr->len >= my_arr->empty)
        {
            my_arr->empty *= 2;
            my_arr->mal = my_arr->len;
            char *new_arr = (char *) malloc(my_arr->len * sizeof(char));
            for (int i = 0; i < my_arr->len; i++)
            {
                new_arr[i] = my_arr->arr[i];
            }
            free(my_arr->arr);
            my_arr->arr = new_arr;
        }
    }
}

char main()
{

    stack array = {(char *) malloc(array.len * sizeof(char)), 7, 8, 1};

    
    return 0;
}
