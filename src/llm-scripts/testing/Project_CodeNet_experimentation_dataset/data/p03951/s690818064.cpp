# include <iostream>
# include <string>
using namespace std;

int main(){
  int n;
  string s, t;

  cin >> n >> s >> t;
  int maxLen = 0;
  for(int i=1; i<=n; i++){
    if(s.substr(n-i) == t.substr(0,i))
      maxLen = max(maxLen, i);
  }

  cout << 2*n - maxLen << endl;
  return 0;
}