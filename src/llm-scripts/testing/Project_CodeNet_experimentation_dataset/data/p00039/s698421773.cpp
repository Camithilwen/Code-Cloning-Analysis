#include<stdio.h>
#include<string.h>
#include<math.h>

int value( char c )
{
	switch( c ){
		case 'I':
			return 1;
			break;
		case 'V':
			return 5;
			break;
		case 'X':
			return 10;
			break;
		case 'L':
			return 50;
			break;
		case 'C':
			return 100;
			break;
		case 'D':
			return 500;
			break;
		case 'M':
			return 1000;
			break;
	}
}

int main()
{
	char str[101];
	while( scanf( "%s", str ) != EOF ){
	
		int ans = 0;
		
		for( int i = 1; i <= strlen( str ); i++ ){
			if( value( str[i-1] ) >= value( str[i] ) ){
				ans += value( str[i-1] );
			}
			else{
				ans += value( str[i] ) - value( str[i-1] );
				i++;
			}
		}
		
		printf( "%d\n", ans );
	}

 	return 0;
}