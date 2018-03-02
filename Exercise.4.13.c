/* Exercise 4-13: Write a recursive version of the function
 * reverse(s), which reverses the string s in place  
 */

#include <stdio.h>

void reverseString(char[]);

int main(void)
{
	char myString[] = "Hello World";
	
	printf("%s\n", myString);
	reverseString(myString);	
	printf("%s\n", myString);

	return 0;
}

void reverseString(char stringToReverse[])
{
	static int a, b = 0;

	if(!stringToReverse[b] == '\0')
	{
		b++;
		reverseString(stringToReverse);			
	}
		
	if(a < --b)
	{
		char temp = stringToReverse[b];
		stringToReverse[b] = stringToReverse[a];	
		stringToReverse[a++] = temp;		
	}	
}
