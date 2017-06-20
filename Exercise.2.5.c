/* Exercise 2.5: Write the function any(s1, s2), which returns the first location
 * in the string s1 where any character from the string s2 occurs, or -1 if s1 
 * contains no characters from s2.
 *
 * Author: Adam Bak
 */

#include <stdio.h>

int any(char[], char[]);
int containedInArray(char, char[]);

int main(void)
{	
	char s1[] = "Hello, World!";
	char s2[] = "abcde";
	char s3[] = "fghij";
	char s4[] = ", !";
	
	printf("Index of character found: %i\n", any(s1, s2));
	printf("Index of character found: %i\n", any(s1, s3));
	printf("Index of character found: %i\n", any(s1, s4));
	
	return 0;
}

/* This function is the required function as per the exercise. We use
 * different parameter names instead of s1 and s2 to make the function
 * easier to read */
int any(char inputString[], char charactersToMatch[])
{
	int i;

	for(i = 0; inputString[i] != '\0'; i++)
	{		
		if(containedInArray(inputString[i], charactersToMatch))
			return i;
	}
	
	return -1;
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