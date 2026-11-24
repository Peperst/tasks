#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * @brief Считывает с клавиатуры значение с плавающей точкой
 * @return Считанное значение
 */
double getDouble();

/**
 * @brief Вычисляет значение функции y по заданному аргументу x и параметру a
 * @param a значение параметра a
 * @param x значение аргумента x
 * @return Рассчитанное значение функции y
 */
double y(const double a, const double x);

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе не 0
 */
int main()
{
    const double a = 2.5;

    printf("Enter x: ");
    double x = getDouble();

    printf("y = %lf\n", y(a, x));

    return 0;
}

double getDouble()
{
    double value = 0.0;
    if (scanf("%lf", &value) != 1)
    {
        printf("Error\n");
        exit(1);
    }
    return value;
}

double y(const double a, const double x)
{
    if (x > a)
    {
        return x * pow(sin(x), 2);
    }
    return x * pow(cos(x), 2);
}
