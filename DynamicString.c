#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int *arr;
    int len;
    int mal;
}list;

void *append(list *my_arr, int elem)
{
    if (my_arr->len == my_arr->mal)
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

int main()
{

    list array = {(int *) malloc(array.mal * sizeof(int)), 2, 4};
    array.arr[0] =2;
    array.arr[1] =47;

    append(&array, 5);
    for (int i = 0; i<array.len; i++)
    {
        printf("%d\n", array.arr[i]);
    }
    append(&array, 12);
    for (int i = 0; i<array.len; i++)
    {
        printf("%d\n", array.arr[i]);
    }
    return 0;
}
