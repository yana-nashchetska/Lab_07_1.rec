// Lab_7_1.cpp
// < Нащецька Яна >
// Лабораторна робота No 7.1.
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці.
// Варіант 16

#include <iostream>
#include <iomanip>
#include <time.h>
#include <windows.h>

using namespace std;

void Create(int** z, const int rowCount, const int colCount, const int Low,
	const int High, int i, int j);
void Print(int** z, const int rowCount, const int colCount, int i, int j);
void Sort(int** z, const int rowCount, const int colCount, int i0, int i1);
void Change(int** z, const int row1, const int row2, const int colCount, int j);
void Calc(int** z, const int rowCount, const int colCount, int i, int j, int& S, int& k);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand((unsigned)time(NULL));

	int Low = 11;
	int High = 67;

	int rowCount = 7;
	int colCount = 5;

	int** z = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		z[i] = new int[colCount];

	cout << "Початкова матриця: " << endl;
	Create(z, rowCount, colCount, Low, High, 0, 0);
	Print(z, rowCount, colCount, 0, 0);

	cout << "Впорядкована матриця: " << endl;
	Sort(z, rowCount, colCount, 1, 0);
	Print(z, rowCount, colCount, 0, 0);

	int S = 0;
	int k = 0;

	Calc(z, rowCount, colCount, 0, 0,  S, k);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;

	cout << "Матриця, в котрій елементи замінені нулями: " << endl;
	Print(z, rowCount, colCount, 0, 0);
	for (int i = 0; i < rowCount; i++)
		delete[] z[i];
	delete[] z;
	return 0;
}
void Create(int** z, const int rowCount, const int colCount, const int Low,
	const int High, int i, int j)
{
			z[i][j] = Low + rand() % (High - Low + 1);
			if (j < colCount - 1)
				Create(z, rowCount, colCount, Low, High, i, j + 1);
			else
				if (i < rowCount - 1)
					Create(z, rowCount, colCount, Low, High, i + 1, 0);
}
void Print(int** z, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << z[i][j];
	if (j < colCount - 1)
		Print(z, rowCount, colCount, i, j + 1);
	else 
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(z, rowCount, colCount, i + 1, 0);
		}
		else	
		cout << endl << endl;
}
void Sort(int** z, const int rowCount, const int colCount, int i0, int i1)
{
	if ((z[i1][0] < z[i1 + 1][0])
		||
		(z[i1][0] == z[i1 + 1][0] &&

			z[i1][1] < z[i1 + 1][1])
		||
		(z[i1][0] == z[i1 + 1][0] &&
			z[i1][1] == z[i1 + 1][1] &&
			z[i1][3] < z[i1 + 1][3]))
		Change(z, i1, i1 + 1, colCount, 0);

	if (i1 < rowCount - i0 - 1)
		Sort(z, rowCount, colCount, i0, i1 + 1);
	if (i0 < rowCount - 1)
		Sort(z, rowCount, colCount, i0 + 1, 0);	
}
void Change(int** z, const int row1, const int row2, const int colCount, int j)
{
	int tmp = z[row1][j];
	z[row1][j] = z[row2][j];
	z[row2][j] = tmp;
	
	if (j < colCount - 1)
		Change(z, row1, row2, colCount, j + 1);

}
void Calc(int** z, const int rowCount, const int colCount, int i,  int j, int& S, int& k)
{
	if (!(z[i][j] % 2 == 0 && z[i][j] % 13 == 0))
	{
		S += z[i][j];
		k++;
		z[i][j] = 0;
	}

	if (j < colCount - 1)
		Calc(z, rowCount, colCount, i, j + 1, S, k);

	if (i < rowCount - 1)
		Calc(z, rowCount, colCount, i + 1, 0, S, k);
			
}