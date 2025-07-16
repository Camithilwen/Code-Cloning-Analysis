#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MP make_pair
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define PLI pair<ll, int>
#define PIL pair<int, ll>
#define STR string
#define Fst first
#define Snd second
#define SHN 1e9
#define LSHN 1e18
using namespace std;
ll md=2038077799,mul=1400312813;
int n;
ll ai[200010],bi[200010],a[200010],b[200010];
vector<int> v;
ll hasha,hashb,etc;
ll ksm(int x)
{
	if (!x) return 1ll;
	return (((ksm(x/2)*ksm(x/2))%md)*(x%2 ? mul : 1))%md; 
}
int main()
{
	cin >>n;
	for (int i=0;i<n;i++) cin >>ai[i];
	for (int i=0;i<n;i++) cin >>bi[i];
	for (int i=0;i<n;i++) a[i]=ai[i]^ai[(i+1)%n],b[i]=bi[i]^bi[(i+1)%n];
	etc=ksm(n-1);
	for (int i=0;i<n;i++)
	{
		hasha=(((hasha*mul)%md)+a[i])%md;
		hashb=(((hashb*mul)%md)+b[i])%md;
	}
	for (int i=0;i<n;i++)
	{
		if (hasha==hashb) v.push_back(i);
		hasha=(hasha+md-((a[i]*etc)%md))%md;
		hasha=(((hasha*mul)%md)+a[i])%md;
	}
	for (int i=0;i<v.size();i++) cout <<v[i]<<" "<<(ai[v[i]]^bi[0])<<"\n";
	return 0;
} 