#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

string s;

string Replace( string s1, string s2, string s3 )
{
    string :: size_type  pos( s1.find( s2 ) );
    while( pos != string :: npos )
    {
        s1.replace( pos, s2.size(), s3 );
        pos = s1.find( s2, pos + s3.size() );
    }
    return s1;
}

signed main()
{
    int n = 0;
    scanf( "%d\n", &n );
    while( 0 < n )
    {
        getline( cin, s );
        s = Replace( s, "Hoshino", "Hoshina" );
        cout << s << endl;
        n--;
    }
    return 0;
}
