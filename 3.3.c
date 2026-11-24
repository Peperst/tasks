#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

/**
 * @brief Вычисляет значение функции y = (1 + 2*x^2) * e^(x^2)
 * @param x аргумент функции
 * @return Рассчитанное значение функции
 */
double getY(const double x);

/**
 * @brief Вычисляет сумму функционального ряда с заданной точностью
 * @param x аргумент функции
 * @param e заданная точность (порог)
 * @return Рассчитанная сумма ряда
 */
double getSum(const double x, const double e);

/**
 * @brief Вычисляет коэффициент перехода от предыдущего члена ряда к следующему
 * @param x аргумент функции
 * @param n номер следующего члена ряда (n >= 1)
 * @return Рассчитанный коэффициент
 */
double getCoef(const double x, const int n);

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main()
{
    const double xbegin = 0.1;
    const double xend = 1.0;
    const double step = 0.1;
    const double e = 1e-4;

    printf("x\t\t y\t\t S\n");
    printf("--------------------------------------------------\n");

    for (double x = xbegin; x < xend + step / 2.0; x += step)
    {
        printf("%lf\t %lf\t %lf\n", x, getY(x), getSum(x, e));
    }

    return 0;
}

double getY(const double x)
{
    return (1.0 + 2.0 * x * x) * exp(x * x);
}

double getSum(const double x, const double e)
{
    double a = 1.0;
    double result = 0.0;
    int n = 1;

    while (fabs(a) >= e - DBL_EPSILON)
    {
        result += a;
        a *= getCoef(x, n);
        n++;
    }

    return result;
}

double getCoef(const double x, const int n)
{
    return ((2.0 * n + 1.0) / (2.0 * n - 1.0)) * (x * x / n);
}
