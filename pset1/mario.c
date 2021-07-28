/*Task 2
	 The user enters height of piramids
	 Program should output piramids like in mario
	 
	 **
	***
   ****
*/

#include <stdio.h>
#include <stdbool.h>

int main()
{
	int height;

	//Are the input parametrs correct?
	while(true) 
	{
	  printf("Choose piramids heigth (1 - 23 range): ");
	  scanf("%i",&height);

	  if (height >= 1 && height <= 23)
	  {
	  	break;
	  }

	 printf("Out of range\n"); 
	}

	printf("\n");

	//First piramid
	for (int i = 0; i < height; i++)
	{
		//Writes " "
        for (int j = height-1; j > i ; j--)
		{
			printf(" ");
		}

		//Writes #
		for (int j = 0; j < i+2 ; j++)
		{
			printf("#");
		}

		printf("\n");
	}

	printf("\n");

	//Second piramid
	for (int i = 0; i < height; i++)
	{
	
		//Writes #
		for (int j = 0; j < i+2 ; j++)
		{
			printf("#");
		}

		printf("\n");
	}

	printf("\n");

	//Third piramid
	for (int i = 0; i < height; i++)
	{
	
		//Writes #
		for (int j = height+1; j > i ; j--)
		{
			printf("#");
		}

		printf("\n");
	}

	printf("\n");	

	//Fourth piramid
	for (int i = 0; i < height; i++)
	{

		//Writes " "
        for (int j = 0; j < i ; j++)
		{
			printf(" ");
		}

		//Writes #
		
		for (int j = height+1; j > i ; j--)
		{
			printf("#");
		}
		printf("\n");
	}

}