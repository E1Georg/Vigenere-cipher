#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "str.h"

void Encrypt(inputPath, outputPath) {
	
	FILE *inputText;
	FILE *outText;

	if ((inputText = fopen(inputPath, "r")) == NULL) {
		printf("Невозможно открыть файл с исходным сообщением.\n");
		getchar();
		exit(1);
	}
	if ((outText = fopen(outputPath, "w")) == NULL) {
		printf("Невозможно открыть файл вывода зашифрованного сообщения.\n");
		getchar();
		exit(1);
	}

	printf("\n");
	printf("Вы приступили к шифрованию сообщения,\n");
	printf("Введите закрытый ключ: ");

	// Получим из консоли секретный ключ.
	int keyLength;
	char *privateKey = get_string(&keyLength);

	printf("\nЗашифрованное сообщение: ");

	int countSymbolsOnKey = 0;
	int symbolNumber, keyNumber;

	// Далее из "inputText" получим исходный символ, вычислим для него "зашифрованный символ" и поместим его в "outputText".
	char symbol = fgetc(inputText);
	while (symbol != EOF) {		

		if (strchr(Alphabet, symbol) == NULL) {
			printf("\nВ исходном сообщении обнаружен нераспознаваемый символ, шифрование прервано. Обновите алфавит.\n");
			getchar();
			exit(1);
		}
		else {
			//Получим позицию символа в заданном алфавите. Алфавит расположен в main.c
			symbolNumber = strchr(Alphabet, symbol) - Alphabet; 
		}

		if (strchr(Alphabet, privateKey[countSymbolsOnKey]) == NULL) {
			printf("\nВ ключе обнаружен нераспознаваемый символ, шифрование прервано. Обновите алфавит.\n");
			getchar();
			exit(1);
		}
		else {
			//Получим позицию символа ключа в заданном алфавите. Алфавит задаётся в main.c
			keyNumber = strchr(Alphabet, privateKey[countSymbolsOnKey]) - Alphabet; 
		}

		//Получим позицию зашифрованного символа в заданном алфавите. Алфавит задаётся в main.c
		symbolNumber += keyNumber;
		symbolNumber = symbolNumber % Length;
		keyNumber = Alphabet[symbolNumber]; 

		//Счётчик позиций ключа, таким образом символы ключа подставляются под символы входного сообщения.
		countSymbolsOnKey++; 
		if (countSymbolsOnKey == keyLength) countSymbolsOnKey = 0;

		printf("%c", keyNumber);
		fputc(keyNumber, outText);

		symbol = fgetc(inputText);
	}printf("\n");
	
	fclose(inputText);
	fclose(outText);	
	free(privateKey);
}
