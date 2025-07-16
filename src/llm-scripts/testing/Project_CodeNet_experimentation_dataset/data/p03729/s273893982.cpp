#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
  string a,b,c;
  cin >> a >> b >> c;
  int n=a.size();
  int m=b.size();
  int l=c.size();
  if(a[n-1]==b[0] && b[m-1]==c[0])cout << "YES" << endl;
  else cout << "NO" << endl;

}

