#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
const int mod = 1e9+7;
const int mx = INT_MAX;
const long double pi = 4*atan((long double)1);
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
#define file "orz"
const int mxN = 2e5+5;
int arr[mxN], st[20][mxN];
int jump(int pos, int x)
{
	for(int i=19;i>=0;i--)
		if((x>>i)&1)
			pos = st[i][pos];
	return pos;
}
int main()
{
    //freopen(file".inp","r",stdin);
    //freopen(file".out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    	cin>>arr[i];
    int L;
    cin>>L;
    for(int i=1;i<=n;i++)
    {
    	int l = ub(arr+1,arr+n+1,arr[i]+L)-arr-1;
		st[0][i]=l; 
	}
	for(int i=1;i<20;i++)
		for(int j=1;j<=n;j++)
			st[i][j]=st[i-1][st[i-1][j]];
	int q;
	cin>>q;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		if(x>y)
			swap(x,y);
		int l=0, r=n;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(jump(x,mid)>=y)
				r = mid;
			else
				l = mid+1;
		}
		cout<<r<<endl;
	}
}
