#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x)  x.begin(),x.end()
#define vi vector<int>
#define vll vector<ll>
#define print(x) for(auto it=x.begin();it!=x.end();it++) cout<<*it<<' '; cout<<'\n';
#define debug(a,b,c) cout << a << " " << b << " " << c << endl;
#define in(x,n) for(int e=0;e<n;e++){int y;cin>>y;x.pb(y);}
#define inl(x,n) for(int e=0;e<n;e++){ll y;cin>>y;x.pb(y);}
#define lower(sl)  transform(sl.begin(), sl.end(), sl.begin(), ::tolower); 
#define endl "\n";
#define pi pair<int,int>
#define vpi vector<pair<int,int>>
#define vvi vector<vector<int>>
 
int solve(int st, vi a, int& ans,int& n){
	if(st > n ) return 0;
	int res = 0;
	int x1 = solve(st*2, a, ans, n);
	int x2 = solve(st*2+1, a, ans, n);
	int l1 = (st*2-2)>=a.size()?0:a[st*2-2];
	int l2 = (st*2-1)>=a.size()?0:a[st*2-1];
	l2 += x2; l1+=x1;
	ans += abs(l2-l1);
	return max(l1,l2); 
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//code here
	int a, b;
	cin >> a>> b;
	cout << (ll) a*b << endl;
}