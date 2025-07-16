#include <cstdio>

using namespace std;

double l[10],v1, v2;

int main()
{
    loop:
    while ( scanf("%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf\n", &l[0], &l[1], &l[2], &l[3], &l[4], &l[5], &l[6], &l[7], &l[8], &l[9], &v1, &v2 ) != EOF )
    {
        v2 += v1;
        for( int i = 0; i < 10; i++ )
        {
            l[i] += ( ( i == 0 ) ? 0 : l[i - 1] );
        }
        double t = l[9] / v2;
        double dis = v1 * t;
        for( int i = 0; i < 10; i++ )
        {
            if( dis == l[i] )
            {
                printf( "%d\n", i + 1 );
                goto loop;
            }
            else if( dis < l[i] )
            {
                printf( "%d\n", i + 1 );
                goto loop;
            }
        }
        /* for( int i = 0; i < 10; i++ )
        {
            if( l[i] <= dis && dis <= l[i + 1] )
            {
                printf( "%d\n", i + 2 );
                return 0;
            }
        } */
    }
    return 0;
}
