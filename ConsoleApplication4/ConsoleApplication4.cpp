#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    double** a, b; // основной массив и вспомогательный
    int i, j, n, m, k;

    //Ввод размера массива в консоль
    cout << "Введите размер матрицы A(NxM)" << endl;
    cout << "N="; cin >> n;
    cout << "M="; cin >> m;

    //Создание двумерного массива 
    a = new double* [n];
    for (i = 0; i < n; i++)
        a[i] = new double[m];

    //Ввод в консоль значений каждого элемента массива
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            cout << "Введите A[" << i << "][" << j << "]:";
            cin >> a[i][j];
        }

    // Вывод введенного массива
    cout << "Ваш Массив:" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            cout << setw(10) << a[i][j] << " ";
        cout << endl;
    }

    //Сортировка строк массива
    for (i = 0; i < n - 1; i++) 
    {
        for (k = 0; k < n - 1; k++) 
        {
            if (a[k][0] > a[k + 1][0]) //Сравнения первых элементов нынешней строки со следующей
            {
                for (j = 0; j < m; j++) 
                {
                    b = a[k][j]; //Запись элемента из основного массива в вспомогательный
                    a[k][j] = a[k + 1][j]; // Перенос следущей строки в предыдущую
                    a[k + 1][j] = b; //Перенос из вспомогательного в основной
                }
            }
        }
    }
    cout << "Result:" << endl;

    //Вывод отсортированного массива
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            cout << setw(10) << a[i][j] << " ";
        cout << endl;
    }

    //Очистка данных массива
    for (i = 0; i < n; i++)
        delete[] a[i];
    delete[]a;
    a = NULL;
    return 0;
}