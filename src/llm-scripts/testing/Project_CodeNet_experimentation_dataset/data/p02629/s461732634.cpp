#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef map<ll,ll>::iterator itll;
typedef long double ld;
typedef map<ll,ll> mapll;

#define con continue
#define pb push_back
#define fi first
#define se second
#define fr front()
#define INF 1000000000000000000
#define all(vl) vl.begin(),vl.end()
#define m_p make_pair 
#define sz(a) sizeof(a)
#define forn(mp,it) for(it = mp.begin();it!=mp.end();it++)
#define FOR(i,a,n) for(int i=a;i<n;i++) 
#define FORE(i,a,n) FOR(i,a,n+1)
#define Endl endl
#define eNdl endl
#define enDl endl
#define endL endl

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll k;
	cin>>k;
	vector<ll> vl;
	string s = "~abcdefghijklmnopqrstuvwxyz";
	if(k<=26)
	{
		cout<<s[k]<<endl;
		return 0;
	}
	while(k>=26)
	{
		ll yu = k%26;
		k/=26;
		if(yu == 0)
		{
			yu = 26;
			k--;
		}
		vl.pb(yu);
	}
	if(k>0)
		vl.pb(k);
	reverse(all(vl));
	FOR(i,0,vl.size())
	{
		if(vl[i]>0)cout<<s[vl[i]];
		else cout<<"z";
	}
	cout<<endl;
	return 0;
}
