#pragma GCC optimize "-O3"
#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define NumberOfOnes __builtin_popcount
#define LSOne(S) (S & (-S))
#define ll long long
#define two pair<int,int>
#define twoll pair<ll,ll>
#define four pair<two,two>
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define y1 y1922
#define INF 1000000000000000000
#define P 1000000007
#define lmax 1000000000
#define nn 1000003
#define ff first.first
#define fs first.second
#define sf second.first
#define ss second.second
#define f first
#define s second
#define vi vector<int>
#define vll vector<ll>
#define vtwo vector<two>
#define ALL(container) (container).begin(), (container).end()
#define sz(container) (int)(container.size())
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define mid(a,b) (a+b>>1)
#define minN 0
#define maxN 10000000
#define na(x) ((x)<P?(x):(x)-P)
#define ab(a) (-(a)<(a)?(a):-(a))
#define FAST std::ios::sync_with_stdio(false)
#define xRand mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define rnd rng
#define IT iterator
typedef
tree<
  int,// aq pair<int,int> shegidzlia
  null_type,
  less/*_equal*/<int>,// aqac
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_set;
// '_equal' mashin ginda roca multiset gchirdeba
template<class key, class value,class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
ordered_map<int, int> my_map;
inline int rin(){
	int x=0,w=1;char ch=getchar();
	while ((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if (ch=='-') w=0,ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return w?x:-x;
}
inline int bin(){
	int x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x;
}
int k,n,f[308][308][308];
string s;
int main(){FAST;xRand;
cin>>s;
cin>>k;
n=sz(s);
for(int i=n-1;i>=0;i--){
	for(int j=i;j<n;j++){
		for(int p=0;p<=k;p++){
			if(i==j){
				f[i][j][p]=1;
				continue;
			}
			if(i+1==j){
				f[i][j][p]=(s[i]==s[j]||p>0)?2:1;
				continue;
			}
			f[i][j][p]=max(f[i+1][j][p],f[i][j-1][p]);
			if(s[i]==s[j]){
				f[i][j][p]=max(f[i][j][p],f[i+1][j-1][p]+2);	
			}
			if(p>0){
				f[i][j][p]=max(f[i][j][p],f[i+1][j-1][p-1]+2);
			}
		}
	}
}
cout<<f[0][n-1][k]<<endl;
}
/*

                   *         *
                  * *       * *
                 *   *     *   *
                *     *   *     *
                 *   *   * *   *
                  *   *   *   *
                   *   * *   *
                     *  *   *
					   *  *


*/

