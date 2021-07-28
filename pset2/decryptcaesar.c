/*Task 5.1
	Realize the Decryption of Caesar cipher
	Input data -  ciphertext
	Output data - All possible plaintext 

*/

#include <stdio.h>
#include <string.h> //for strlen
#include <ctype.h> //for check on upper/lower case

#define Arrsize 100 //for array
#define AplhabetSize 26

int main()
{	
	char CipherText[Arrsize];
	char PlainText[AplhabetSize][Arrsize];
	

	printf("Input your CipherText: ");
	fgets(CipherText, Arrsize, stdin);

	printf("All possible dectyption options:\n");

	for (int i = 0, key = 1; i < AplhabetSize; i++, key++)
	{
		for (int j = 0, length = strlen(CipherText); j < length; j++)
		{
			//For uppcase
			if (isupper(CipherText[j]))
			{
				if ((int)CipherText[j] - key < 65)
				{
					PlainText[i][j] = (int)CipherText[j] - key + AplhabetSize;
				}
					
				else
				{

					PlainText[i][j] = (int)CipherText[j] - key;
				}
			}

			//For downcase
			else if (islower(CipherText[j]))
			{
				if ((int)CipherText[j] - key < 97)
				{
					PlainText[i][j] = (int)CipherText[j] - key + AplhabetSize;
				}
					
				else
				{
					PlainText[i][j] = (int)CipherText[j] - key;
				}
			}

			//For other symbols
			else 
			{
				PlainText[i][j] = CipherText[j];
			}

		}
		puts(PlainText[i]);
	}	
}