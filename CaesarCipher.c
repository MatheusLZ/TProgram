#include<cs50.h>
#include<stdio.h>
#include<string.h>

int
main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("Erro. Digite um número na linha de comando.\n");
		return 1;
	}

	printf("Texto a ser criptografado:\n");
	string text = GetString();
	int k = atoi(argv[1]);

	for (int i = 0, j = strlen(text); i < j; i++) {
		if (text[i] >= 65 && text[i] <= 90)
			text[i] = (((text[i] - 65) + k) % 26) + 65;
		else if (text[i] >= 97 && texto[i] <= 122)
			text[i] = (((text[i] - 97) + k) % 26) + 97;
		printf("%c", text[i]);
	}

	printf("\nKey = %d.\n", k);
	return 0;
}
