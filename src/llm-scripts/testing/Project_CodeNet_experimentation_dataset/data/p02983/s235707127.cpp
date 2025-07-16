#include<bits/stdc++.h>
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
s.find_by_order(x) xth element in set
x.order_of_key(x) number of elements <x*/
#define ll long long
#define vi vector<int>
#define si set<int>
#define mii map<int,int>
#define pb push_back
#define pf push_front
#define pii pair<int,int>
#define extract_word(s)  stringstream str(s); while(str>>word)
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SET(s) cout<<fixed<<setprecision(s)
#define chotu 1000000007
#define set0(a) memset(a,0,sizeof(a))
#define endl "\n"
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define lower_string(s) transform(all(s),s.begin(),::tolower())
#define upper_string(s) transform(all(s),s.begin(),::toupper())
#define size(s) s.size()
template<class T> bool umin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool umax(T &a, T b) { return a < b ? (a = b, true) : false; }
template<typename T,typename U>
bool compare(T x,U y){return(abs(x-y)<=1e-9);}
void solve()
{
fastio
int l,r;
cin>>l>>r;
if(l==0)
cout<<0;
else
{
	if((r-l)>=2019)
	cout<<0;
	else
	{
		int ans=10000000;
		for(int i=l;i<=r;i++)
		{
			for(int j=i+1;j<=r;j++)
			ans=min(ans,((i%2019)*(j%2019))%2019);
		}
		cout<<ans;
	}
}
}
int main()
{
//code
fastio
int t;
t=1;
while(t--)
{
solve();
cout<<endl;
}
}
