#include <stdio.h>
#include <math.h>

/**
 * @brief Вычисляет расстояние между двумя точками на плоскости
 * @param x1 координата X первой точки
 * @param y1 координата Y первой точки
 * @param x2 координата X второй точки
 * @param y2 координата Y второй точки
 * @return Рассчитанное значение расстояния
 */
double d(const double x1, const double y1, const double x2, const double y2);

/**
 * @brief Считывает с клавиатуры значение с плавающей точкой
 * @return Считанное значение
 */
double getDouble();

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе не 0
 */
int main()
{
    double x1 = getDouble();
    double y1 = getDouble();
    double x2 = getDouble();
    double y2 = getDouble();

    printf("Distance is %lf\n", d(x1, y1, x2, y2));

    return 0;
}

double d(const double x1, const double y1, const double x2, const double y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double getDouble()
{
    double value = 0.0;
    scanf("%lf", &value);
    return value;
}
