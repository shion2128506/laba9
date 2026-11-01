#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

void task1();
void task2();
void task3();

#define ROW 9
#define COL 9

int main()
{
	setlocale(LC_ALL, "RUS");
	task1();
	task2();
	task3();
}
void task1()
{
    int row, col;
    printf("\nТаблица Пифагора:\n");
    for (row = 1; row <= ROW; ++row) {
        for (col = 1; col <= COL; col++) {
            printf("%5d", col * row);
        }
        printf("\n");
    }
    printf("Левый нижний треугольник:\n");
    for (row = 1; row <= ROW; ++row)
    {
        // Условие col <= row создает эффект треугольника
        for (col = 1; col <= row; col++)
        {
            printf("%5d", col * row);
        }
        printf("\n");
    }
    printf("Таблица умножения в виде выражений:\n");
    for (row = 1; row <= ROW; ++row) {
        for (col = 1; col <= COL; col++) {
            // %d x %d = %-3d 
            // (%-3d означает, что результат займет 3 символа и будет выровнен по левому краю для ровных столбцов)
            printf("%d x %d = %-3d  ", row, col, row * col);
        }
        printf("\n");
    }
}
void task2()
{
    char repeat;
    do {
        char str[100]; // Строка для ввода очень длинного числа
        int digits[100]; // Массив для хранения цифр
        int count = 0; // Количество цифр

        printf("\nВведите произвольное длинное число: ");
        scanf("%s", str);

        // 1. разбор числа на цифры
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] >= '0' && str[i] <= '9') {
                digits[count] = str[i] - '0'; // превращание символа '5' в число 5
                count++;
            }
        }

        if (count == 0)
        {
            printf("Вы не ввели ни одной цифры\n");
        }
        else
        {
            int count3 = 0; // 1) количество цифр 3
            int countLast = 0; // 2) число повторений последней цифры
            int countEven = 0; // 3) количество четных цифр
            int countMore5 = 0; // 4) количество цифр > 5
            int sumOdd = 0; // 5) сумма нечетных цифр
            int sumMore7 = 0; // 6) сумма цифр >= 7
            long long prodAll = 1; // 7) произведение всех цифр (кроме 0)
            int countAdjacent = 0; // 10) рядом расположенные одинаковые цифры

            int lastDigit = digits[count - 1];
            int firstDigit = digits[0];
            int secondDigit = (count >= 2) ? digits[1] : 0;
            int preLastDigit = (count >= 2) ? digits[count - 2] : 0;

            int sumFirstHalf = 0;
            int sumSecondHalf = 0;
            int sumEvenRazryad = 0; // 12) сумма цифр четных разрядов
            int sumOddRazryad = 0;  // 12) сумма цифр нечетных разрядов

            int half = count / 2;

            for (int i = 0; i < count; i++)
            {
                int d = digits[i];

                if (d == 3) count3++; // 1) Количество 3

                if (d == lastDigit) countLast++; // 2) Повторения последней цифры

                if (d % 2 == 0) countEven++; // 3) Количество четных цифр

                if (d > 5) countMore5++; // 4) Количество цифр > 5

                if (d % 2 != 0) sumOdd += d; // 5) Сумма нечетных цифр

                if (d >= 7) sumMore7 += d; // 6) Сумма цифр >= 7

                if (d != 0) prodAll *= d; // 7) Произведение всех цифр (исключая 0)

                if (i > 0 && digits[i] == digits[i - 1]) // 10) Рядом расположенные одинаковые цифры
                {
                    countAdjacent++;
                }

                if (i < half) sumFirstHalf += d; // 11) Сумма половин. Если цифр нечетное количество, средняя цифра идет во вторую половину
                else sumSecondHalf += d;

                int positionFromEnd = count - 1 - i; // 12) Суммы по разрядам (младший разряд — индекс count-1). Если расстояние от конца (count - 1 - i) четное, разряд нечетный (1-й, 3-й...)
                if (positionFromEnd % 2 == 0)
                {
                    sumOddRazryad += d;
                }
                else
                {
                    sumEvenRazryad += d;
                }
            }

            int prodPreLastSecond = preLastDigit * secondDigit; // 8) Произведение предпоследней и второй цифры

            int sumEvenExceptLast = 0;  // 9) Сумма четных цифр, исключая последнюю
            for (int i = 0; i < count - 1; i++)
            {
                if (digits[i] % 2 == 0) sumEvenExceptLast += digits[i];
            }

            int isHalvesEqual = (sumFirstHalf == sumSecondHalf); // 11) Равна ли сумма первой и второй половины

            printf("\nРезультаты анализа\n");
            printf("1) Количество цифр 3: %d\n", count3);
            printf("2) Число повторений последней цифры (%d): %d\n", lastDigit, countLast);
            printf("3) Количество четных цифр: %d\n", countEven);
            printf("4) Количество цифр > 5: %d\n", countMore5);
            printf("5) Сумма нечетных цифр: %d\n", sumOdd);
            printf("6) Сумма цифр >= 7: %d\n", sumMore7);
            printf("7) Произведение всех цифр (без 0): %lld\n", prodAll); // Вывод произведения с проверкой на пустоту (если все нули, произведение останется 1)
            printf("8) Произведение предпоследней (%d) и второй (%d): %d\n", preLastDigit, secondDigit, prodPreLastSecond);
            printf("9) Сумма четных цифр (без последней): %d\n", sumEvenExceptLast);
            printf("10) Кол-во рядом стоящих одинаковых цифр: %d\n", countAdjacent);
            printf("11) Сумма 1-й половины: %d, 2-й: %d. Они %s\n", sumFirstHalf, sumSecondHalf, isHalvesEqual ? "РАВНЫ" : "НЕ РАВНЫ");
            printf("12) Произведение сумм (чет.разряды %d * нечет.разряды %d) = %d\n", sumEvenRazryad, sumOddRazryad, sumEvenRazryad * sumOddRazryad);
        }

        while (getchar() != '\n');

        printf("\nПродолжить? (Да - y, нет - n): ");
        repeat = getchar();

    } while (repeat == 'y' || repeat == 'Y');
    return 0;
}
void task3()
{
    int repeat;
    do {
        char symbol;
        int n;

        while (getchar() != '\n');

        printf("\nВведите символ (например, *): ");
        scanf("%c", &symbol);
        printf("Введите размер (рекомендуется 5-10): ");
        scanf("%d", &n);

        printf("\nЧертеж (Вариант 16):\n\n");

        for (int i = 1; i <= 2 * n - 1; i++) 
        {
            int spaces;
            if (i <= n) 
            {
                spaces = n - i;
            }
            else 
            {
                spaces = i - n;
            }

            for (int j = 1; j <= spaces; j++) 
            {
                printf(" ");
            }

            if (i == 1) 
            {
                printf("B"); 
            }
            else if (i == 2 * n - 1) 
            {
                printf("D");
            }
            else if (i == n) 
            {
                printf("A");
                for (int j = 1; j <= 2 * n - 3; j++) 
                {
                    if (j == n - 1) printf("r");
                    else printf("%c", symbol);
                }
                printf("C");
            }
            else 
            {
                printf("%c", symbol);
                for (int j = 1; j <= (2 * n - 3) - 2 * spaces; j++) 
                {
                    printf(" ");
                }
                printf("%c", symbol);
            }
            printf("\n");
        }

        printf("\nПродолжить? (Да - 1, Нет - 0): ");
        scanf("%d", &repeat);

    } while (repeat != 0);

    return 0;
}

