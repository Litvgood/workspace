#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

char coding (char token, int key);

int main(int argc, string argv[])

{
	if (argc!=2)
	{
		printf("Erorr\n");
		return 1;
	}
	else if (argv[1])
	{
	    int l = strlen(argv[1]);
		for(int i = 0; i < l; i++ )
		{
			if (!isalpha(argv[1][i]))
			{
				printf("Erorr");
				return 1;				
			}
		}
	}

	string key = argv[1];
	int length = strlen(key);
	int code[length];


	for (int i = 0; i < length; i++)
	{
		code[i] = toupper(key[i]) - 65;
	}

	string inputText = GetString();
	int inputLength = strlen(inputText);
	int keyCount = 0;

	for (int i = 0; i < inputLength; i++)
	{
		if ( isalpha(inputText[i]))
		{
			printf("%c", coding(inputText[i], code[keyCount] ));
			if ( keyCount < length - 1)
			{
				keyCount ++;
			}
			else
			{
				keyCount = 0;
			}
		}
		else
		{
			printf("%c", inputText[i] );
		}
	}
	
    printf( "\n" );
	return 0;
}

char coding (char token, int key)
{
	if ( isupper(token) )
	{
		return ( ((token - 65 ) + key)%26 ) + 65;
	}
	else
	{
		return ( ((token - 97 ) + key)%26 ) + 97;
	}
}