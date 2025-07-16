#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define M 1000000007
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define f first
#define s second
#define b begin
#define e end
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for(i=a;i<b;i++)
#define RFOR(i,a,b) for(i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define itfr(it,x) for(it=x.begin();it!=x.end();it++)
#define flash ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int main()
{
    flash;
    //sieve();
    ll T=1,t,n,m,q,k,i,j;
    // cin>>T;
    while(T--)
    {
      string st;
      cin>>st;
      int fl=1;
      n = st.size();
      vector<int> ind(26,-10);
      FOR(i,0,n)
      {
        int x = ind[st[i]-'a'];
        if((i-x)<3){
          cout<<x+1<<" "<<i+1<<endl;
          fl=0;
          break;
        }
        ind[st[i]-'a']=i;
      }
      if(fl)
        cout<<-1<<" "<<-1<<endl;
    }
}