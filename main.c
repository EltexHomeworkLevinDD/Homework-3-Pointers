/*
3. Напишите программу, в которой определите массив типа int (размер
    массива 10 элементов от 1 до 10). Используйте указатель для вывода
    элементов массива на консоль (применять можно только арифметику
    указателей, а не индексы).
*/

#include <stdio.h>

int main(){
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int* arrayPtr = array;
    for (int i = 0; i < 10; i++)
        printf("%2d ", *arrayPtr++);
    arrayPtr = NULL;

    printf("\n\n");
    return 0;
}