/*Task 4.1 (modify version)
	 The user enters name form console as a parametrs
	 Program should output the first letter in uppercase
*/

#include <stdio.h>
#include <ctype.h> //for toupper

int main(int argc,char* argv[])
{
	printf("Result:\n");

	for (int i = 1; i < argc; i++)
	{
		printf("%c", toupper(argv[i][0]));
	}
	
	printf("\n");	
}