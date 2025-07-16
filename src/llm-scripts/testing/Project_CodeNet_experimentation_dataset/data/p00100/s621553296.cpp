#include<iostream>
using namespace std;

int main()
{
    int n;
    long long int e[4000], p[4000], q[4000], sum[4000];
    bool ej[4000];

    while( cin >> n )
    {
        if( n == 0 )
            break;

        for( int i = 0; i < 4000; i++ )
        {
            sum[i] = 0;
            ej[i] = false;
        }

        for( int i = 0; i < n; i++ )
        {
            cin >> e[i] >> p[i] >> q[i];
            sum[e[i]] += p[i] * q[i];
        }
        
        bool judge = false;
        for( int i = 0; i < n; i++ )
        {
            if( sum[e[i]] >= 1000000 && ej[e[i]] == false )
            {
                cout << e[i] << endl;
                judge = true;
                ej[e[i]] = true;
            }
        }
        if( judge == false )
            cout << "NA" << endl;
    }
    return 0;
}
