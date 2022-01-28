#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

// Получим от пользователя строку. Затем под эту строку разместив в памяти вернём указатель на массив char со строкой.
char *get_string(int *length) {

	// Изначально для пользователя длина строки равна 0, но учтём символ '\0';
	*length = 0;
	int scale = 1;
	char *string = NULL;
	char *tmp = NULL;

	if ((string = (char*)malloc(scale * sizeof(char))) == NULL) {
		printf("Ошибка памяти! Память под массив string, function.c не выделена!\n");
		getchar();
		exit(1);
	}	

	char symbol;
	scanf(" %c", &symbol);

	// Получим новый символ и поместим его в массив. Если размер массива меньше, чем требуется, то перевыделим память под элементы.
	while (symbol != '\n') {
		string[(*length)++] = symbol; 

		if (*length >= scale) {
			scale *= 2;
			tmp = string;
			string = NULL;

			if ((string = (char*)realloc(tmp, scale * sizeof(char))) == NULL) {
				printf("Ошибка памяти! Память под массив string, function.c не перевыделена!\n");
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
