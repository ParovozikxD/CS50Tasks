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

	for (int i = 0, key = 0; i < AplhabetSize; i++, key++)
	{
		for (int j = 0, length = strlen(CipherText); j < length; j++)
		{
			//For uppcase
			if (isupper(CipherText[j]))
			{
				PlainText[i][j] = ((int)CipherText[j] + 65 - key) % AplhabetSize + 65;
			}
			//For downcase
			if (islower(CipherText[j]))
			{
				PlainText[i][j] = ((int)CipherText[j] + 97 - key) % AplhabetSize + 97;
			}
		}
		puts(PlainText[i]);
	}	

}