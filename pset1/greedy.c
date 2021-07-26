#include <stdio.h>
#include <stdbool.h>

int main()
{
	float change;

	while(true) 
	{
		printf("Enter the amount of change in dollars\n");
		
		scanf("%f", &change);
		
		//Checking inputed data
		if (change >= 0)
			break;
		else
			printf("Incorrect input data.Try again\n ");
	}

	int cents = change * 100;


	//Checking count of 25c coins
	int Coin25c = 0;

	while(cents >= 25) 
	{
	    cents = cents - 25;
	    Coin25c++;
	}

	//Checking count of 10c coins	
	int Coin10c = 0;

	while(cents >= 10) 
	{
	    cents = cents - 10;
	    Coin10c++;
	}

	//Checking count of 5c coins
	int Coin5c = 0;

	while(cents >= 5) 
	{
	    cents = cents - 5;
	    Coin5c++;
	}

	//Checking count of 1c coins
	int Coin1c = 0;

	while(cents >= 1) 
	{
	    cents = cents - 1;
	    Coin1c++;
	}

	//Results
	printf("For change needs: \n");
	printf("%i coins of 25c \n",Coin25c);
	printf("%i coins of 10c \n",Coin10c);
	printf("%i coins of 5c \n",Coin5c);
	printf("%i coins of 1c \n",Coin1c);
}