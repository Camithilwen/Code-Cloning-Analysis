#include <iostream>
#include <string>
using namespace std;
int main( void )
{
  string s;
  while( 1 ){
    getline( cin, s );
    if( cin.eof() ) break;
    while( 1 ){
      for( int i=0; i<s.size(); i++ ){
        if( s[i] == 'z' ) s[i] = 'a';
        else if( 'a' <= s[i] && s[i] < 'z' ) s[i]++;
      }
      if( s.find( "the",  0 ) != string::npos ){ cout << s << endl; break; }
      if( s.find( "this", 0 ) != string::npos ){ cout << s << endl; break; }
      if( s.find( "that", 0 ) != string::npos ){ cout << s << endl; break; }
    }
  }
  return 0;
}