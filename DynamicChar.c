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

int main()
{

    list array = {(char *) malloc(array.mal * sizeof(char)), 1, 2};
    array.arr[0] ='A';
    array.arr[1] ='\0';

    append(&array, 'B');
    append(&array, 'C');
    printf("%s\n", array.arr);
    return 0;
}
