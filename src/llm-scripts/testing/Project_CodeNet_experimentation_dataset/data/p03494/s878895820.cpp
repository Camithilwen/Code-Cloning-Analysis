#include<iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include<map>	
#include<cstring>
#include<iomanip>
#include <string>
#include <vector>	
#include<unordered_map>
#include<unordered_set>
using namespace std;


typedef long long unsigned llu;
typedef long double ld;
#define ll long long
#define PI 3.14159265358979323846
#define For(i, a, b) for (int i = a, sz = (int)b; i < sz; i++)
#define rFor(i, a, b, c) for (int i = (a); i >= (b); i -= (c))
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define fill(a, b) memset(a, b, sizeof(a))
#define IO ios_base::sync_with_stdio(false), cin.tie(0),cout.tie(0)
const int mod = 1000000007;
const ll inf = 1000000000009;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b) { return a*b/gcd(a,b);}

//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdoutn

int main()
{
	IO;
	int n{},res{},ans{},f{};
	cin>>n;
	vector<ll>v(n);
	For(i,0,n)cin>>v[i];
	while(true){
		For(i,0,n)
		{
			if(v[i]&1){f=1;break;}
			else if(!(v[i]%2))res++,v[i]/=2;
		}
		if(f){cout<<ans<<'\n';break;}
		if(res==n)ans++;
		res=0;
	}
//	system("pause");
	return 0;	
}