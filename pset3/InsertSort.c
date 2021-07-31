/*Task 7.3
	Realize the Sort by inserts
*/

#include <stdio.h>


void InsertSort(int *Array, int ArrSize);

int main()
{
	int Array[] = {4,8,6,2,1,7,5,3};

	int ArrSize = sizeof(Array)/sizeof(int);
	
	InsertSort(Array, ArrSize);

	for (int i = 0; i < ArrSize; i++)
	{
		printf("%i ", Array[i]);
	}
	printf("\n");
}

void InsertSort(int *Array, int ArrSize)
{

	for (int i = 1; i < ArrSize; i++)
	{
		int fixed = Array[i];
		int j = i;

		while(fixed < Array[j-1] && j>0) 
		{
		    Array[j] = Array[j-1];
		    
		    j--;
		    Array[j] = fixed;
		   
		}	
	}
}