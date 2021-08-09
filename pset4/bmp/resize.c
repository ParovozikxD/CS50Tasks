/*
 * resize.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Resize bmp 
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize resizeArg infile outfile\n");
        return 1;
    }

    // Entering parametrs
    int ResizeArg = atoi(argv[1]);
    char* infile = argv[2];
    char* outfile = argv[3];
    if (ResizeArg > 100 || ResizeArg < 1)
    {
        printf("Incorrect argument for resizing \n");
        return 2;
    }


    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 3;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 5;
    }

    //Initial new sizes

    LONG OldHeight = bi.biHeight;
    bi.biHeight *= ResizeArg;

    LONG OldWidth = bi.biWidth;
    bi.biWidth *= ResizeArg;

    LONG OldImgSize = bi.biSizeImage;
    bi.biSizeImage *= bi.biHeight * bi.biWidth;

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int padding_before = (4 - (OldWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    int pos = OldWidth * sizeof(RGBTRIPLE) + padding_before;

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(OldHeight); i < biHeight; i++)
    {   
        for (int count_row = 0; count_row < ResizeArg; count_row++)
        {
             // iterate over pixels in scanline
            for (int j = 0; j < OldWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                
                for (int count_pix = 0; count_pix < ResizeArg; count_pix++)
                {
                    // write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }          
            }

            // skip over padding, if any
            fseek(inptr, padding, SEEK_CUR);

            // then add it back (to demonstrate how)
            for (int k = 0; k < padding; k++)
            {
                fputc(0x00, outptr);
            }

            //for duplicate rows
            fseek(inptr, 54 + pos*i, SEEK_SET);
    
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
