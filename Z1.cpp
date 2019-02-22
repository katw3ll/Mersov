#include <locale>

#include <iostream>
using namespace std;


//������� 14 (������ 14)

int main() {

	setlocale(LC_ALL, "Russian");

	int n1, n2;

	cout << "������� ����������� �������� A � B ����� ������: ";
	cin >> n1 >> n2;

	int* A = new int[n1];
	int* B = new int[n2];


	cout << "������� �������� ������� A: ";
	for (int i = 0; i < n1; i++)
		cin >> *(A+i);

	cout << "������� �������� ������� B: ";
	for (int i = 0; i < n2; i++)
		cin >> *(B + i);

	int min_A = *A;
	for (int i = 1; i < n1; i++)
		if (min_A > *(A + i)) min_A = *(A + i);

	int min_B = *B;
	for (int i = 1; i < n2; i++)
		if (min_B > *(B + i)) min_B = *(B + i);


	cout << "�������� ������� A: " << endl;
	for (int i = 0; i < n1; i++) 
		cout << *(A + i) << ' ';

	cout << endl << "�������� ������� B: " << endl;
	for (int i = 0; i < n2; i++) 
		cout << *(B + i) << ' ';

	cout << endl;

	cout << "����������� ������� ������� A: " << min_A << endl
		 << "����������� ������� ������� B: " << min_B << endl;
	
	cout << "�������� ������� A ����� ��������� �� ����������� �������: " << endl;
	for (int i = 0; i < n1; i++) {
		*(A + i) *= min_A;
		cout << *(A + i) << ' ';
	}
	
	cout << endl << "�������� ������� B ����� ��������� �� ����������� �������: " << endl;
	for (int i = 0; i < n2; i++) {
		*(B + i) *= min_B;
		cout << *(B + i) << ' ';
	}

	cout << endl;


	delete[] A;
	delete[] B;

	return 0;
}