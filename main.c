/*
1. Поменять в целом положительном числе (типа int) значение третьего
    байта на введенное пользователем число (изначальное число также
    вводится с клавиатуры) через указатель (не применяя битовые
    операции).
*/

#include <stdio.h>

int main(){
    printf("\n\n");

    int number;
    int value;
    printf("Enter a positive integer A: ");
    scanf("%d", &value);
    getchar();
    printf("Enter a positive integer for 3-rd byte of A number: ");
    scanf("%d", &number);
    printf("\n");

    printf("Your integer before: %d\n", value);
    char* cptr = &value;
    cptr = cptr + 2;    // Shift to 3-rd byte of value
    *cptr = number;
    cptr = NULL;
    printf("Your integer after:  %d\n", value);

    printf("\n\n");
    return 0;
}