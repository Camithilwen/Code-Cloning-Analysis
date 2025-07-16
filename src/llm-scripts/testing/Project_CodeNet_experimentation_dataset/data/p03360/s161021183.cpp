#include <bits/stdc++.h>
using namespace std;

int main(){
  
  long long a,b,c,k,sum=0;
  cin >> a >> b >> c >> k;
  sum+=(a+b+c);
  long long x=max(a,max(b,c));
  sum-=x;
  for(long long i=0; i<k; i++){
    x*=2;
  }
  cout << x+sum << endl;
}