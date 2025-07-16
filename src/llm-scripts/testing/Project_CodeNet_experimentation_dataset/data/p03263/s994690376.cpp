#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(int)(n); i<i##_len; i++)
#define reps(i,n) for(int i=1 , i##_len=(int)(n);i<=i##_len;i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define rreps(i,n) for(int i=((int)(n));i>0;i--)
#define repi(i,x) for(auto i=(x).begin(),i##_fin=(x).end();i!=i##_fin;i++)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define solve(a) ((a)?"Yes":"No")
typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef pair<int , int> Pi;
typedef vector<Pi> VPi;
typedef vector<long long> V;
typedef vector<V> VV;
typedef pair<long long , long long> P;
typedef vector<P> VP;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
const long long INFLL = 1LL<<60;
const int INF = 1<<30;
const double PI=acos(-1);
int main(){
	int h,w;
	cin >>h>>w;
	VVi a(h,Vi(w,0));
	int bef;
	vector<pair<pair<int,int>,pair<int,int>>>ans;
	rep(i,h){
		rep(j,w){
			cin>>bef;
			a[i][j]+=bef;
			if(a[i][j]%2){
				if(j!=w-1){
					ans.push_back(mp(mp(i,j),mp(i,j+1)));
					a[i][j+1]++;
					a[i][j]--;
				}else if(i!=h-1){
					ans.push_back(mp(mp(i, j), mp(i+1, j )));
					a[i+1][j ]++;
					a[i][j]--;
				}
			}
		}
	}
	cout<<ans.size()<<endl;
	rep(i,ans.size()){
		printf("%d %d %d %d\n",1+ans[i].F.F,1+ans[i].F.S,1+ans[i].S.F,1+ans[i].S.S);
	}
}