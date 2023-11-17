/*
4. Напишите программу, которая ищет введенной строке (с клавиатуры)
    введенную подстроку (с клавиатуры) и возвращает указатель на начало
    подстроки, если подстрока не найдена в указатель записывается NULL.
    В качестве срок использовать статические массивы.
*/

#include <stdio.h>


#define STR_SIZE 20
#define SUBSTR_SIZE (int)sizeof(int)

int main(){
    // Строка и подстрока (+1 для '\0')
    char str[STR_SIZE + 1] = {' '};
    char substr[SUBSTR_SIZE + 1] = {' '};

    printf("Enter a string (max size %d): .", STR_SIZE);
    fgets(str, STR_SIZE + 1, stdin);

    printf("Enter a substring equal to the size %d: .", SUBSTR_SIZE);
    fgets(substr, SUBSTR_SIZE  + 1, stdin);
    printf("\n");

    // Значение подстроки
    unsigned int substr_value = 0;
    for (int i = 0; i < SUBSTR_SIZE ; i++){
        substr_value = (substr_value << 8) | substr[i];
        //printf("%u ", (int)substr[i]);
    }
    //printf("\nSubstr value: %u\n", substr_value);
    
    // Проверяем значение подстроки на равенство со значенем выборки из строки
    unsigned int value = 0;
    char* substr_begin = NULL;
    int index = -1;

    // Значение строки
    for (int i = 0; i < SUBSTR_SIZE; i++)
        value = (value << 8) | str[i];

    // Если подстрока в начале
    if (substr_value == value){ 
        substr_begin = &str[0];
        index = 0;
    }else{  // Если подстрока не в начале
        for (int i = SUBSTR_SIZE; i < STR_SIZE; i++){
            value = (value << 8) | str[i];
            // Проверка
            if (substr_value == value){
                substr_begin = &str[i - SUBSTR_SIZE + 1];
                index = i - SUBSTR_SIZE + 1;
                break;
            }
        }
    }
    
    if (substr_begin == NULL)
        printf("Substring not found!\n");
    else
        printf("Substring found at index: %d, addr: %p, symbol: %c", index, substr_begin, *substr_begin);

    printf("\n\n");
    return 0;
}