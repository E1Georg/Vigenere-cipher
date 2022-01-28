#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include "str.h"

// ������� ������� ��������, ������� �������� "tabula recta".
unsigned char Alphabet[] = "abcdefghijklmnopqrstuvwxyz"; 
// ����� ��������� ��������.
int Length = (sizeof(Alphabet) / sizeof(Alphabet[0])) - 1; 

int main() {
	setlocale(LC_ALL, "Rus");	
	printText();

	char *code;
	int lengthString;

	for (;;) {
		// ������������ ������ ������� ��������. ������� ��������������� ���.
		printf("������� ����: ");
		code = get_string(&lengthString); 

		if (lengthString >= 2) {
			printf("�� ����� �������� ���! ��� ������ ������� ������� \"4\".\n");
		}
		else if (strcmp(code, "1") == 0) {
			printf("��������� ����� ���������!");
			
			free(code);
			break;
		}
		else if (strcmp(code, "2") == 0) {
		// 1-�� � 2-�� ���������� ��������� ���� � �����.
			Encrypt("Input.txt", "Encrypt.txt"); 
		}
		else if (strcmp(code, "3") == 0) {
		// 1-�� � 2-�� ���������� ��������� ���� � �����.
			Decrypt("Encrypt.txt", "Decrypt.txt"); 
		}
		else if (strcmp(code, "4") == 0) {
			helpText();
		}
		else {
			printf("�� ����� �������� ���! ��� ������ ������� ������� \"4\".\n");
		}
		free(code);
	}	
	return 0;
}
