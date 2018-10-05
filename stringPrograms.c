#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_TABLE_SIZE	128

int isPermutation(char *string1, char *string2)
{
	char character = 0;
	int i = 0;

	int charUsage[ASCII_TABLE_SIZE];
	for (i = 0; i < ASCII_TABLE_SIZE; i++)
		charUsage[i] = 0;

	if((string1 == NULL) || (string2 == NULL))
		return -1;
	
	int str1Len = strlen (string1);
	int str2Len = strlen (string2);

	if (str1Len != str2Len)
		return -1;

	i = 0;
	while((character = string1[i]) !='\0')
	{
		charUsage[character]++;

		printf("\n Debug: Char: %c, Use: %d", character, charUsage[character]);
		i++;
	}

	i = 0;
	while((character = string2[i]) !='\0') {
		charUsage[character]--;

		printf("\n Debug: Char: %c, Use: %d", character, charUsage[character]);

		if (charUsage[character] < 0)
			return -1;
		i++;
	}

	return 0;
}


int main()
{
	char string1[128];
	char string2[128];

	printf("\n Enter first string: ");
	scanf("%s", string1);

	printf("\n Enter second string: ");
	scanf("%s", string2);

	if(isPermutation(string1, string2) == 0)
		printf("\n Strings are permutation\n");
	else
		printf("\n Strings are not permutation\n");	
}
