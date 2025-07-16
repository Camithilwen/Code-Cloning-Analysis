#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
int main()
{
  ll n,m,t,i,res=0;
  cin >> n;
  m=(ll)sqrt(n);
  for(i=m;i>0;i--)
    if(n%i==0){
      t=n/i;
      while(t>0){
        t/=10;
        res++;
      }
      cout << res << endl;
      return 0;
    }
  return 0;
}