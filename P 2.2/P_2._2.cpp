#include <iostream>
#include <list>

using namespace std;

//  РЕКУРСИЯ ДЛЯ ПЕРВОЙ ЗАДАЧИ
int recursion1(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n % 3 == 0 && n > 0)
    {
        return (n + recursion1(n-3));
    }
    else if ((n % 3) > 0)
    {
        return (n + recursion1(n - (n % 3)));
    }
}

//  РЕКУРСИЯ ДЛЯ ВТОРОЙ ЗАДАЧИ
int recursion2(list<int> lst)
{
    if (lst.empty())
    {
        return 0;
    }

    int current = lst.front();
    lst.pop_front();
    
    if (current % 2 != 0)
    {
        return current + recursion2(lst);
    }
    else
    {
        return recursion2(lst);
    }
}

void recursion3(int start, int end, bool even) {
    // Базовый случай: если start больше end, прекращаем рекурсию
    if (start > end) {
        return;
    }

    // Определяем, является ли текущее число четным или нечетным
    bool isEven = (start % 2 == 0);

    // Если требуется печатать четные числа и текущее число четное
    if (even && isEven) {
        cout << start << " ";
    }
    // Если требуется печатать нечетные числа и текущее число нечетное
    else if (!even && !isEven) {
        cout << start << " ";
    }

    // Рекурсивный вызов для следующего числа
    recursion3(start + 1, end, even);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Практика 2 | Вариант 2\n";

    //ЗАДАНИЕ 1
    cout << "Задание 1\n";
    
    int n = 0;
    cout << "Введите значение n: ";
    cin >> n;
    
    int result1 = recursion1(n);
    cout << "Результат: " << result1 << endl;

    //ЗАДАНИЕ 2
    cout << "Задание 2\n";
    
    list<int> lst {1, 31, 55, 46, 24, 98, 7, 66};
    
    int result2 = recursion2(lst);
    cout << "Результат: " << result2 << endl;
    
    //ЗАДАНИЕ 3
    cout << "Задание 3\n";

    
    int start = 1;
    int end = 10;

    cout << "Четные числа в диапазоне от " << start << " до " << end << ":\n";
    recursion3(start, end, true);

    cout << "\nНечетные числа в диапазоне от " << start << " до " << end << ":\n";
    recursion3(start, end, false);
    
    return 0;
}