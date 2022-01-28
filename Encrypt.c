#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "str.h"

void Encrypt(inputPath, outputPath) {
	
	FILE *inputText;
	FILE *outText;

	if ((inputText = fopen(inputPath, "r")) == NULL) {
		printf("���������� ������� ���� � �������� ����������.\n");
		getchar();
		exit(1);
	}
	if ((outText = fopen(outputPath, "w")) == NULL) {
		printf("���������� ������� ���� ������ �������������� ���������.\n");
		getchar();
		exit(1);
	}

	printf("\n");
	printf("�� ���������� � ���������� ���������,\n");
	printf("������� �������� ����: ");

	// ������� �� ������� ��������� ����.
	int keyLength;
	char *privateKey = get_string(&keyLength);

	printf("\n������������� ���������: ");

	int countSymbolsOnKey = 0;
	int symbolNumber, keyNumber;

	// ����� �� "inputText" ������� �������� ������, �������� ��� ���� "������������� ������" � �������� ��� � "outputText".
	char symbol = fgetc(inputText);
	while (symbol != EOF) {		

		if (strchr(Alphabet, symbol) == NULL) {
			printf("\n� �������� ��������� ��������� ���������������� ������, ���������� ��������. �������� �������.\n");
			getchar();
			exit(1);
		}
		else {
			//������� ������� ������� � �������� ��������. ������� ���������� � main.c
			symbolNumber = strchr(Alphabet, symbol) - Alphabet; 
		}

		if (strchr(Alphabet, privateKey[countSymbolsOnKey]) == NULL) {
			printf("\n� ����� ��������� ���������������� ������, ���������� ��������. �������� �������.\n");
			getchar();
			exit(1);
		}
		else {
			//������� ������� ������� ����� � �������� ��������. ������� ������� � main.c
			keyNumber = strchr(Alphabet, privateKey[countSymbolsOnKey]) - Alphabet; 
		}

		//������� ������� �������������� ������� � �������� ��������. ������� ������� � main.c
		symbolNumber += keyNumber;
		symbolNumber = symbolNumber % Length;
		keyNumber = Alphabet[symbolNumber]; 

		//������� ������� �����, ����� ������� ������� ����� ������������� ��� ������� �������� ���������.
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
