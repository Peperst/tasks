#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <float.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

/**
 * @brief Считывает с клавиатуры значение с плавающей точкой
 * @return Считанное значение
 */
double getDouble();

/**
 * @brief Проверяет, лежат ли три точки на одной прямой
 * @param x1 координата X точки A
 * @param y1 координата Y точки A
 * @param x2 координата X точки B
 * @param y2 координата Y точки B
 * @param x3 координата X точки C
 * @param y3 координата Y точки C
 * @return true, если точки расположены на одной прямой, иначе false
 */
bool isCollinear(const double x1, const double y1,
                 const double x2, const double y2,
                 const double x3, const double y3);

/**
 * @brief Вычисляет угол B (в радианах) между векторами BA и BC
 * @param x1 координата X точки A
 * @param y1 координата Y точки A
 * @param x2 координата X точки B
 * @param y2 координата Y точки B
 * @param x3 координата X точки C
 * @param y3 координата Y точки C
 * @return Значение угла B в радианах
 */
double getAngleB(const double x1, const double y1,
                 const double x2, const double y2,
                 const double x3, const double y3);

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе не 0
 */
int main()
{
    printf("Enter point A (x1, y1):\n");
    double x1 = getDouble();
    double y1 = getDouble();

    printf("Enter point B (x2, y2):\n");
    double x2 = getDouble();
    double y2 = getDouble();

    printf("Enter point C (x3, y3):\n");
    double x3 = getDouble();
    double y3 = getDouble();

    if (isCollinear(x1, y1, x2, y2, x3, y3))
    {
        printf("Points are located on one line\n");
    }
    else
    {
        double angleRad = getAngleB(x1, y1, x2, y2, x3, y3);
        double angleDeg = angleRad * (180.0 / M_PI);
        printf("Points are not located on one line\n");
        printf("Angle B = %lf radians (%lf degrees)\n", angleRad, angleDeg);
    }

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

bool isCollinear(const double x1, const double y1,
                 const double x2, const double y2,
                 const double x3, const double y3)
{
    double cross = (x1 - x2) * (y3 - y2) - (y1 - y2) * (x3 - x2);
    return (fabs(cross) < DBL_EPSILON);
}

double getAngleB(const double x1, const double y1,
                 const double x2, const double y2,
                 const double x3, const double y3)
{
    double baX = x1 - x2;
    double baY = y1 - y2;
    double bcX = x3 - x2;
    double bcY = y3 - y2;

    double dot = baX * bcX + baY * bcY;
    double lenBA = sqrt(baX * baX + baY * baY);
    double lenBC = sqrt(bcX * bcX + bcY * bcY);

    double cosB = dot / (lenBA * lenBC);
    if (cosB > 1.0)
    {
        cosB = 1.0;
    }
    else if (cosB < -1.0)
    {
        cosB = -1.0;
    }

    return acos(cosB);
}
