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
 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//code here
    int n;
    cin >> n;
    vi a; in(a,n);
    ll res = 0;
    for(int i=1;i<n;i++){
        if(a[i]<a[i-1]){
            res += (a[i-1]-a[i]);
            a[i] = a[i-1];
        }
    }
    cout << res << endl;

}