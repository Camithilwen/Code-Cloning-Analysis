#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define f(i,a,b,c) for(ll i=a;i<b;i+=c)
#define r(i,a,b,c) for(ll i=a;i>=b;i-=c)
#define mod 1000000007
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n; cin >> n;
    ll ar[n];
    f(i,0,n,1){
    	cin >> ar[i]; 
    }
    ll c = 0;
    sort(ar,ar+n);
    f(i,0,n-2,1){
    	f(j,i+1,n-1,1){
    		f(k,j+1,n,1){
    		if(ar[i]+ar[j]>ar[k] && (ar[i]!=ar[j] && ar[j]!=ar[k] && ar[k]!=ar[i]))
    			c++;
    		}
    	}
    }
    cout << c;
    return 0;
}