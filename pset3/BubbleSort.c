/*Task 7.2
	Realize the Bubble Sorting
*/

#include <stdio.h>


void BubbleSort(int *Array, int ArrSize);
void SwapElements(int *FirArray, int *SecArray);

int main()
{
	int Array[] = {4,8,6,2,1,7,5,3};

	int ArrSize = sizeof(Array)/sizeof(int);
	
	BubbleSort(Array, ArrSize);

	for (int i = 0; i < ArrSize; i++)
	{
		printf("%i ", Array[i]);
	}
	printf("\n");
}

void SwapElements(int *FirArray, int *SecArray)
{
	int temp;
	temp = *FirArray;
	*FirArray = *SecArray;
	*SecArray = temp;
}

void BubbleSort(int *Array, int ArrSize)
{
	for (int i = 0; i < ArrSize; i++)
	{
		//Last i elements in their places
		for (int j = 0; j < ArrSize - i- 1; j++)
		{
			if (Array[j] > Array[j+1])
			{
				SwapElements(&Array[j],&Array[j+1]);
			}
		}
	}
}

