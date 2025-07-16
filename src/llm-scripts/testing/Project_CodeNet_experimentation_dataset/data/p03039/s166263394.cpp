#include<iostream>
using namespace std;
int p = 1000000007;
int log2_p_MAX = 32;
long long felmer(long long a)
{
  long long rem[log2_p_MAX];
  rem[0] = a%p;
  for(int i=1;i<log2_p_MAX;i++)
    rem[i] = (rem[i-1]*rem[i-1])%p;
  long long res = 1;
  long long expo = p-2;
  for(int i=0;i<log2_p_MAX;i++){
	if(expo%2==1){
      res *= rem[i];
      res = res%p;
    }
  	expo /= 2;
  }
  return res;
}
int main()
{
  long long n,m,k,mn,i,res;
  cin >> n >> m >> k;
  res=m*n*(m*(n-1)*(n+1)+n*(m-1)*(m+1));
  res%=p;
  res*=felmer(6);
  res%=p;
  mn=m*n-2;
  k-=2;
  for(i=1;i<=k;i++){
    res*=mn-i+1;
    res%=p;
    res*=felmer(i);
    res%=p;
  }
  cout << res << endl;
  return 0;
}