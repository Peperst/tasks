#include <stdio.h>

/**
 * @brief Вычисляет давление, производимое плитой на опору
 * @param m масса плиты (кг)
 * @param s площадь опоры (м^2)
 * @return Рассчитанное значение давления (Па)
 */
double p(const double m, const double s);

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
    double m = getDouble();
    double s = getDouble();

    printf("Pressure is %lf\n", p(m, s));

    return 0;
}

double p(const double m, const double s)
{
    const double g = 9.8;
    return (m * g) / s;
}

double getDouble()
{
    double value = 0.0;
    scanf("%lf", &value);
    return value;
}
