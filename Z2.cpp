#include <locale>

#include <iostream>
using namespace std;


//������� 14 (������� 39)

int main() {

	setlocale(LC_ALL, "Russian");

	int n;

	cout << "������� ����������� ������� A ����������� n �� n: ";
	cin >> n;

	int** A = new int* [n];
	for (int i = 0; i < n; i++)
		*(A + i) = new int[n];


	int sum_0 = 0, sum_1 = 0;

	cout << "������� �������� ������� A: " << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> *(*(A + i)+j);
			if (*(*(A + i) + j) == 0) sum_0++;
			if (*(*(A + i) + j) == 1) sum_1++;
		}
			

	cout << "�������� ������� A: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << *(*(A + i) + j) << ' ';
		cout << endl;
	}

	cout << "���������� ����� � ������� A ����� " << sum_0 << endl;
	cout << "���������� ������ � ������� A ����� "<< sum_1 << endl;



	for(int i = 0; i < n; i++) 
		delete[] *(A + i);
	delete[] A;

}