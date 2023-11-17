/*
4. Напишите программу, которая ищет введенной строке (с клавиатуры)
    введенную подстроку (с клавиатуры) и возвращает указатель на начало
    подстроки, если подстрока не найдена в указатель записывается NULL.
    В качестве срок использовать статические массивы.
*/

#include <stdio.h>
#define STRING_LIM 20
#define SUBSTRING_SIZE 5

int main(){
    // Строка и подстрока (+1 для '\0')
    char str[STRING_LIM + 1] = {' '};
    char substr[SUBSTRING_SIZE + 1] = {' '};
    printf("Enter a string (max size %d): .", STRING_LIM);
    fgets(str, STRING_LIM + 1, stdin);
    printf("\nEnter a substring equal to the size %d): .", SUBSTRING_SIZE);
    fgets(substr, SUBSTRING_SIZE + 1, stdin);

    printf("String[0]    = %c\n", str[0]);
    printf("Substring[0] = %c\n", substr[0]);
    printf("String[4]    = %c\n", str[4]);
    printf("Substring[4] = %c\n", substr[4]);
    // Значение подстроки
    unsigned long long int substr_value = 0;
    for (int i = 0; i < SUBSTRING_SIZE; i++){
        substr_value = (substr_value << 8) | substr[i];
        printf("%u ", &substr[i]);
    }
    printf("Substr value: %llu\n", substr_value);
    
    // Значение строки
    unsigned long long int value = 0;
    long mask = 0;
    //mask = ((~mask) << ((sizeof(unsigned long long int) - 8*(SUBSTRING_SIZE - 1))) >> ((sizeof(unsigned long long int) - 8*(SUBSTRING_SIZE - 1))));
    for (int i = 0; i < SUBSTRING_SIZE; i++){
        value = (value << 8) | str[i];
    }

    char* substr_begin = NULL;
    int index = -1;
    // Проверяем значение подстроки на равенство со значенем выборки из строки
    for (int i = SUBSTRING_SIZE; i < STRING_LIM - SUBSTRING_SIZE; i++){
        printf("---str value: %llu\n", value);
        // Проверка
        if (substr_value == value){
            substr_begin = &str[i - 1];
            index = i - 1;
            break;
        }
        // Значение строки

        //value = ((value << 8) | str[i]) & ();
        // value = ((value << sizeof(unsigned long long int) - 8*(SUBSTRING_SIZE - 1)) // Удаляем послений байт
        //         >> (sizeof(unsigned long long int) - 8*(SUBSTRING_SIZE) - 8*(SUBSTRING_SIZE - 1)) // Сдвигаем обратно
        //         | str[i]);
        value = ((value << 8) | str[i]) & (mask);
    }
    
    if (substr_begin == NULL)
        printf("Substring not found!\n");
    else
        printf("Substring found at index: %d, addr: %p, symbol: %c", index, substr_begin, *substr_begin);

    //printf("Your string is: .%s", str);
    //printf("Your substring is: .%s", substr);
    printf("\n\n");
    return 0;
}