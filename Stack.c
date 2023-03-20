#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int *arr;
    int len;
    int mal;
    int empty;
}stack;

void *push(stack *my_arr, int elem)
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

void *pop(stack *my_arr)
{
    if (my_arr->len != 0)
    {
        my_arr->len--;
        if (my_arr->mal - my_arr->len >= my_arr->empty)
        {
            my_arr->empty *= 2;
            my_arr->mal = my_arr->len;
            int *new_arr = (int *) malloc(my_arr->len * sizeof(int));
            for (int i = 0; i < my_arr->len; i++)
            {
                new_arr[i] = my_arr->arr[i];
            }
            free(my_arr->arr);
            my_arr->arr = new_arr;
        }
    }
}

int main()
{

    stack array = {(int *) malloc(array.len * sizeof(int)), 7, 8, 1};

    for (int i = 0; i<array.len; i++)
    {
        array.arr[i] = i;
    }
    
    push(&array, 5);
    for (int i = 0; i<array.len; i++)
    {
        printf("%d\n", array.arr[i]);
    }
    printf("Stop\n\n");

    push(&array, 12);
    for (int i = 0; i<array.len; i++)
    {
        printf("%d\n", array.arr[i]);
    }
    printf("Stop\n\n");

    pop(&array);
    for (int i = 0; i<array.len; i++)
    {
        printf("%d\n", array.arr[i]);
    }
    printf("Stop\n\n");

    pop(&array);
    for (int i = 0; i<array.len; i++)
    {
        printf("%d\n", array.arr[i]);
    }
    printf("Stop\n\n");


    push(&array, 254);
    for (int i = 0; i<array.len; i++)
    {
        printf("%d\n", array.arr[i]);
    }
    printf("Stop\n\n");
    return 0;
}
