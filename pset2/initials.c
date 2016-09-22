#include <stdio.h>

int main()
{
	char stroka[50];
	fgets( stroka, 50, stdin);
	int p;
	for ( p = 0; stroka[p] == ' '; p++ ){
	
	}
	if ( stroka[p] > 91 ) {
        stroka[p] -= 32;
        printf("%c", stroka[p]);
	}
	else {
		printf("%c", stroka[p]);
	}
    for (int i = p; stroka[i] != '\0'; i++ ) {
    	if( stroka[i] == 32 ){
    		i++;
        	if ( stroka[i] > 91 ) {
       			stroka[i] -= 32;
       			printf("%c", stroka[i]);
			}
			else {
       			printf("%c", stroka[i]);
			}
		}
    }
    printf( "\n" );
	return 0;
}
