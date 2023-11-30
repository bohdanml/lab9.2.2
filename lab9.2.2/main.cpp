#include <iostream>
#include <Windows.h>
#include <string>
#include "Student.h"
#include <algorithm>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N, K = 3, menuItem;
    cout << "Введіть кількість студентів N: ";
    cin >> N;

    Student* p = new Student[N];
    cout << endl << endl << endl;

    int* indexArray = new int[N];
    for (int i = 0; i < N; i++) {
        indexArray[i] = i; 
    }
    do
    {
        cout << "\nОберіть дію:" << endl << endl;
        cout << "(1) – Створити таблицю \n(2) – Вивести таблицю, \n(3) – Вивести кількість студентів, які мають середній бал більше 4.5, з вказаною умовою \n(4) - Вивести предмет з найвищим середнім балом\n(5) - Впорядкувати за умовою\n(0) - Вихід\nВведіть номер опції: ";
        cin >> menuItem;
        switch (menuItem)
        {
        case 1: Create(p, N); break;
        case 2:
            // Сортування за допомогою індексного масиву
            sort(indexArray, indexArray + N, [&p](int a, int b) {
                return compareStudents(p[a], p[b]);
                });

            // Вивід відсортованої таблиці
            PrintTable(p, N, indexArray);
            break;
        case 3: Output3(QuantOfStudentsMarkThan45(p, N, K), "Кількість студентів, які мають середній бал більше 4.5: "); break;
        case 4: cout << SubjmaxAvgMark(p, N, K); break;
        case 0: break;
        }
    } while (menuItem != 0);



    cout << endl << endl << endl;
}
