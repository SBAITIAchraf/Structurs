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
    if (my_arr->len == my_arr->mal)
    {
        my_arr->mal *= 2;
        char *new_arr =(char *) malloc((my_arr->mal + 1) * sizeof(char));
        for (int i = 0; i < my_arr->len; i++)
        {
            new_arr[i] = my_arr->arr[i];
        }
        free(my_arr->arr);
        my_arr->arr = new_arr;
    }
    my_arr->arr[my_arr->len] = elem;
    my_arr->arr[my_arr->len + 1] = '\0';
    my_arr->len++;
}

void *pop(stack *my_arr)
{
    if (my_arr->len != 0)
    {
        my_arr->len--;
        my_arr->arr[my_arr->len] = '\0';
        if (my_arr->mal - my_arr->len >= my_arr->empty)
        {
            my_arr->empty *= 2;
            my_arr->mal = my_arr->len;
            char *new_arr = (char *) malloc((my_arr->len + 1) * sizeof(char));
            for (int i = 0; i <= my_arr->len; i++)
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

    stack array = {(char *) malloc(array.len * sizeof(char)), 1, 2, 1};

    array.arr[0] ='A';
    array.arr[1] ='\0';

    push(&array, 'B');
    push(&array, 'C');
    pop(&array);
    printf("%s\n", array.arr);
    push(&array, 'C');
    printf("%s\n", array.arr);
    
    return 0;
}
