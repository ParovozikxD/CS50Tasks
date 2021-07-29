/*Task 6
	Realize the vigenere
	Input data - key (word), plaintext
	Output data - ciphertext 

*/

#include <stdio.h>
#include <stdlib.h> //for atoi (convert str to int)
#include <string.h> //for strlen
#include <ctype.h> //for check on upper/lower case

#define Arrsize 100 //for array
#define AplhabetSize 26

int main(int argc, char* argv[])
{
	//checking input data
	for (int i = 0, length = strlen(argv[1]); i < length; i++)
	{
		//Cheking for the presence of parametrs
		if (argc !=2)
		{	
			printf("Incorrect data\n");
			return 1;
		}

		//Cheking the input key 
		else if (isalpha(argv[1][i]) == 0)
		{
			printf("Incorrect data\n");
			return 1;
		}
	}

	char PlainText[Arrsize];
	char CipherText[Arrsize];
	int key[Arrsize];

	printf("Input your plaintext: ");
	fgets(PlainText, Arrsize, stdin);

	//Genering key

	for (int i = 0, j = 0, count = 0, length = strlen(PlainText); i < length; i++)
	{
		//Retry if key < Plaintext
		
		if (isalpha(PlainText[i]))
		{
			
			//Retry if key < Plaintext
			if (strlen(argv[1]) == j)
			{
				j = 0;
				//Converting to uppercase and storing int a key
				key[count] = ((int)toupper(argv[1][j]))-65;
				j++;
				count++;
			}

			else
			{	
				//Converting to uppercase and storing int a key
				key[count] = ((int)toupper(argv[1][j]))-65;
				j++;
				count++;
			}
		}	
	}


	for (int i = 0,j = 0, length = strlen(PlainText); i < length; i++)
	{
		//For uppcase
		if (isupper(PlainText[i]))
		{
			CipherText[i] = ((int)PlainText[i] - 65 + key[j]) % AplhabetSize + 65;
			j++;
		}
		
		//For downcase
		else if (islower(PlainText[i]))
		{
			CipherText[i] = ((int)PlainText[i] - 97 + key[j]) % AplhabetSize + 97;
			j++;
		}

		//For other symbols
		else 
		{
			CipherText[i] = PlainText[i];
		}
	}

	printf("Encryption result:\n");
	puts(CipherText);

}