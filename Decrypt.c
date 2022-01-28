#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "str.h"

void Decrypt(inputPath, outputPath) {

	FILE *inputText;
	FILE *outText;

	if ((inputText = fopen(inputPath, "r")) == NULL) {
		printf("Невозможно открыть файл input.\n");
		getchar();
		exit(1);
	}
	if ((outText = fopen(outputPath, "w")) == NULL) {
		printf("Невозможно открыть файл Out.\n");
		getchar();
		exit(1);
	}

	printf("\n");
	printf("Вы приступили к расшифрованию сообщения,\n");
	printf("Введите закрытый ключ: ");
	
	//Получим из консоли ключ и узнаем его длину.
	int keyLength;
	char *privateKey = get_string(&keyLength);

	printf("\nРасшифрованное сообщение: ");

	int countSymbolsOnKey = 0;
	int symbolNumber, keyNumber;

	// Далее из "inputText" получим исходный символ, вычислим для него "расшифрованный символ" и поместим его в "outputText".
	char symbol = fgetc(inputText);	
	while (symbol != EOF) {

		if (strchr(Alphabet, symbol) == NULL) {
			printf("В исходном сообщении обнаружен нераспознаваемый символ, шифрование прервано. Обновите алфавит.\n");
			getchar();
			exit(1);
		}
		else {
			//Получим позицию символа в заданном алфавите. Алфавит задаётся в main.c
			symbolNumber = strchr(Alphabet, symbol) - Alphabet; 
		}

		if (strchr(Alphabet, privateKey[countSymbolsOnKey]) == NULL) {
			printf("В ключе обнаружен нераспознаваемый символ, шифрование прервано. Обновите алфавит.\n");
			getchar();
			exit(1);
		}
		else {
			//Получим позицию ключа в заданном алфавите. Алфавит задаётся в main.c
			keyNumber = strchr(Alphabet, privateKey[countSymbolsOnKey]) - Alphabet; 
		}

		//Получим позицию зашифрованного символа в заданном алфавите. Алфавит задаётся в main.c
		symbolNumber += Length;
		symbolNumber -= keyNumber;
		symbolNumber = symbolNumber % Length;
		keyNumber = Alphabet[symbolNumber]; 

		//Счётчик позиций ключа, таким образом символы ключа подставляются под символы входного сообщения.
		countSymbolsOnKey++;
		if (countSymbolsOnKey == keyLength) countSymbolsOnKey = 0;

		fputc(keyNumber, outText);
		printf("%c", keyNumber);

		symbol = fgetc(inputText);
	}printf("\n");

	fclose(inputText);
	fclose(outText);
	free(privateKey);
}
