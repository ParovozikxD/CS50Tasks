/*Task 6.1
	Realize the Decryption of Vigenere cipher
	Input data - key (word), ciphertext
	Output data - plaintext 

*/

#include <stdio.h>
#include <stdlib.h> //for atoi (convert str to int)
#include <string.h> //for strlen
#include <ctype.h> //for check on upper/lower case

#define Arrsize 100 //for array
#define AplhabetSize 26

int main(int argc, char* argv[])
{
	//Checking input data

	//Cheking for the presence of parametrs
	if (argc !=2)
	{	
		printf("Incorrect data\n");
		return 1;
	}

	for (int i = 0, length = strlen(argv[1]); i < length; i++)
	{
		
		//Cheking the input key 
		if (isalpha(argv[1][i]) == 0)
		{
			printf("Incorrect data\n");
			return 1;
		}
	}

	char PlainText[Arrsize];
	char CipherText[Arrsize];
	int key[Arrsize];

	printf("Input your ciphertext: ");
	fgets(CipherText, Arrsize, stdin);

	//Generating a key

	for (int i = 0, j = 0, count = 0, length = strlen(CipherText); i < length; i++)
	{
		//Retry if key < Plaintext
		
		if (isalpha(CipherText[i]))
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


	for (int i = 0,j = 0, length = strlen(CipherText); i < length; i++)
	{
		//For uppcase
		if (isupper(CipherText[i]))
		{
			if ((int)CipherText[i] - (key[j]+65) < 0)
			{
				PlainText[i] = ((int)CipherText[i] + AplhabetSize - 65 - key[j]) % AplhabetSize + 65;
			}
			else
			{
				PlainText[i] = ((int)CipherText[i] - 65 - key[j]) % AplhabetSize + 65;
			}
				j++;
		}
		
		//For downcase
		else if (islower(CipherText[i]))
		{
			if ((int)CipherText[i] - (key[j]+97) < 0)
			{
				PlainText[i] = ((int)CipherText[i] + AplhabetSize - 97 - key[j]) % AplhabetSize + 97;
			}
			else
			{
				PlainText[i] = ((int)CipherText[i] - 97 - key[j]) % AplhabetSize + 97;
			}
				j++;
		}

		//For other symbols
		else 
		{
			PlainText[i] = CipherText[i];
		}
	}

	printf("Encryption result:\n");
	puts(PlainText);

}