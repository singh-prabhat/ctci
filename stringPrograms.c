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
		i++;
	}

	i = 0;
	while((character = string2[i]) !='\0') {
		charUsage[character]--;

		if (charUsage[character] < 0)
			return -1;
		i++;
	}

	return 0;
}

int countSpaces(char *string)
{
	char *tmpPtr = string;
	int count = 0;
	if(tmpPtr)
	{
		while(*tmpPtr != '\0')
		{
			if(*tmpPtr == ' ')
				count++;
			tmpPtr++;
		}
	}  

	return count;
}


char *convertUrl(char *string, int length)
{
	int count = 0;
	char *readPtr = NULL;
	char *writePtr = NULL;
	if (string == NULL)
		return string;
	
	int numOfSpaces = countSpaces(string);

	readPtr = string + length - 1;

	writePtr = readPtr + (numOfSpaces * 2);
	*(writePtr+1) = '\0';

	while(count < length)
	{
		if(*readPtr != ' ')
			*writePtr = *readPtr;
		else
		{
			*(writePtr--) = '0';
			*(writePtr--) = '2';
			*(writePtr) = '%';
		}
		
		readPtr--;
		writePtr--;
		count++;
	}

	return writePtr;
}


void testPermutation()
{
	char string1[128];
	char string2[128];

	printf("\nTesting isPermutation()");
	printf("\n\tEnter first string: ");
	scanf("%s", string1);

	printf("\n\tEnter second string: ");
	scanf("%s", string2);

	if(isPermutation(string1, string2) == 0)
		printf("\n\tStrings are permutation\n");
	else
		printf("\n\tStrings are not permutation\n");	
}

void testUrlConverter()
{
	#define MAX_LENGH 	512
	#define SIZE		14

	int length = 0;
	char *inputUrls[] = {	"This is First Test URL", 
							"http//test", 
							"http//one space", 
							" space", 
							"Space middle", 
							"End ", 
							"multiple spaces in between", 
							" begining space with multiple spaces in between", 
							"multiple spaces in between with space at end "
							"     Consecutive_at_begining",
							"Consecutive_at_end       ",
							"multiple consecutive spaces      in      between",
							"multiple consecutive    spaces      in       between     with      space     at end         ",
							"NO_SPACES_AT_ALL"
							};

	char inputStrings[MAX_LENGH][SIZE-1];

	int samples = SIZE;
	
	printf("\n Testing convertUrl()::\n");
	
	for (int i = 0; i < samples - 1; i++)
	{
		printf ("\n\tInput String: %s", inputUrls[i]);
		strcpy(inputStrings[i], inputUrls[i]);
		length = strlen(inputStrings[i]);
		convertUrl(inputStrings[i], length);
		printf ("\n\tOutPut String: %s", inputStrings[i]);
	}
}


int main()
{
	int choice = 0;
	while (1) 
	{
		printf("\n Please choose the function for testing: \n");
		printf("\n\tFor testing \"convertUrl()\", enter 1: ");
		printf("\n\tFor testing \"isPermutation()\", enter 2: ");
		printf("\n\tFor finishing testing enter -99:");
		printf("\n\tEnter your choice now: ");

		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				testUrlConverter();
				break;
			case 2:
				testPermutation();
				break;
			case -99:
				printf("\n Finished testing\n\n");
				return 0;
			default:
				printf("\n Please make a valid choice");
				break;
		}

		printf("\n ====================================================================================:");
		printf("\n ====================================================================================:\n");
	}

	return 0;
}
