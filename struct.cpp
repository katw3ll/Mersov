#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#pragma warning(disable : 4996)

//Отключение безопасного ввода =) для VS


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
	printf("Введите количество людей: ");
	scanf("%d", &n);
	printf("\n======= WARNING!!!! Данные вводить только на английском языке!!! =======\n\n");
	profile* Persons = new profile[n];
	for (int i = 0; i < n; i++) {
		printf(" ==== АНКЕТА %d ==== \n");
		printf("Укажите Фамилию, Имя и Отчество:\n"); 
		scanf("%s %s %s", &Persons[i].person.name, &Persons[i].person.surname, &Persons[i].person.patronymic);
		printf("Укажите название улицы, номер дома и номер квартиры:\n");
		scanf("%s %d %d", &Persons[i].address.street, &Persons[i].address.number_house, &Persons[i].address.number_room);
		printf("Укажите пол муж/жен (1/0): ");
		scanf("%d", &Persons[i].sex);
		printf("Введите возраст: ");
		scanf("%d", &Persons[i].age);
		printf("\n");
	}

	

	for (int i = 0; i < n; i++) {
		printf(" ==== Профиль %d ==== \n", i);
		printf("Фамилия, имя, отчество: %s, %s, %s\n", Persons[i].person.name, Persons[i].person.surname, Persons[i].person.patronymic);
		printf("Улица: %s\n", Persons[i].address.street);
		printf("Номер дома: %d\n", Persons[i].address.number_house);
		printf("Номер комнаты: %d\n", Persons[i].address.number_room);
		printf("Пол: %s\n", Persons[i].sex ? "муж" : "жен");
		printf("Возраст: %d\n", Persons[i].age);
		printf("\n");
	}

	printf("Чтобы узнать сколько человек мужского и женского возраста до 50 лет проживает на одной улице.\nВведите улицу: ");
	char street[20];
	scanf("%s", &street);
	int count = 0;

	for (int i = 0; i < n; i++) {
		if (Persons[i].age < 50 && !strcmp(Persons[i].address.street, street))
			count++;
	}

	printf("Найдено: %d человек", count);


	return 0;
}