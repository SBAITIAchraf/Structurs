#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int len;
    int mal;
    int start_index;
    int empty;
    char *arr;
}queu;

void *push(queu *my_arr, char elem)
{
    if (my_arr->len >= my_arr->mal)
    {
        int new_mal = my_arr->mal * 2;
        char *new_arr =(char *) malloc(new_mal * sizeof(char));
        for (char i = 0; i < my_arr->len; i++)
        {
            new_arr[(new_mal - 1) - i] = my_arr->arr[(my_arr->mal - 1) - i];
        }
        free(my_arr->arr);
        my_arr->mal = new_mal;
        my_arr->arr = new_arr;
    }
    my_arr->len++;
    my_arr->start_index = my_arr->mal - my_arr->len;
    my_arr->arr[my_arr->start_index] = elem;
}

void *pop(queu *my_arr)
{
    if (my_arr->len != 0)
    {
        my_arr->len--;
        if (my_arr->mal - my_arr->len >= my_arr->empty)
        {
            my_arr->empty *= 2;
            int new_mal = my_arr->len;
            char *new_arr = (char *) malloc(new_mal * sizeof(char));
            for (int i = 0; i < my_arr->len; i++)
            {
                new_arr[i] = my_arr->arr[my_arr->start_index + i];
            }
            free(my_arr->arr);
            my_arr->mal = new_mal;
            my_arr->arr = new_arr;
            my_arr->start_index = my_arr->mal - my_arr->len;
        }
    }
}

char peak(queu *my_arr)
{
    char elem = my_arr->arr[my_arr->start_index];
    return elem;
}

char main()
{

    queu array = { 7, 8, array.mal - array.len, 1, (char *) malloc(array.mal * sizeof(char))};

    for (int i = 0; i<array.len; i++)
    {
        array.arr[array.start_index + i] = i;
    }
    
    push(&array, 5);
    for (int i = 0; i<array.len; i++)
    {
        printf("%c\n", (char) array.arr[array.start_index + i]);
    }
    printf("Stop\n\n");

    pop(&array);
    for (int i = 0; i<array.len; i++)
    {
        printf("%c\n", array.arr[i]);
    }
    printf("Stop\n\n");


    push(&array, 254);
    for (int i = 0; i<array.len; i++)
    {
        printf("%c\n", array.arr[i]);
    }
    printf("Stop\n\n");
    return 0;
}
