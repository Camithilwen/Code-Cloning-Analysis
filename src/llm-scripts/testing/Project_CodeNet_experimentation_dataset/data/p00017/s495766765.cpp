#include<iostream>
#include<iomanip>
#include<memory>
#include<array>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<algorithm>
#include<cmath>

using namespace std;

int chipher( string& s )
{
  for ( auto& c : s )
    {
      if ( c >= 'a' && c <= 'y' )
        ++c;
      else if ( c == 'z' )
        c = 'a';
    }
  return 0;
}

int main()
{
  
  string x;

  while( getline(cin, x) )
    {
      for ( int i = 0; i < 26; ++i )
        {
          if ( x.find( "the" ) != string::npos )
            cout << x << endl;
          else if ( x.find( "this" ) != string::npos )
            cout << x << endl;
          else if ( x.find( "that" ) != string::npos )
            cout << x << endl;
          chipher( x );
        }
    }
  
  return 0;
}