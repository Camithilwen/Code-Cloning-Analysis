// organize and stay in moment  - Abhinav IIITA
#include <bits/stdc++.h>
using namespace std;
#define int long long int 
#define pb push_back
#define ff first
#define ss second
#define ld long double
#define f(i,x,n) for(int i=x;i<n;++i)
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};
int m=1e9+7;

vector<int> pr;
int prime[200005]={0};
void seive(){
  for(int i=2;i<200005;++i){
    if(prime[i]==0){
      pr.pb(i);
      for(int j=2*i;j<200005;j+=i){
        prime[j]=1;
      }
    }
  }
}

// -----------------------------------------------------------------------
 
 
 int exp(int a,int b){
  int r=1;
  while(b!=0){
    if(b&1){
      r*=a;
    }
    b/=2;
    a*=a;
  }
  return r;
 }

// -----------------------------------------------------------------------

 
void solve(){ 
  int h1,m1,h2,m2,k; 
  cin>>h1>>m1>>h2>>m2>>k;
  int h=(h2-h1-1)*60;
  h+=(m2+60-m1-k);
  cout<<h;
}
 
// -----------------------------------------------------------------------
 
 
int32_t main()
{
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);  
  int t=1; //  cin>>t;
  //seive();
  while(t--)
  solve();
  return 0;
}