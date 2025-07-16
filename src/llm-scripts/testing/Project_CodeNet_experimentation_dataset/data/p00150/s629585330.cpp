#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n, a, b;
    bool p[10000] = {false};

    for( int i = 2; i < 10000; i++ )
    {
        bool judge = true;
        for( int j = 2; j <= sqrt(i); j++ )
            if( i % j == 0 )
                judge = false;
        if( judge == true )
            p[i] = true;
    }

    while( cin >> n )
    {
        if( n == 0 )
            break;

        for( int i = 2; i <= n - 2; i++ )
        {
            if( p[i] == true && p[i+2] == true )
            {
                a = i;
                b = i + 2;
            }
        }
        cout << a << " " << b << endl;
    }
    return 0;
}
