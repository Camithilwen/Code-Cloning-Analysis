#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

stack<char> stacky;

int solve(string X, int N, int ans) {
      for(int i=0; i<N; i++) {
            if(X[i] == 'S') stacky.push('S');
            else {      // encounter 't'
                  if(!stacky.empty()) stacky.pop(); 
                  else ans++;
            }
      }
      ans += stacky.size();
      return ans;
}

int main() {
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      string X;
      cin >> X;
      int N = X.size();
      
      cout << solve(X, N, 0) << endl;
}