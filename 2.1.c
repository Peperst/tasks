#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Перечислимый тип для выбора способа обмена значений
 */
enum Choice
{
    WITH_THIRD_VARIABLE = 1,
    WITHOUT_THIRD_VARIABLE = 2
};

/**
 * @brief Меняет местами значения переменных с использованием третьей переменной
 * @param a указатель на первую переменную
 * @param b указатель на вторую переменную
 */
void swapWithThird(double *a, double *b);

/**
 * @brief Меняет местами значения переменных без использования третьей переменной
 * @param a указатель на первую переменную
 * @param b указатель на вторую переменную
 */
void swapWithoutThird(double *a, double *b);

/**
 * @brief Считывает с клавиатуры значение с плавающей точкой
 * @return Считанное значение
 */
double getDouble();

/**
 * @brief Считывает с клавиатуры целое число
 * @return Считанное значение
 */
int getInt();

/**
 * @brief Проверяет корректность выбора пользователя
 * @param choice выбранный пункт меню
 */
void checkChoice(const int choice);

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе не 0
 */
int main()
{
    printf("Enter a: ");
    double a = getDouble();

    printf("Enter b: ");
    double b = getDouble();

    printf("Choose method (%d - with third variable c, %d - without third variable): ",
           WITH_THIRD_VARIABLE, WITHOUT_THIRD_VARIABLE);
    int choice = getInt();
    checkChoice(choice);

    printf("Before swap: a = %lf, b = %lf\n", a, b);

    switch (choice)
    {
        case WITH_THIRD_VARIABLE:
            swapWithThird(&a, &b);
            printf("After swap (with third variable c): a = %lf, b = %lf\n", a, b);
            break;
        case WITHOUT_THIRD_VARIABLE:
            swapWithoutThird(&a, &b);
            printf("After swap (without third variable): a = %lf, b = %lf\n", a, b);
            break;
        default:
            printf("Error\n");
            exit(1);
    }

    return 0;
}

void swapWithThird(double *a, double *b)
{
    double c = *a;
    *a = *b;
    *b = c;
}

void swapWithoutThird(double *a, double *b)
{
    if (a == b)
    {
        return;
    }
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
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

int getInt()
{
    int value = 0;
    if (scanf("%d", &value) != 1)
    {
        printf("Error\n");
        exit(1);
    }
    return value;
}

void checkChoice(const int choice)
{
    if (choice != WITH_THIRD_VARIABLE && choice != WITHOUT_THIRD_VARIABLE)
    {
        printf("Error\n");
        exit(1);
    }
}
