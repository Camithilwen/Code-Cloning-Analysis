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
int DP[301*301*301];
void Calc(){
	string S = res();
	int K = rei();
	int N = S.length();
	for(int i=0;i<N;i++){
		for(int j=N-1;j>i;j--){
			for(int k=0;k<=K;k++){
				DP[(i+1)*301*301+j*301+k] = max(DP[i*301*301+j*301+k],DP[(i+1)*301*301+(j+1)*301+k]);
				if(S[i] == S[j]){
					DP[(i+1)*301*301+j*301+k] = max(DP[(i+1)*301*301+j*301+k],DP[i*301*301+(j+1)*301+k]+1);
				}
				else if(k != 0){
					DP[(i+1)*301*301+j*301+k] = max(DP[(i+1)*301*301+j*301+k],DP[i*301*301+(j+1)*301+k-1]+1);
				}
			}
		}
	}
	int ans = 1;
	for(int k=0;k<=K;k++){
		for(int i=0;i<N-1;i++){
			ans = max(DP[(i+1)*301*301+(i+1)*301+k]*2,ans);
		}
		for(int i=0;i<N-2;i++){
			ans = max(DP[(i+1)*301*301+(i+2)*301+k]*2+1,ans);
		}
	}
	cout << ans << endl;
}
int main(int argc,char** argv){
	ios::sync_with_stdio(false), cin.tie(0);
	cout.tie(0); Calc(); return 0;
}