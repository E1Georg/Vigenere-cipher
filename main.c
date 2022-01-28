#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include "str.h"

// Зададим алфавит символов, которые составят "tabula recta".
unsigned char Alphabet[] = "abcdefghijklmnopqrstuvwxyz"; 
// Длина заданного алфавита.
int Length = (sizeof(Alphabet) / sizeof(Alphabet[0])) - 1; 

int main() {
	setlocale(LC_ALL, "Rus");	
	printText();

	char *code;
	int lengthString;

	for (;;) {
		// Пользователь должен выбрать действие. Получим соответствующий код.
		printf("Введите ключ: ");
		code = get_string(&lengthString); 

		if (lengthString >= 2) {
			printf("Вы ввели неверный код! Для вызова справки введите \"4\".\n");
		}
		else if (strcmp(code, "1") == 0) {
			printf("Программа будет завершена!");
			
			free(code);
			break;
		}
		else if (strcmp(code, "2") == 0) {
		// 1-ым и 2-ым параметром передаётся путь к файлу.
			Encrypt("Input.txt", "Encrypt.txt"); 
		}
		else if (strcmp(code, "3") == 0) {
		// 1-ым и 2-ым параметром передаётся путь к файлу.
			Decrypt("Encrypt.txt", "Decrypt.txt"); 
		}
		else if (strcmp(code, "4") == 0) {
			helpText();
		}
		else {
			printf("Вы ввели неверный код! Для вызова справки введите \"4\".\n");
		}
		free(code);
	}	
	return 0;
}
