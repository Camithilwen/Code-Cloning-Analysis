#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  int A = min(a,b);
  int B = max(a,b);
  for(int i=A;i<=B;i++){
    if(i == c){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}