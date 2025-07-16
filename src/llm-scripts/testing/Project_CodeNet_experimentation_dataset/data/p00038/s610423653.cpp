#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int cs[5];
    while( scanf( "%d,%d,%d,%d,%d", &cs[0], &cs[1], &cs[2], &cs[3], &cs[4] ) != -1 ) {
        sort( cs, cs + 5 );

        vector<int> uc( 5 );
        unique_copy( cs, cs+5, uc.begin() );

        int p[5] = {};
        for( auto const& c : uc ) {
            ++p[count( cs, cs + 5, c )];
        }
        
        bool const is_straight = [&]{
            bool const b = [&](){
                for( int i=1; i<5; ++i ) {
                    if ( cs[i-1] + 1 != cs[i] )
                        return false;
                }
                return true;
            }();

            return b
                   || ( cs[0] == 10 && cs[1] == 11 && cs[2] == 12 && cs[3] == 13 && cs[4] == 1 )
                   || ( cs[0] == 1 && cs[1] == 10 && cs[2] == 11 && cs[3] == 12 && cs[4] == 13 );
        }();

        
        cout <<
            ( ( p[4] == 1 )
              ? "four card"
              : ( p[3] == 1 && p[2] == 1 )
              ? "full house"
              : ( is_straight )
              ? "straight"
              : ( p[3] == 1 )
              ? "three card"
              : ( p[2] == 2 )
              ? "two pair"
              : ( p[2] == 1 )
              ? "one pair"
              : "null" )
            << endl;
    }
}