#include<bits/stdc++.h>
#define DBG(x) cerr << #x << “ = ” << (x) << endl
#define Rep(i,a,b) for (int i = a, to = b; i < to; i++)
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()

typedef long long Long;

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	Long n,x,t;
    cin>>n>>x>>t;
    cout<<((n+x-1)/x)*t;
     
	return 0;
}