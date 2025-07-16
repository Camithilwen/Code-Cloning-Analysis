#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define loop(i,a,b) for(int i=(a); i<(int)(b); i++)
#define rep(i,b) loop(i,0,b)
#define all(c) (c).begin(), (c).end()
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

int main() {
  int n; cin >> n;
  string s;
  getline(cin, s);
  while(n--) {
    getline(cin, s);
    rep(i, s.size()) {
      if(s.substr(i, 7) == "Hoshino") s[i+6] = 'a';
    }
    cout << s << endl;
  }
}