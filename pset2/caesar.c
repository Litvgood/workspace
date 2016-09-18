#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    int k = atoi(argv[1]);
    if( k <= 0 ) {
    return 1;
  }
	char s[100];
    fgets( s, 100, stdin);

	int n = 0, r = 0, i;

	for(i = 0; s[i] != '\0'; i++)
	{
		if(s[i] >='a' && s[i] <='z')
		{
		n = 'z' - s[i];
			if( k > n )
			{
				r = k - n - 1;
				s[i] = 'a';
				s[i] += r;
			}
			else
				s[i] += k;
		}
		if(s[i] >='A' && s[i] <='Z')
		{
		n = 'Z' - s[i];
			if( k > n )
			{
				r = k - n - 1;
				s[i] = 'a';
				s[i] += r;
			}
			else
				s[i] += k;
		}
	}

	int j;
	for(j = 0; s[j] !='\0'; j++)
	{
		printf("%c", s[j]);
	}

	printf("");

	return 0;
	}
