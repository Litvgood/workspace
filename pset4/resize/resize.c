/**
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>
 
#include "bmp.h"
 
int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }
 
    double coefficient = atof(argv[1]);
    char* infile = argv[2];
    char* outfile = argv[3];
 
    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }
 
    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
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
        return 4;
    }
 
    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    RGBTRIPLE image[bi.biWidth][abs(bi.biHeight)];
    
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            RGBTRIPLE triple;
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
            image[j][i] = triple;
        }
        
        fseek(inptr, padding, SEEK_CUR);
    }
    
    // modify headers of file
    bi.biWidth *= coefficient;
    bi.biHeight *= coefficient;
    
    // recalculate the padding
    padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // calculate the number of bytes in the non-header part of the image
    bi.biSizeImage = abs(bi.biHeight) * (bi.biWidth * sizeof(RGBTRIPLE) + padding);
    
    // calculate the total number of bytes in the image
    bf.bfSize = bi.biSizeImage + 54;
    
    //write outfile's BITMAPFILEHEADER and BITMAPINFOHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);
    
    // writing to the coefficient image's out file
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        for (int j = 0; j < bi.biWidth; j++)
        {
            RGBTRIPLE triple;
            triple = image[(int) (j / coefficient)][(int) (i / coefficient)];
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr); 
        }
        
        // write the buffer
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }
    }
    
 
    // close infile
    fclose(inptr);
 
    // close outfile
    fclose(outptr);
 
    // that's all folks
    return 0;
}