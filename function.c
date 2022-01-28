#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

// ������� �� ������������ ������. ����� ��� ��� ������ ��������� � ������ ����� ��������� �� ������ char �� �������.
char *get_string(int *length) {

	// ���������� ��� ������������ ����� ������ ����� 0, �� ���� ������ '\0';
	*length = 0;
	int scale = 1;
	char *string = NULL;
	char *tmp = NULL;

	if ((string = (char*)malloc(scale * sizeof(char))) == NULL) {
		printf("������ ������! ������ ��� ������ string, function.c �� ��������!\n");
		getchar();
		exit(1);
	}	

	char symbol;
	scanf(" %c", &symbol);

	// ������� ����� ������ � �������� ��� � ������. ���� ������ ������� ������, ��� ���������, �� ����������� ������ ��� ��������.
	while (symbol != '\n') {
		string[(*length)++] = symbol; 

		if (*length >= scale) {
			scale *= 2;
			tmp = string;
			string = NULL;

			if ((string = (char*)realloc(tmp, scale * sizeof(char))) == NULL) {
				printf("������ ������! ������ ��� ������ string, function.c �� ������������!\n");
				getchar();
				exit(1);
			}
			tmp = NULL;			
		}
		scanf("%c", &symbol);
	}

	string[*length] = '\0';
	return string;
}
