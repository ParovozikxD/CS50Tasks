/*Task 5
	Realize the Caesar cipher
	Input data - key, plaintext
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
	if (argc !=2 || atoi(argv[1]) < 0)
	{
		printf("Incorrect data\n");
		return 1;
	}

	int key = atoi(argv[1]);
	char PlainText[Arrsize];
	char CipherText[Arrsize];

	printf("Input your plaintext: ");
	fgets(PlainText, Arrsize, stdin);
	for (int i = 0,length = strlen(PlainText); i < length; i++)
	{
		//For uppcase
		if (isupper(PlainText[i]))
		{
			CipherText[i] = ((int)PlainText[i] - 65 + key) % AplhabetSize + 65;
		}
		
		//For downcase
		else if (islower(PlainText[i]))
		{
			CipherText[i] = ((int)PlainText[i] - 97 + key) % AplhabetSize + 97;
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