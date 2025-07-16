#include <bits/stdc++.h>
using namespace std;
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
int main()
{
    string A, B, C;
    cin >> A >> B >> C;
    
    string next;
    next.push_back( A[ 0 ] );
    
    int a{}, b{}, c{};
    while( true )
    {
        if( next == "a" )
        {
            if( A.empty() )
            {
                cout << "A" << endl;
                break;
            }
            next = *A.begin();
            A.erase( A.begin() );
            a++;
        }
        if( next == "b" )
        {
            if( B.empty() )
            {
                cout << "B" << endl;
                break;
            }
            next = *B.begin();
            B.erase( B.begin() );
            b++;
        }
        if( next == "c" )
        {
            if( C.empty() )
            {
                cout << "C" << endl;
                break;
            }
            next = *C.begin();
            C.erase( C.begin() );
            c++;
        }
    }
    return 0;
}
