#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int main(int argc, string argv[])
{
	if (argc!=2)
	{
		printf("Erorr\n");
		return 1;
	}

	int number;

	if((atoi(argv[1])) <= 26)
	{
		number = atoi(argv[1]);
	}
	else
	{
		number = atoi(argv[1])%26;
	}
	
	string text = GetString();

	for( int i = 0, symbols = strlen(text); i < symbols; i++ )
	{
		if ( isalpha(text[i]) )
		{
			if ( isupper(text[i]) )
			{
				text[i] = ( ((text[i] - 65 ) + number)%26 ) + 65;
			}
			else
			{
				text[i] = ( ((text[i] - 97 ) + number)%26 ) + 97;
			}
		}

	}

	printf("%s\n", text);
	return 0;
}
