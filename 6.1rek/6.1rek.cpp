#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

// Формування масиву
void CreateArray(int p[], int n, int i = 0)
{
    if (i == n)
        return;

    p[i] = 15 + rand() % 80;
    CreateArray(p, n, i + 1);
}

// Виведення масиву
void PrintArray(const int p[], int n, int i = 0)
{
    if (i == n)
    {
        cout << endl;
        return;
    }

    cout << setw(4) << p[i];
    PrintArray(p, n, i + 1);
}

// Перевірка критерію
bool IsTargetIndex(int i)
{
    return !(i % 2 == 0 && i % 13 == 0);
}

// Підрахунок елементів
int CountElements(const int p[], int n, int i = 0)
{
    if (i == n)
        return 0;

    return (IsTargetIndex(i) ? 1 : 0)
        + CountElements(p, n, i + 1);
}

// Обчислення суми
int SumElements(const int p[], int n, int i = 0)
{
    if (i == n)
        return 0;

    return (IsTargetIndex(i) ? p[i] : 0)
        + SumElements(p, n, i + 1);
}

// Заміна елементів нулями
void ZeroElements(int p[], int n, int i = 0)
{
    if (i == n)
        return;

    if (IsTargetIndex(i))
        p[i] = 0;

    ZeroElements(p, n, i + 1);
}

// Короткий unit-тест
void UnitTest()
{
    int p[] = { 20, 30, 40, 50, 60 };
    int n = 5;

    assert(CountElements(p, n) == 4);
    assert(SumElements(p, n) == 180);

    ZeroElements(p, n);

    assert(p[0] == 20);
    assert(p[1] == 0 && p[2] == 0);
    assert(p[3] == 0 && p[4] == 0);
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    const int N = 25;
    int p[N];

    CreateArray(p, N);

    cout << "\nOriginal array:\n";
    PrintArray(p, N);

    int count = CountElements(p, N);
    int sum = SumElements(p, N);

    ZeroElements(p, N);

    cout << "\nNumber of elements: " << count << endl;
    cout << "Sum of elements: " << sum << endl;

    cout << "\nModified array:\n";
    PrintArray(p, N);

    return 0;
}