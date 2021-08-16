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

    unsigned char jpeg[SIZEOFJPEGBLOCK];
    int count = 1;
    char jpegname[12];
    FILE *jpegfile = NULL;


    while(fread(jpeg, SIZEOFJPEGBLOCK, 1, card))
    {
        if (jpeg[0] == 0xff && jpeg[1] == 0xd8 && jpeg[2] == 0xff)
        {
            if (jpegfile)
            {
                fclose(jpegfile);
            }

            sprintf(jpegname,"Jpeg%d.jpg",count++);

            jpegfile = fopen(jpegname, "w");
           
        }

        if (jpegfile)
        {
           fwrite(jpeg, SIZEOFJPEGBLOCK, 1, jpegfile);
        } 

   }
    fclose(jpegfile);
    fclose(card);

    return 0;
}