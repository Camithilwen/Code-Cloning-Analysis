#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<cmath>
#include<tuple>
#include<string>
#include<chrono>
#include<functional>
#include<iterator>
#include<random>
#include<unordered_set>
#include<unordered_map>
#include<array>
#include<map>
#include<bitset>
#include<iomanip>
#include<list>
using namespace std;
typedef long long int llint;
typedef long double lldo;
#define mp make_pair
#define mt make_tuple
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define fir first
#define sec second
#define res resize
#define ins insert
#define era erase
#define RE return 0
//ios::sync_with_stdio(false);
//std::cin.tie(0);
//<< setprecision(20)
const int mod=1e9+7;
const int big=1e9+100;
const long double pai=3.141592653589793238462643383279502884197;
const long double ena=2.71828182845904523536;
const long double eps=1e-7;
template <class T,class U>void mineq(T& a,U b){if(a>b){a=b;}}
template <class T,class U>void maxeq(T& a,U b){if(a<b){a=b;}}
template <class T> void soun(T& ar)
{sort(ar.begin(),ar.end());ar.erase(unique(ar.begin(),ar.end()),ar.end());}
int main(void){
	int bi,i,j,n,m,all=0;cin>>n>>m;
	int hen[15][15];
	for(i=0;i<15;i++){
		for(j=0;j<15;j++){
			hen[i][j]=-big;
		}
	}
	for(i=0;i<m;i++){
		int a,b,c;cin>>a>>b>>c;a--;b--;
		all+=c;
		hen[a][b]=c;
		hen[b][a]=c;
	}
	int waka[32768]={0};
	//bitが立っているところでの残す道のア
	for(bi=0;bi<(1<<n);bi++){
		for(i=0;i<n;i++){
			if((bi&(1<<i))==0){continue;}
			for(j=0;j<i;j++){
				if((bi&(1<<j))==0){continue;}
				waka[bi]+=max(0,hen[i][j]);
			}
		}
	}
	static int dp[32768][15]={0};
	for(bi=0;bi<(1<<n);bi++){for(j=0;j<15;j++){dp[bi][j]=-big;}}
	for(bi=0;bi<(1<<(n-1));bi++){dp[bi][0]=waka[bi];}
	for(bi=0;bi<(1<<n);bi++){
		for(int bjj=0;bjj<(1<<n);){
			if((bi&bjj)!=0){
				bjj+=(bi&bjj);
				
				continue;
			}
			for(i=0;i<n;i++){
				if((bi&(1<<i))==0){continue;}
				for(j=0;j<n;j++){
					if((bjj&(1<<j))==0){continue;}
					maxeq(dp[bjj+bi][j],dp[bi][i]+waka[bjj]+hen[i][j]);
				}
			}
			bjj++;
		}
	}
	cout<<all-dp[(1<<n)-1][n-1]<<endl;
	RE;
}