///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define                           ll                          long long
#define                           int                         ll
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<ll,ll>
#define                           clr(x)                      memset(x,0,sizeof(x));
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           show(x,y)                   cout<<x<<" : ";for(auto z:y)cout<<z<<" ";cout<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const ll inf=1e18;
const int mod=1e9+7;

struct BIT
{
	int N;
	vector<int> bit;

	void init(int n)
	{
		N = n;
		bit.assign(n + 1, 0);
	}

	void update(int idx, int val)
	{
		while(idx <= N)
		{
			bit[idx] += val;
			idx += idx & -idx;
		}
	}

	void updateMax(int idx, int val)
	{
		while(idx <= N)
		{
			bit[idx] = max(bit[idx], val);
			idx += idx & -idx;
		}
	}

	int pref(int idx)
	{
		int ans = 0;
		while(idx > 0)
		{
			ans += bit[idx];
			idx -= idx & -idx;
		}
		return ans;
	}

	int rsum(int l, int r)
	{
		return pref(r) - pref(l - 1);
	}

	int prefMax(int idx)
	{
		int ans = -2e9;
		while(idx > 0)
		{
			ans = max(ans, bit[idx]);
			idx -= idx & -idx;
		}
		return ans;
	}
};


const int M=502;
vector<int>vec[M];
int ses[100009];
vector<pi>yo[M];
vector<pi>abr_yo[M];
BIT Magic;
 main()

{
    fast
    int n,m,q;
    cin>>n>>m>>q;
    Magic.init(503);
    f(i,1,m)
    {
        int l,r;
        cin>>l>>r;
        vec[l].pb(r);
    }
    f(i,1,q)
    {
        int l,r;
        cin>>l>>r;
        yo[l].pb(mp(r,i));
        abr_yo[r].pb(mp(l,i));
    }
    f(i,1,500)
    {
       for(auto x:yo[i])
       {
           int idx=x.si;
           int rgt=x.fi;
           int lft=i;
           ses[idx]=-Magic.rsum(lft,rgt);
       }
       for(auto x:vec[i])
       {
           Magic.update(x,1);
       }
    }
    Magic.init(503);
    f(i,1,500)
    {
        for(auto x:vec[i])
       {
           Magic.update(x,1);
       }
       for(auto x:abr_yo[i])
       {
           int idx=x.si;
           int lft=x.fi;
           int rgt=i;
           ses[idx]+=Magic.rsum(lft,rgt);
       }

    }
    f(i,1,q)
    {
        cout<<ses[i]<<endl;
    }
     cout<<endl;
    return 0;

}



































