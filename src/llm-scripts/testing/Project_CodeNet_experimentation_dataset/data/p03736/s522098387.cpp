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
#include <numeric>
using namespace std;
typedef unsigned long long int ulint;
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
const int mod=(int)1000000007;
const llint big=(llint)(2.19e15)+1;
const long double pai=3.141592653589793238462643383279502884197;
const long double ena=2.71828182845904523536;
const long double eps=1e-7;
template <class T,class U>bool mineq(T& a,U b){if(a>b){a=b;return true;}return false;}
template <class T,class U>bool maxeq(T& a,U b){if(a<b){a=b;return true;}return false;}
template <class T> void soun(T& ar)
{sort(ar.begin(),ar.end());ar.erase(unique(ar.begin(),ar.end()),ar.end());}
llint gcd(llint a,llint b){if(a%b==0){return b;}else{return gcd(b,a%b);}}
llint lcm(llint a,llint b){return a/gcd(a,b) *b;}
template<class T,class U> auto LB(T& ve,U in){return lower_bound(ve.begin(),ve.end(),in);}
template<class T,class U> auto UB(T& ve,U in){return upper_bound(ve.begin(),ve.end(),in);}
template<class T,class U> auto LBI(T& ve,U in){return LB(ve,in)-ve.begin();}
template<class T,class U> auto UBI(T& ve,U in){return UB(ve,in)-ve.begin();}
template<class T> void SO(T& ve){sort(ve.begin(),ve.end());}
template<class T> void REV(T& ve){reverse(ve.begin(),ve.end());}
using pli=pair<llint,int>;
using daic=priority_queue<pli,vector<pli>,greater<pli>>;
class seg_tree{public:
	//セグ木
	vector<llint>val;
	seg_tree(void){val.res(524288);}
	//両側からアクセスするので、bitテクが使える
	//    1    
	// 2     3  
	//4  5  6  7
	
	//偶数ナンバーは、(短縮時間+x) を記録
	//奇数ナンバーは、(短縮時間-x) を記録
	llint que(llint bas,llint mae){
		llint time=-abs(bas-mae);//短縮
		int bi=bas-1+262144;
		while(bi>1){
			if(bi%2==0){maxeq(time,val[bi+1]+bas);}
			bi/=2;
		}
		bi=bas+1+262144;
		while(bi>1){
			if(bi%2==1){maxeq(time,val[bi-1]-bas);}
			bi/=2;
		}
		time+=abs(bas-mae);
		bi=mae+262144;
		while(bi>1){
			if(bi%2==0){maxeq(val[bi],time+mae);}
			if(bi%2==1){maxeq(val[bi],time-mae);}
			bi/=2;
		}
		return time;
	}
};
int main(void){
	seg_tree ki;
	int n,q;cin>>n>>q;
	int A;cin>>A;
	int mae;cin>>mae;
	int bi=A+262144;
	while(bi>1){
		if(bi%2==0){maxeq(ki.val[bi],big+A);}
		if(bi%2==1){maxeq(ki.val[bi],big-A);}
		bi/=2;
	}
	llint ans=0,wa=big;
	while(q--){
		llint x;cin>>x;
		maxeq(ans,ki.que(x,mae));
		wa+=abs(mae-x);
		mae=x;
		
	}
	cout<<wa-ans<<endl;RE;
}