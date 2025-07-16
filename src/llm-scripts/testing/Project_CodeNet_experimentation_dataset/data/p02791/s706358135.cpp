#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define loop(i,n)for(i=0;i<n;i++)
#define INF 1000000000
using ll = long long int;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;


#define MAX 100005


int main()
{
    IOS;
    //freopen("inputfile.txt","r",stdin);
  ll n;cin>>n;
  ll ar[n];
  ll count = 0;ll mi;
  for(ll i=0;i<n;i++)
  {
      ll x;cin>>x;
      if(i==0)mi = x;
      else if(x>mi)count++;
      else mi = x;
  }
  cout<<n-count<<endl;
    return 0;
}
