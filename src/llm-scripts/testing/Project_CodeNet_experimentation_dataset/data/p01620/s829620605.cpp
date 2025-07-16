#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

  while( true ) {

    long long int n;
    cin >> n;
    if ( n == 0 ) break;

    vector< long long int > k;

    for ( long long int i = 0; i < n; i++ ) {
      long long int in;
      cin >> in;
      k.push_back( in );
    }

    string s;
    cin >> s;

    for ( long long int j = 0; j < s.size(); j++ ) {

      long long int b = k[ j % k.size() ];
      if ( b >= 26 ) {
	b -= 26;
	if ( s[j] >= 'a' && s[j] <= 'z' ) {
	  s[j] += 'A' - 'a';
	}else {
	  s[j] += 'a' - 'A';
	}
      }
      if ( s[j] >= 'a' && s[j] <= 'z' ) {
	s[j] -= b;
	if ( s[j] < 'a' ) {
	  s[j] += 26;
	  s[j] += 'A' - 'a';
	}
      }else {
	s[j] -= b;
	if ( s[j] < 'A' ) {
	  s[j] += 26;
	  s[j] += 'a' - 'A';
	}
      }

    }

    cout << s << endl;

  }

  return 0;

}