//cwystc <--> 陈威宇是天才  --by cwy
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const double PI=acos(-1);
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define per(i,a,b) for (int i=(a);i>=(b);i--)
#define Rep(i,a,b) for (int i=(a);i<(b);i++)
#define Per(i,a,b) for (int i=(a);i>(b);i--)
#define travel_set(it,a) for (set<int>::iterator (it)=(a).begin();(it)!=(a).end();(it)++)
#define travel_map(it,a) for (map<int>::iterator (it)=(a).begin();(it)!=(a).end();(it)++)
#define travel_vec(it,a) for (vector<int>::iterator (it)=(a).begin();(it)!=(a).end();(it)++)
#define p(x) cout << x << endl;
#define def cout << "find" << endl;
#define what_is(x) cout << #x << " is " << x << endl;
template <class T>T sqr(T x){return x*x;}
template <class T>T alex(T x){return (x>0)?x:-x;}
template <class T>void read(T&x){
	x=0;T f=1;char ch=getchar();
	while ((ch<48||ch>57)&&ch!=45)ch=getchar();
	if (ch==45)f=-1,ch=getchar();
	while (ch>=48&&ch<=57)x=x*10+ch-48,ch=getchar();
	x*=f;
}

//-------------------------------------------------head-------------------------------------------------

#define maxn 305
int f[maxn][maxn][maxn];
char s[maxn],_s[maxn];int k,len;
int main(){
	scanf("%s",s+1);len=strlen(s+1);read(k);
	rep(i,1,len)_s[i]=s[len-i+1];
	// rep(i,0,len)f[i][0][0]=f[0][i][0]=0;
	rep(i,1,len)rep(j,1,len)if (i!=0&&j!=0){
		f[i][j][0]=max(max(f[i-1][j][0],f[i][j-1][0]),f[i-1][j-1][0]+(s[i]==_s[j]));
		rep(kk,1,k){
			f[i][j][kk]=max(max(f[i-1][j][kk],f[i][j-1][kk]),f[i-1][j-1][kk-(s[i]!=_s[j])]+1);
		}
	}
	int res=0;
	rep(i,1,len)rep(kk,0,k)res=max(f[i][len-i][k]*2,res);
	rep(i,1,len)rep(kk,0,k)res=max(f[i-1][len-i][kk]*2+1,res);printf("%d\n",res);return 0;
}