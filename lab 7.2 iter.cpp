#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

// Функція для створення матриці
void Create(int** a, const int n, const int Low, const int High) {
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = Low + rand() % (High - Low + 1);
        }
    }
}

// Функція для друку матриці
void Print(int** a, const int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(4) << a[i][j];
        }
        cout << endl;
    }
}

// Функція для пошуку мінімального парного елементу
bool SearchMinEven(int** a, const int n, int& minEven) {
    bool found = false;
    for (int j = 0; j < n; j += 2) { // перевіряємо лише парні стовпці
        for (int i = 0; i < n; ++i) {
            if (a[i][j] % 2 == 0) {
                if (!found || a[i][j] < minEven) {
                    minEven = a[i][j];
                    found = true;
                }
            }
        }
    }
    return found;
}

int main() {
    int Low = 7;
    int High = 65;
    int n;

    cout << "n = ";
    cin >> n;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    Create(a, n, Low, High);
    cout << "Original matrix:" << endl;
    Print(a, n);

    int minEven;
    if (SearchMinEven(a, n, minEven))
        cout << "min even = " << minEven << endl;
    else
        cout << "there are no even elements" << endl;

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
