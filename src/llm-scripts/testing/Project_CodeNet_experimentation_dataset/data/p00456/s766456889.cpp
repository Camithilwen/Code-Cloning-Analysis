#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int w = 0 , k = 0 ;
    int score[2][10] = {0} ;
    for ( int i = 0 ; i < 2 ; i++ )
    {
        for ( int j = 0 ; j < 10 ; j++ )
        {
            cin >> score[i][j] ;
        }
        sort( score[i],score[i]+10 ) ;
        reverse( score[i],score[i]+10 ) ;
    }
    w = score[0][0] + score[0][1] + score[0][2] ;
    k = score[1][0] + score[1][1] + score[1][2] ;
    printf("%d %d\n",w ,k ) ;

    return 0 ;
}