#include <iostream>
using namespace std;

int convert( char c )
{
    switch ( c )
    {
    case 'I':   return 1;
    case 'V':   return 5;
    case 'X':   return 10;
    case 'L':   return 50;
    case 'C':   return 100;
    case 'D':   return 500;
    case 'M':   return 1000;
    }
}

int main( void )
{
    string input;
    int answer, prev;
    while ( cin >> input )
    {
        answer = 0;
        prev = 0;

        for ( string ::reverse_iterator it = input.rbegin(); it != input.rend(); it++ )
        {
            int next = convert( *it );
            if ( prev <= next )
            {
                answer += next;
            }
            else
            {
                answer -= next;
            }
            prev = next;
        }

        cout << answer << endl;
    }
    return 0;
}