/* Exercise 5-3: Write a pointer version of the function strcat that we showed
 * in Chapter 2: strcat(s, t) copies the string t to the end of s.
 * 
 * The original strcat(s, t) function relied on s being large enough to accomodate
 * the size of t. We change this function around a little bit and incorporate the
 * rudimentary storage allocator function alloc that was introduced in Chapter 5. 
 * We are unable to properly allocate memory using the malloc and free functions,
 * since these have not yet been introduced at this point in the text.
 */

#include <stdio.h>
#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE];	/* storage for alloc */
static char *allocp = allocbuf;		/* next free position */

char *alloc(int n) /* return pointer to n characters */
{
	if(allocbuf + ALLOCSIZE - allocp >= n) /* it fits */
	{
		allocp += n;
		return allocp - n; /* old p */
	}
	else /* not enough room */
	{
		return 0;
	}
}

void afree(char *p)		/* free storage pointed to by p */
{
	if(p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}

int stringLength(char *s)
{
	char *p = s;
	
	while(*p != '\0')
		p++;
	
	return p - s;
}

char *stringCat(char *firstString, char *secondString)
{
	int concatenatedStringLength = stringLength(firstString) + stringLength(secondString);
	char *finalString = alloc(concatenatedStringLength + 1); /* Make room for '\0' */
	
	while(*firstString != '\0')
		*finalString++ = *firstString++;	

	while(*secondString != '\0')
		*finalString++ = *secondString++;	
	
	*finalString = '\0';
	finalString -= concatenatedStringLength;
	
	return finalString;
}

int main(void)
{
	char myString1[] = "my string 1";
	char myString2[] = "my string 2";
	
	char *myConcatenatedString = stringCat(myString1, myString2);
	printf("%s\n", myConcatenatedString);
	return 0;
}