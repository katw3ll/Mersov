#include <locale>

#include <iostream>
using namespace std;


//Вариант 14 (Заздача 39)

int main() {

	setlocale(LC_ALL, "Russian");

	int n;

	cout << "Введите размерность матрицы A рамерностью n на n: ";
	cin >> n;

	int** A = new int* [n];
	for (int i = 0; i < n; i++)
		*(A + i) = new int[n];


	int sum_0 = 0, sum_1 = 0;

	cout << "Введите элементы матрицы A: " << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> *(*(A + i)+j);
			if (*(*(A + i) + j) == 0) sum_0++;
			if (*(*(A + i) + j) == 1) sum_1++;
		}
			

	cout << "Элементы матрицы A: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << *(*(A + i) + j) << ' ';
		cout << endl;
	}

	cout << "Количество нулей в матрице A равно " << sum_0 << endl;
	cout << "Количество единиц в матрице A равно "<< sum_1 << endl;



	for(int i = 0; i < n; i++) 
		delete[] *(A + i);
	delete[] A;

}