#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int main()
{
  int n,m;cin>>n>>m;
  vector<int> a(m);
  vector<int> b(m);
  int i;
  int even=m/2;
  int odd=m-even;
  rep(i,odd)//1 to odd*2
  {
    a[i]=i+1;
    b[i]=odd*2-i;
  }
  int add=odd*2;
  rep(i,even)
  {
    a[odd+i]=add+i+1;
    b[odd+i]=m*2+1-i;
  }
  rep(i,m)
  {
    cout<<a[i]<<' '<<b[i]<<endl;
  }
}
