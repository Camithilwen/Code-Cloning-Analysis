#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;

#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
#define pi  3.14159265359
#define mod 1000000007


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    char val[5+1]={'a','a','a','a','a'};
    bool t=false;
    for(int i=1;i<=m;i++)
    {
        int x;char y;
        cin>>x>>y;
        if(val[x]=='a'){
            val[x]=y;
        }else{
        if(val[x]!=y){
            t=true;
        }
        }
    }

    if(t){
        cout<<-1;
    }else if(val[1]=='0'&&n>=2){
        cout<<-1;
    }else{
     if(val[1]=='a'){
        if(n>=2)
        val[1]='1';
        else
        val[1]='0';
     }
     for(int i=1;i<=n;i++)
     {
         if(val[i]!='a') cout<<val[i];
         else  cout<<0;
     }
    }
}


