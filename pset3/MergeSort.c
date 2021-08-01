/*Task 7.4
	Realize the Merge sorting
*/

#include <stdio.h>


void MergeSort(int *Array, int Start, int End);
void Merge(int *Array, int Start, int End);

int main()
{
	int Array[] = {4,8,6,2,1,7,5,3};

	int End = (sizeof(Array)/sizeof(int)) - 1;
	
	MergeSort(Array, 0, End);

	for (int i = 0; i < End+1; i++)
	{
		printf("%i ", Array[i]);
	}
	printf("\n");
}

void Merge(int *Array, int Start, int End)
{
	int temp[End+1];

	int left = Start, right = ((Start+End)/2)+1;

	for (int i = Start; i < End; i++)
	{	
	
		if (left < right && (right > End ||Array[left] < Array[right]))
		{
			temp[i] = Array[left];

			left++;
 		}
		else
		{
			temp[i] = Array[right];

			right++;
		}
	}
	for (int i = Start; i <= End; i++)
	{
		Array[i] = temp[i];
	}

}

void MergeSort(int *Array, int Start, int End)
{
	if (End > Start)
	{
		int Middle = (Start + End) /2;
		MergeSort(Array, Start, Middle);
		MergeSort(Array, Middle+1, End);
		Merge(Array, Start, End);
	}
}