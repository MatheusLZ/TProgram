#include<cc50.h>
#include<stdio.h>
#include<string.h>

int
main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("put a text argument\n");
		return 1;
	}

	printf("ciphertext:\n");
	string text = GetString();

	int k = 0, l = strlen(text), m = strlen(argv[1]);

	for (int i = 0, j = 0; i < l; i++) {
		if (j == m)
			j = 0;

		k = (int)argv[1][j];
		    if (k >= 65 && k <= 90)
			    k -= 65;
		    else if (k >= 97 && k <= 122)
			    k -= 97;
	    	else
			    k = 0;

		if (text[i] >= 65 && text[i] <= 90) {
			text[i] = (((text[i] - 65) + k) % 26) + 65;
			j++;
		}
		else if (text[i] >= 97 && text[i] <= 122) {
			text[i] = (((text[i] - 97) + k) % 26) + 97;
			j++;
		}

		printf("%c", text[i]);
	}

	printf("\n");
	return 0;
}
