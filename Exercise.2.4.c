/* Exercise 2.4: Write an alternate version of squeeze(s1, s2) that deletes
 * each character in s1 that matches any character in the string s2 
 *
 * Author: Adam Bak */

#include <stdio.h>

void squeezeAlternate(char[], char[]);
int containedInArray(char, char[]);

int main(void)
{
	char myString[] = "Hello, World!";
	char squeezeString[] = "HWod";
	
	printf("Squeeze string: %s\n", squeezeString);
	printf("Before squeeze: %s\n", myString);	
	squeezeAlternate(myString, squeezeString);
	printf("After squeeze: %s\n", myString);	
	
	return 0;
}

void squeezeAlternate(char inputString[], char charactersToDelete[])
{
	int i, j;
	
	for(i = j = 0; inputString[i] != '\0'; i++)
	{		
		if(!containedInArray(inputString[i], charactersToDelete))
		{
			inputString[j] = inputString[i];
			j++;
		}
	}
	
	inputString[j] = '\0';
}

/* This function tests whether the provided character is 
 * present in the array  */
int containedInArray(char characterToTest, char characterArray[])
{
	for(int k = 0; characterArray[k] != '\0'; k++)
	{
		if(characterToTest == characterArray[k])
		{
			return 1;
		}					
	}
	
	return 0;
}