#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

/**
 * @brief Считывает целое число с консоли
 * @param message приглашение к вводу
 * @return Считанное целое число
 */
int getInt(const char* message);

/**
 * @brief Считывает вещественное число с консоли
 * @param message приглашение к вводу
 * @return Считанное вещественное число
 */
double getValue(const char* message);

/**
 * @brief Проверяет, что n является положительным числом
 * @param n проверяемое значение
 */
void checkPositive(const int n);

/**
 * @brief Проверяет, что e является положительным числом
 * @param e проверяемое значение
 */
void checkEpsilon(const double e);

/**
 * @brief Вычисляет сумму первых n членов последовательности
 * @param n количество членов
 * @return Рассчитанная сумма
 */
double sumN(const int n);

/**
 * @brief Вычисляет сумму всех членов последовательности, по модулю не меньших e
 * @param e заданная точность (порог)
 * @return Рассчитанная сумма
 */
double sumE(const double e);

/**
 * @brief Вычисляет рекуррентный коэффициент перехода между членами последовательности
 * @param i индекс шага (i = 0 соответствует k = 1)
 * @return Коэффициент перехода к следующему члену
 */
double getCoef(const int i);

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main()
{
    int n = getInt("Enter n: ");
    checkPositive(n);

    double e = getValue("Enter e: ");
    checkEpsilon(e);

    printf("Summ of %d elements is: %lf\n", n, sumN(n));
    printf("Summ of elements not less than %lf is: %lf\n", e, sumE(e));

    return 0;
}

double getValue(const char* message)
{
    if (message != NULL)
    {
        printf("%s", message);
    }
    double value = 0.0;
    if (scanf("%lf", &value) != 1)
    {
        printf("Input error\n");
        exit(1);
    }
    return value;
}

int getInt(const char* message)
{
    if (message != NULL)
    {
        printf("%s", message);
    }
    int value = 0;
    if (scanf("%d", &value) != 1)
    {
        printf("Input error\n");
        exit(1);
    }
    return value;
}

void checkPositive(const int n)
{
    if (n <= 0)
    {
        printf("Error, n have to be positive\n");
        exit(1);
    }
}

void checkEpsilon(const double e)
{
    if (e <= 0)
    {
        printf("Error, e have to be positive\n");
        exit(1);
    }
}

double getCoef(const int i)
{
    return -(i + 2.0) / (i + 6.0);
}

double sumN(const int n)
{
    double a = -1.0 / 120.0;
    double result = 0.0;

    for (int i = 0; i < n; i++)
    {
        result += a;
        a *= getCoef(i);
    }

    return result;
}

double sumE(const double e)
{
    double a = -1.0 / 120.0;
    double result = 0.0;

    for (int i = 0; fabs(a) >= e - DBL_EPSILON; i++)
    {
        result += a;
        a *= getCoef(i);
    }

    return result;
}
