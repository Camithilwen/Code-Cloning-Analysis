#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <ctype.h>
#include <algorithm>
using namespace std;

#define loop(i,a,b) for(int i=(a); i<(int)(b); i++)
#define rep(i,b) loop(i,0,b)
#define all(c) (c).begin(), (c).end()
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

int main() {
  string s; 
  while(getline(cin, s)) {
    int slide = 0;
    rep(i, s.size()-4) {
      if(islower(s[i]) == 0) continue;
      rep(j, 26) {
        string sub;
        rep(k, 4) sub += (s[i+k]-'a'+j+52)%26 + 'a';
        if(sub.substr(0,3) == "the") slide = j;
        else if(sub == "this" || sub == "that") slide = j;
      }
      if(slide != 0) break;
    }
    rep(i, s.size()) {
      if(islower(s[i]) != 0)printf("%c", (s[i]-'a'+slide+52)%26 + 'a');
      else cout << s[i];
    }
    cout << endl;
  }
}