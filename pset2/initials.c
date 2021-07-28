/*Task 4
	 The user enters name 
	 Program should output the first letter in uppercase
*/

#include <stdio.h>
#include <ctype.h> //for toupper

int main()
{
	int count;
	int maxsize = 40;

	printf("How many names do you want to write?\n");
	scanf("%i", &count);

	char NamesArr[count][maxsize];

	for (int i = 0; i < count; i++)
	{
		printf("Write %i name\n", i+1);
		scanf("%s", NamesArr[i]);
	}
	
	printf("Result:\n");

	for (int i = 0; i < count; i++)
	{
		printf("%c", toupper(NamesArr[i][0]));
	}
	printf("\n");
}