/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>

#define SIZEOFJPEGBLOCK 512

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Usage ./recover InptFile\n");
        return 1;
    }

    char *infile = argv[1];    

    FILE *card = fopen(infile,"r");

    if (card == NULL)
    {
        printf("Something wrong with File!\n");
        return 2;
    }

    char JpegName[8];
    int JpegNameCount = 1;
    unsigned char data[SIZEOFJPEGBLOCK];
    
    FILE *jpeg = NULL;


    while(fread(&data,SIZEOFJPEGBLOCK,1,card) == 1) 
    {

        if (data[0] == 0xff && data[1] == 0xd8 && data[2] == 0xff)
        {
            sprintf(JpegName,"Jpeg_%i",JpegNameCount++);
          
            jpeg = fopen(JpegName, "w");

            fwrite(&data,SIZEOFJPEGBLOCK,1, jpeg);
            fclose(jpeg);
        }
               
    }

    fclose(card);
    
    return 0;

}
