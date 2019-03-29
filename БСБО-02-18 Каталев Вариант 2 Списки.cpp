#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#pragma warning(disable : 4996)


#include <locale>
#include <stdio.h>

struct el {
	struct el* pred;
	float ELEM;
	struct el* post;
};


void printList(el *EL, int size) {
	for (int i = 0; i < size; i++) { //¬ывод списка
		printf("\n=== Ёлемент є%d с адресом %p\n", i + 1, EL);
		printf("”казатель на прошлый элемент:%p\n", EL->pred);
		printf("Ёлемент: %g\n", EL->ELEM);
		printf("”казатель на следующий элемент:%p\n", EL->post);
		if (EL->post != NULL)
			EL = EL->post;
	}
}


int main() {
	
	setlocale(LC_ALL,"");

	el* head = NULL;
	el* EL = NULL;
	el* tail = NULL;
	
	int size,i = 0;
	printf("¬ведите количество элементов списка: ");
	scanf("%d",&size);
	printf("¬ведите элементы списка: \n");
	//¬вод элементов
	for (i = 0; i < size; i++)
	{
		EL = (struct el*)malloc(sizeof(struct el));
		EL->pred = NULL;
		EL->post = NULL;
		printf("\t%d: ",i+1);
		scanf("%f", &(EL->ELEM));
		if (head == NULL) {
			head = tail = EL;
		}
		else {
			tail->pred = EL;
			EL->post = tail;
			tail = EL;
		}
	}

	printList(tail, size);


	printf("\n===============\n\n");
	printf("’вост: %p\n", tail);
	printf("√олова: %p\n", head);
	printf("\n===============\n\n");


	printf("¬ведите число, которое вы хотите удалить: ");
	float p;
	scanf("%f", &p);

	EL = tail;
	for (i = 0; i < size; i++) { 
		if (EL->ELEM == p) {
			if (EL->pred != NULL && EL->post != NULL) {
				(EL->pred)->post = EL->post;
				(EL->post)->pred = EL->pred;
			}
			else {
				if (EL->pred == NULL && EL->post == NULL)
				{
					head = NULL;
					tail = NULL;
				}
				else {
					if (EL->post == NULL) {
						(EL->pred)->post = NULL;
						head = EL->pred;
					}

					if (EL->pred == NULL) {
						tail = EL->post;
						(EL->post)->pred = NULL;
					}
				}
			}

			size--;
			printf("\n-> Ёлемент %g удален\n", EL->ELEM);
			free(EL);
			break;
		}
		if (EL->post != NULL)
			EL = EL->post;
	}

	printList(tail, size);

	printf("\n===============\n\n");
	printf("’вост: %p\n", tail);
	printf("√олова: %p\n", head);
	printf("\n===============\n\n");

	return 0;
}