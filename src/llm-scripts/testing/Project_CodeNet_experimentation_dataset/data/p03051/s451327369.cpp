#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <functional>

using namespace std;
 
#define mod 1000000007
#define FOR(x,to) for(int x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define long long long
inline int rei(){int x;cin>>x;return x;}
inline long rel(){long x;cin>>x;return x;}
inline string res(){string x;cin>>x;return x;}
//------------------------------------------------------- 
int A[500000];
int acum[500001];
bool S[500001];
int zero[500001];
long DP[500001];
long DP2[500001];
vector<pair<int,int>> Data;
void Calc(){
	int N = rei();
	for(int i=0;i<N;i++){
		A[i] = rei();
	}
	for(int i=0;i<N;i++){
		acum[i+1] = acum[i] ^ A[i];
	}
	if(acum[N] == 0){
		int z = 0;
		for(int i=0;i<=N;i++){
			if(acum[i] == 0){
				z++;
			}
			else{
				Data.push_back({acum[i],i});
			}
			zero[i] = z;
		}
		sort(Data.begin(),Data.end());
		long ans = 1;
		for(int i=0;i<z-2;i++){
			ans <<= 1;
			ans %= mod;
		}
		int p = 0;
		while(p < Data.size()){
			long c = 1;
			long d = 1;
			while(p+1 < Data.size() && Data[p].first == Data[p+1].first){
				p++;
				d += c * (zero[Data[p].second] - zero[Data[p-1].second]);
				d %= mod;
				c += d;
				c %= mod;
			}
			p++;
			ans += c;
			ans %= mod;
		}
		cout << ans << endl;
	}
	else{
		int c = 0;
		for(int i=0;i<=N;i++){
			if(acum[i] == 0){
				S[c++] = false;
			}
			else if(acum[i] == acum[N]){
				S[c++] = true;
			}
		}
		DP[0] = 1;
		for(int i=1;i<c;i++){
			if(S[i]){
				DP[i] = DP[i-1];
				DP2[i] = (DP[i-1] + DP2[i-1]) % mod;
			}
			else{
				DP[i] = (DP[i-1] + DP2[i-1]) % mod;
				DP2[i] = DP2[i-1];
			}
		}
		cout << DP[c-1] << endl;
	}
}
int main(int argc,char** argv){
	ios::sync_with_stdio(false), cin.tie(0);
	cout.tie(0); Calc(); return 0;
}