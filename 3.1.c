#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>

/**
 * @brief Считывает значение с консоли
 * @param message приглашение к вводу
 * @return Считанное значение типа double
 */
double getValue(const char* message);

/**
 * @brief Проверяет, что шаг является положительным числом
 * @param step значение шага
 */
void checkStep(const double step);

/**
 * @brief Проверяет корректность границ отрезка
 * @param xbegin начало отрезка
 * @param xend конец отрезка
 */
void checkSegment(const double xbegin, const double xend);

/**
 * @brief Проверяет, принадлежит ли точка области определения функции (ОДЗ)
 * @param x проверяемое значение аргумента
 * @return true, если функция определена в точке x, иначе false
 */
bool isOOF(const double x);

/**
 * @brief Вычисляет значение функции y = 3x - 4*ln(x) - 5
 * @param x аргумент функции
 * @return Рассчитанное значение функции
 */
double getY(const double x);

/**
 * @brief Точка входа в программу (цикл for)
 * @return 0, если программа выполнена корректно
 */
int main()
{
    double xbegin = getValue("Enter segment start: ");
    double xend = getValue("Enter segment end: ");
    double step = getValue("Enter step: ");

    checkStep(step);
    checkSegment(xbegin, xend);

    for (double x = xbegin; x < xend + step / 2.0; x += step)
    {
        if (isOOF(x))
        {
            printf("x = %lf, y = %lf\n", x, getY(x));
        }
        else
        {
            printf("y is not define\n");
        }
    }

    return 0;
}

double getValue(const char* message)
{
    if (message != NULL)
    {
        printf("%s\n", message);
    }
    double value = 0.0;
    if (scanf("%lf", &value) != 1)
    {
        printf("Input error\n");
        exit(1);
    }
    return value;
}

void checkStep(const double step)
{
    if (step <= 0)
    {
        printf("Error, step have to be positive\n");
        exit(1);
    }
}

void checkSegment(const double xbegin, const double xend)
{
    if (xbegin > xend)
    {
        printf("Error, segment begin have to be less or equal segment end\n");
        exit(1);
    }
}

bool isOOF(const double x)
{
    return (x > 0.0);
}

double getY(const double x)
{
    return 3 * x - 4 * log(x) - 5;
}
