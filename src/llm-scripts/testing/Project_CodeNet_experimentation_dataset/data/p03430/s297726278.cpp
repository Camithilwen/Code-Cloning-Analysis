#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define lol(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
#define maz(a,b) a=max(a,b);
typedef long long ll;

using namespace std;
#define N 310
ll d[N][N][N],n,x;
string s;
int main(){
    cin>>s>>x; n=s.size();
    lol(k,x+1)lol(i,n)d[0][i][k]=0,d[1][i][k]=1;
    for(ll t=2;t<=n;t++){
	for(ll i=0;i+t-1<n;i++)lol(k,x+1){
	    ll l=i,r=i+t-1;
	    ll res=max(d[t-1][i][k],d[t-1][i+1][k]);
	    if(s[l]==s[r]){
		maz(res,d[t-2][i+1][k]+2);
	    }
	    else if(k){
		maz(res,d[t-2][i+1][k-1]+2);
	    }
	    d[t][i][k]=res;
	}
    }
    cout<<d[n][0][x]<<endl;
    return 0;
}
