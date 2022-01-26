/*Домашнє завдання "Багатовимірні динамічні масиви"
1. Знайти суму елементів матриці, які є додатні.Кількість стовпців і рядків матриці повинен вводити користувач.За введеним даним, динамічно, повинна виділитися пам'ять під матрицю. Матрицю заповнювати випадковими значеннями,
як негативними так і позитивними.
Знайдіть суму елементів, які знаходяться на головній діагоналі.
Знайдіть суму елементів, які знаходяться на другорядній діагоналі.
Обчисліть суму елементів, які знаходяться під головною діагоналлю
2. Відсортуйте динамічний масив за зростанням або спаданням.
Реалізуйте меню для користувача.
Наприклад:
1 – сортування за зростанням
2 – за спаданням.
*/

#include <iostream>
#include <locale>;//загуглив варіант рішення відображення української мови в консолі
#include "windows.h";//загуглив варіант рішення відображення української мови в консолі
using namespace std;

void divisionArr(int** matrix, int n, int m) {



    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[m];
    }
}
void inputArr(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = rand() % 99 + (-31);//робимо рандом мінусово-плюсовим для того щоб виконувалася умова задачі на заповнення рандомними як відємними так і додатніми значеннями 
        }
    }
}
void printArr(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}
void deleteArr(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++)
    {
        delete[]matrix[i];
    }
}
void sotrArrUp(int** matrix, int n, int m) {//Функція що сортує елементи масиву за зростанням
    for (int k = 0; k < n; k++)
    {
        for (int l = 0; l < m; l++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (i + 1 == n && j + 1 == m) {
                        continue;
                    }
                    else {
                        if (j + 1 == m && matrix[i][j] > matrix[i + 1][0]) {
                            int temp = matrix[i][j];
                            matrix[i][j] = matrix[i + 1][0];
                            matrix[i + 1][0] = temp;
                        }
                        else {
                            if (j + 1 == m) {
                                continue;
                            }
                            else {
                                if (matrix[i][j] > matrix[i][j + 1]) {
                                    swap(matrix[i][j], matrix[i][j + 1]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}//функція 
void sotrArrDown(int** matrix, int n, int m) {//Функція що сортує елементи масиву за спаданням
    for (int k = 0; k < n; k++)
    {
        for (int l = 0; l < m; l++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (i + 1 == n && j + 1 == m) {
                        continue;
                    }
                    else {
                        if (j + 1 == m && matrix[i][j] < matrix[i + 1][0]) {
                            int temp = matrix[i][j];
                            matrix[i][j] = matrix[i + 1][0];
                            matrix[i + 1][0] = temp;
                        }
                        else {
                            if (j + 1 == m) {
                                continue;
                            }
                            else {
                                if (matrix[i][j] < matrix[i][j + 1]) {
                                    swap(matrix[i][j], matrix[i][j + 1]);
                                }
                            }
                        }
                    }
                }



            }



        }



    }
}
void sumArrPlus(int** matrix, int n, int m) {//Функція що визначає суму додатніх елементів масиву
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] > 0)
            {
                sum = sum + matrix[i][j];
            }
        }
    }
    cout << "Сума додатніх елементів матриці= " << sum << endl;
}
void sumArrMainD(int** matrix, int n, int m) {
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i] == matrix[j])
            {
                sum = sum + matrix[i][j];
            }
        }
    }
    cout << "Сума елементів головної діагоналі маматриці= " << sum << endl;
}
void sumArrSecondD(int** matrix, int n, int m) {
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i + j == m - 1)
            {
                sum = sum + matrix[i][j];
            }
        }
    }
    cout << "Сума елементів другорядної діагоналі маматриці= " << sum << endl;
}
void sumArrUnderMainD(int** matrix, int n, int m) {//функція яка сумує елементи під головною діагоналлю....
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            sum = sum + matrix[i][j];
        }
    }
    cout << "Сума елементів під головною діагоналлю маматриці= " << sum << endl;
}

int main()
{
    SetConsoleCP(1251);//загуглив варіант рішення відображення української мови в консолі
    SetConsoleOutputCP(1251);//загуглив варіант рішення відображення української мови в консолі
    int** matrix = nullptr;
    int n = 5;
    int m = 6;
    cout << "Введіть кількість рядків матриці - ";
    cin >> n;
    cout << "Введіть кількість стовпців матриці - ";
    cin >> m;
    matrix = new int* [n];
    divisionArr(matrix, n, m);
    inputArr(matrix, n, m);
    cout << "Наша матриця має такий вигляд:" << endl;
    printArr(matrix, n, m);
    cout << endl;
    sumArrPlus(matrix, n, m);//визиваємо функцію яка рахує суму додатніх елементів
    cout << endl;
    sumArrMainD(matrix, n, m);//визиваємо функцію яка рахує суму елементів головної діагоналі...
    cout << endl;
    sumArrSecondD(matrix, n, m);//визиваємо функцію яка рахує суму елементів допоміжної діагоналі...
    cout << endl;
    sumArrUnderMainD(matrix, n, m);//визиваємо функцію що рахує суму елементів під головною діагоналлю...
    cout << endl;

    bool choise = false; //на даному етапі розробили вибір сортування за зростанням або спаданням по вибору користувача 
    cout << "Вкажіть метод сортування 1 - Зростання, 0 - Спадання" << endl;
    cin >> choise;
    if (choise == true)
    {
        cout << "Ви вибрали сортування за зростанням" << endl;
        sotrArrUp(matrix, n, m);//визиваємо функцію сортування за зростанням 
        printArr(matrix, n, m);
        cout << endl;
    }
    else
    {
        cout << "Ви вибрали сортування за спаданням" << endl;
        sotrArrDown(matrix, n, m);//визиваємо функцію сортування за спаданням
        printArr(matrix, n, m);
    }

    deleteArr(matrix, n, m);
    delete[]matrix;
}