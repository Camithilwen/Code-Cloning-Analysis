#include<bits/stdc++.h>
using namespace std;
#define fori(x,y)   for(ll i=x;i<y;i++)
#define forj(x,y)   for(ll j=x;j<y;j++)
#define rfori(a,b)   for(int i=a;i>=b;i--)
#define for_it(a)     for(auto it: a)
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(x)      x.begin(),x.end()
#define mp          make_pair
#define mod         1000000007
#define mem(a,b)    memset(a,b,sizeof(a))
#define ld          long double
#define endl        "\n"
#define ll          long long
#define llu         unsigned long long 
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define vl          vector<ll> 
#define vi          vector<int> 
#define vc          vector<char> 
#define vs          vector<string> 
#define si          set<int>
#define spii        set<pii>
#define usi         unordered_set<int>
#define usl         unordered_set<ll>
#define uspii       unordered_set<pii>
#define mii         map<int,int>
#define umii        unordered_map<int,int>
#define pqmx        priority_queue<int>
#define pqmn        priority_queue<int,vi,greater<int>>
#define setbits(x)  __builtin_popcountll(x)
#define fast        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define testcase    int test;cin>>test;for(ll tst=0;tst<test;tst++)
int xx[4]={0,0,1,-1};
int yy[4]={-1,1,0,0};

/*-----------------------------------------------------------------------------------------------------------------*/



int main()
{
	#ifndef ONLINE_JUDGE
	freopen("C_IN.txt","r",stdin);
	freopen("C_Out.txt","w",stdout);
	#endif
	fast;

	ll n,m;
	cin>>n>>m;
	vl v(11,0);
	fori(0,m)
	{
		int x;
		cin>>x;
		v[x]++;
	}
	ll res=0,b=n;
	while(1)
	{
		int temp=b;
		bool flag=true;
		while(temp>0)
		{
			int rem=temp%10;
			temp=temp/10;
			if(v[rem])
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			cout<<b;
			break;
		}
		b++;
	}
	return 0;
}




