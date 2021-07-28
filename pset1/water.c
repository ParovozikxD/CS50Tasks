/*Task 1
	 The user enters time in the shower
	 Program should output number of spent bottles 
	 (1 min = 12 bottles)
*/

#include <stdio.h>
#include <stdbool.h>

int main()
{
	int minutes;
	
	//While corrected data wasn't input ==> continuous loop
	while (true)
	{
	
		printf("How many minutes (whole ones) did you take a shower?\n");
		
		scanf("%i", &minutes);
		
		//Checking on correct input data
		if (minutes < 0) 		
			printf("Incorrect data. Try again\n");

		else
			break;
	}
		
	//Output bottles count			
	printf("You have used up: %i bottles\n",minutes*12);	
}