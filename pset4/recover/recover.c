#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char* argv[])
{
	FILE* input = fopen(argv[1], "r");
    FILE* output = NULL;
    char outfile[] = "000.jpg";
    unsigned char buffer[512];
    int i = -1;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }
    
    if (input == NULL)
    {
        fprintf(stderr, "Could not open card.raw\n");
        return 2;
    }
   
    while (fread(&buffer, sizeof(buffer), 1, input))
    {
        if (((buffer[0]==0xff) && (buffer[1]==0xd8) && (buffer[2]==0xff)) && ((buffer[3]==0xe0) || (buffer[3]==0xe1)))
        {
            if (output == NULL)
            {
                output = fopen(outfile, "w");
                fwrite(&buffer, sizeof(buffer), 1, output);
            }
            else
            {
                fclose(output);
                i++;
                
                //modify name of file
                if (i < 10)
                {
                    outfile[2] = i + '0';
                }
                else 
                {
                    if (i >= 10 && i < 100)
                    {
                        outfile[1] = (round(i/10) + '0');
                        outfile[2] = (i - (10*(round(i/10)))) + '0';
                    }
                }
                
                output = fopen(outfile, "w");
                fwrite(&buffer, sizeof(buffer), 1, output);
            }
        }
        else 
        {
            if (output == NULL)
            {
                output = fopen(outfile, "w");
                fwrite(&buffer, sizeof(buffer), 1, output);
            } else
            {
                fwrite(&buffer, sizeof(buffer), 1, output);
            }
        }
    }
   
   fclose(input);
   fclose(output);
   
   return 0;
}