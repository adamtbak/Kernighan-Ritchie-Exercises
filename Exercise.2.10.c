/* Exercise 2-10: Rewrite the function lower, which converts upper case
 * letters to lower case, with a conditional expression instead of if-else.
 * 
 * We include the original lower function for comparative purposes.
 */

#include <stdio.h>

int lowerOriginal(int);
int lower(int);

int main(void)
{
	printf("Upper case 'A' lowered: %c\n", lower('A'));
	printf("Upper case 'B' lowered: %c\n", lower('B'));
	printf("Upper case 'D' lowered: %c\n", lower('D'));
	printf("Upper case 'L' lowered: %c\n", lower('L'));
	printf("Upper case 'Q' lowered: %c\n", lower('Q'));
	printf("Upper case 'Z' lowered: %c\n", lower('Z'));
	
	return 0;
}

int lower(int inputCharacter)
{	
	return (inputCharacter >= 'A' && inputCharacter <= 'Z') 
				? inputCharacter + 'a' - 'A'
				: inputCharacter;
}


int lowerOriginal(int inputCharacter)
{
	int characterToReturn;
	
	if(inputCharacter >= 'A' && inputCharacter <= 'Z')
		characterToReturn = inputCharacter + 'a' - 'A';
	else
		characterToReturn = inputCharacter;
	
	return characterToReturn;
}