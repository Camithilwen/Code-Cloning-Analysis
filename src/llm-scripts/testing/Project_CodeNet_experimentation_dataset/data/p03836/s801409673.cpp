#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
//マクロ
//forループ関係
//引数は、(ループ内変数,動く範囲)か(ループ内変数,始めの数,終わりの数)、のどちらか
//Dがついてないものはループ変数は1ずつインクリメントされ、Dがついてるものはループ変数は1ずつデクリメントされる
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
//xにはvectorなどのコンテナ
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
//定数
#define INF 1000000000000 //10^12:極めて大きい値,∞
#define inf 2147483647 //int値の最大値
#define MOD 1000000007 //10^9+7:合同式の法
#define MAXR 100000 //10^5:配列の最大のrange(素数列挙などで使用)
//略記
#define PB push_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素
#define cint(n) int n;cin>>n;
#define CST(x) cout<<fixed<<setprecision(x)//小数点以下の桁数指定
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int gcd(int a, int b) {
    if (b==0) return a;
    else return gcd(b, a%b);
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	int sx,sy,tx,ty;cin>>sx>>sy>>tx>>ty;
	rep(i,tx-sx){
	    cout<<"R";
	}
	rep(i,ty-sy){
	    cout<<"U";
	}
	rep(i,tx-sx){
	    cout<<"L";
	}
	rep(i,ty-sy){
	    cout<<"D";
	}
	cout<<"D";
	rep(i,tx-sx){
	    cout<<"R";
	}
	cout<<"RU";
	rep(i,ty-sy){
	    cout<<"U";
	}
	cout<<"LU";
	rep(i,tx-sx){
	    cout<<"L";
	}
	cout<<"LD";
	rep(i,ty-sy){
	    cout<<"D";
	}
	cout<<"R"<<endl;
	return 0;
}
