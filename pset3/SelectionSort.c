/*Task 7.1
	Realize the Selection Sorting
*/

#include <stdio.h>


void SelectionSort(int *Array, int ArrSize);

int main()
{
	int Array[] = {4,8,6,2,1,7,5,3};

	int ArrSize = sizeof(Array)/sizeof(int);
	
	SelectionSort(Array, ArrSize);

	for (int i = 0; i < ArrSize; i++)
	{
		printf("%i ", Array[i]);
	}
	printf("\n");
}

void SelectionSort(int *Array, int ArrSize)
{
	int min;
	int temp;

	for (int i = 0; i < ArrSize; i++)
	{
		min = i;
		for (int j = i; j < ArrSize - 1; j++)
		{
			if (Array[min] > Array[j+1])
			{
				min = j+1;			
			}
		}
	temp = Array[i];
	Array[i] = Array[min];
	Array[min] = temp;
	}
}