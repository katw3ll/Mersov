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
	for (int i = 0; i < size; i++) { //����� ������
		printf("\n=== ������� �%d � ������� %p\n", i + 1, EL);
		printf("��������� �� ������� �������:%p\n", EL->pred);
		printf("�������: %g\n", EL->ELEM);
		printf("��������� �� ��������� �������:%p\n", EL->post);
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
	printf("������� ���������� ��������� ������: ");
	scanf("%d",&size);
	printf("������� �������� ������: \n");
	//���� ���������
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
	printf("�����: %p\n", tail);
	printf("������: %p\n", head);
	printf("\n===============\n\n");


	printf("������� �����, ������� �� ������ �������: ");
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
			printf("\n-> ������� %g ������\n", EL->ELEM);
			free(EL);
			break;
		}
		if (EL->post != NULL)
			EL = EL->post;
	}

	printList(tail, size);

	printf("\n===============\n\n");
	printf("�����: %p\n", tail);
	printf("������: %p\n", head);
	printf("\n===============\n\n");

	return 0;
}