#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#pragma warning(disable : 4996)

//���������� ����������� ����� =) ��� VS


#include <stdio.h>
#include <locale>


struct persons {
	char name[20];
	char surname[20];
	char patronymic[20];
};
struct addresses {
	char street[20];
	int number_house;
	int number_room;
};

struct profile {
	persons person;
	addresses address;
	int sex;
	int age;
};




int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	printf("������� ���������� �����: ");
	scanf("%d", &n);
	printf("\n======= WARNING!!!! ������ ������� ������ �� ���������� �����!!! =======\n\n");
	profile* Persons = new profile[n];
	for (int i = 0; i < n; i++) {
		printf(" ==== ������ %d ==== \n");
		printf("������� �������, ��� � ��������:\n"); 
		scanf("%s %s %s", &Persons[i].person.name, &Persons[i].person.surname, &Persons[i].person.patronymic);
		printf("������� �������� �����, ����� ���� � ����� ��������:\n");
		scanf("%s %d %d", &Persons[i].address.street, &Persons[i].address.number_house, &Persons[i].address.number_room);
		printf("������� ��� ���/��� (1/0): ");
		scanf("%d", &Persons[i].sex);
		printf("������� �������: ");
		scanf("%d", &Persons[i].age);
		printf("\n");
	}

	

	for (int i = 0; i < n; i++) {
		printf(" ==== ������� %d ==== \n", i);
		printf("�������, ���, ��������: %s, %s, %s\n", Persons[i].person.name, Persons[i].person.surname, Persons[i].person.patronymic);
		printf("�����: %s\n", Persons[i].address.street);
		printf("����� ����: %d\n", Persons[i].address.number_house);
		printf("����� �������: %d\n", Persons[i].address.number_room);
		printf("���: %s\n", Persons[i].sex ? "���" : "���");
		printf("�������: %d\n", Persons[i].age);
		printf("\n");
	}

	printf("����� ������ ������� ������� �������� � �������� �������� �� 50 ��� ��������� �� ����� �����.\n������� �����: ");
	char street[20];
	scanf("%s", &street);
	int count = 0;

	for (int i = 0; i < n; i++) {
		if (Persons[i].age < 50 && !strcmp(Persons[i].address.street, street))
			count++;
	}

	printf("�������: %d �������", count);


	return 0;
}