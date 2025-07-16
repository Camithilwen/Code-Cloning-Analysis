#include <bits/stdc++.h>

#define int long long

using namespace std;

#ifdef LOCAL 
#include "/media/brayand/7801-B00D/debugger.h"
#else
template<typename... Args>
void db(Args... args){}
#endif

const int MOD = 1e9+7;

const int BAS = 331;

string A[30];
string rA[30];
string B[30];

const int MAXN = 2e5+100;

int mp[MAXN];
int val[MAXN];

int P[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    P[0] = 1;
    for(int i = 1 ; i < MAXN ; i++)P[i] = P[i-1]*BAS%MOD;

    int N;
    cin >> N;

    for(int i = 0 ; i < N ; i++)
    {
    	int n;
    	cin >> n;
    	for(int j = 0 ; j < 30 ; j++)
    	{
    		if(n&(1<<j))A[j] += "1", rA[j] += "0";
    		else A[j] += "0", rA[j] += "1";
    	}
    }

    for(int i = 0 ; i < N ; i++)
    {
    	int n;
    	cin >> n;
    	for(int j = 0 ; j < 30 ; j++)
    	{
    		if(n&(1<<j))B[j] += "1";
    		else B[j] += "0";
    	}
    }

    for(int i = 0 ; i < 30 ; i++)
    {
    	A[i] = A[i]+A[i];
    	rA[i] = rA[i]+rA[i];
    }

    vector<pair<int,int>> res[30];

    for(int i = 0 ; i < 30 ; i++)
    {
    	int ha1[A[i].size()+1];
    	int ha2[rA[i].size()+1];
    	int hhh = 0;

    	ha1[0] = 1;
    	ha2[0] = 1;

    	for(int x = 0 ; x < A[i].size() ; x++)
    	{
    		ha1[x+1] = (ha1[x]*BAS+A[i][x])%MOD;
    	}

    	for(int x = 0 ; x < rA[i].size() ; x++)
    	{
    		ha2[x+1] = (ha2[x]*BAS+rA[i][x])%MOD;
    	}

    	for(int x = 0 ; x < B[i].size() ; x++)
    	{
    		hhh = (hhh*BAS+B[i][x])%MOD;
    	}

    	for(int x = 0 ; x < N ; x++)
    	{
    		if((ha1[x+N]+MOD-ha1[x]*P[N]%MOD)%MOD == hhh)
    		{
    			res[i].push_back({x,0});
    		}
    	}

    	for(int x = 0 ; x < N ; x++)
    	{
    		if((ha2[x+N]+MOD-ha2[x]*P[N]%MOD)%MOD == hhh)
    		{
    			res[i].push_back({x,1});
    		}
    	}

    }

    for(int i = 0 ; i < 30 ; i++)
    {
    	for(auto x : res[i])
    	{
    		mp[x.first]++;
    		val[x.first] += (x.second)*(1ll<<i);
    	}
    }

    for(int i = 0 ; i < N ; i++)
    {
    	if(mp[i] == 30)
    	{
    		cout << i << " " << val[i] << '\n';
    	}
    }

    return 0;
}