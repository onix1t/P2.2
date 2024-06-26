﻿#include <iostream>
#include <list>

using namespace std;

// Рекурсия для задания 1
int recursion1(int n)
{
    if (n == 0)
    {
        return 0;
    } else if (n % 3 == 0 && n > 0)
    {
        return (n + recursion1(n-3));
    } else if ((n % 3) > 0)
    {
        return (n + recursion1(n - (n % 3)));
    }
}

// Рекурсия для задания 2
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
    } else
    {
        return recursion2(lst);
    }
}

// Рекурсия для задания 3
void recursion3(int start, int end, bool even) {
    if (start > end) {
        return;
    }

    bool isEven = (start % 2 == 0);

    if (even && isEven) {
        cout << start << " ";
    } else if (!even && !isEven) {
        cout << start << " ";
    }

    recursion3(start + 1, end, even);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Практика 2 | Вариант 2\n";

    // --[Задание 1]--
    cout << "Задание 1\n";
    
    int n = 0;
    cout << "Введите значение n: ";
    cin >> n;
    
    int result1 = recursion1(n);
    cout << "Результат: " << result1 << endl;

    // --[Задание 2]--
    cout << "Задание 2\n";
    
    list<int> lst {1, 31, 55, 46, 24, 98, 7, 66};
    
    int result2 = recursion2(lst);
    cout << "Результат: " << result2 << endl;
    
    // --[Задание 3]--
    cout << "Задание 3\n";

    
    int start = 1;
    int end = 10;

    cout << "Четные числа в диапазоне от " << start << " до " << end << ":\n";
    recursion3(start, end, true);

    cout << "\nНечетные числа в диапазоне от " << start << " до " << end << ":\n";
    recursion3(start, end, false);
    
    return 0;
}
