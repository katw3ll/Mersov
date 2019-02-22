#include <locale>

#include <iostream>
using namespace std;


//¬ариант 14 («адача 14)

int main() {

	setlocale(LC_ALL, "Russian");

	int n1, n2;

	cout << "¬ведите размерность массивов A и B через пробел: ";
	cin >> n1 >> n2;

	int* A = new int[n1];
	int* B = new int[n2];


	cout << "¬ведите элементы массива A: ";
	for (int i = 0; i < n1; i++)
		cin >> *(A+i);

	cout << "¬ведите элементы массива B: ";
	for (int i = 0; i < n2; i++)
		cin >> *(B + i);

	int min_A = *A;
	for (int i = 1; i < n1; i++)
		if (min_A > *(A + i)) min_A = *(A + i);

	int min_B = *B;
	for (int i = 1; i < n2; i++)
		if (min_B > *(B + i)) min_B = *(B + i);


	cout << "Ёлементы массива A: " << endl;
	for (int i = 0; i < n1; i++) 
		cout << *(A + i) << ' ';

	cout << endl << "Ёлементы массива B: " << endl;
	for (int i = 0; i < n2; i++) 
		cout << *(B + i) << ' ';

	cout << endl;

	cout << "ћинимальный элемент массива A: " << min_A << endl
		 << "ћинимальный элемент массива B: " << min_B << endl;
	
	cout << "Ёлементы массива A после умножени€ на минимальный элемент: " << endl;
	for (int i = 0; i < n1; i++) {
		*(A + i) *= min_A;
		cout << *(A + i) << ' ';
	}
	
	cout << endl << "Ёлементы массива B после умножени€ на минимальный элемент: " << endl;
	for (int i = 0; i < n2; i++) {
		*(B + i) *= min_B;
		cout << *(B + i) << ' ';
	}

	cout << endl;


	delete[] A;
	delete[] B;

	return 0;
}