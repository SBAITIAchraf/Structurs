#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char *arr;
    int len;
    int mal;
}list;

void *append(list *my_arr, char elem)
{
    if (my_arr->len == my_arr->mal)
    {
        my_arr->mal *= 2;
        char *new_arr =(char *) malloc(my_arr->mal * sizeof(char));
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

    list array = {(char *) malloc(array.mal * sizeof(char)), 2, 4};
    array.arr[0] ='A';
    array.arr[1] ='C';

    append(&array, 'B');
    for (int i = 0; i<array.len; i++)
    {
        printf("%c\n", array.arr[i]);
    }
    append(&array, 'C');
    for (int i = 0; i<array.len; i++)
    {
        printf("%c\n", array.arr[i]);
    }
    return 0;
}
