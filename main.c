/*
2. В приведенном ниже коде измените только одну строку (помеченную),
    чтобы напечатать “Результат: 12.0”.
        #include <stdio.h>
        int main(void)
        {
            float x = 5.0;
            printf("x = %f, ", x);
            float y = 6.0;
            printf("y = %f\n", y);
            float *xp = &x; // TODO: отредактируйте эту строку, и только правую часть
            уравнения
            float *yp = &y;
            printf("Результат: %f\n", *xp + *yp);
        }
*/

#include <stdio.h>
int main(void)
{
    float x = 5.0;
    printf("x = %f, ", x);
    float y = 6.0;
    printf("y = %f\n", y);
    float *xp = &y; // TODO: отредактируйте эту строку, и только правую часть уравнения
    float *yp = &y;
    printf("Результат: %f\n", *xp + *yp);
}