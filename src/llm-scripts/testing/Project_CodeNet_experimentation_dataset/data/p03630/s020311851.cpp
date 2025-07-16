#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto& (a): (b))
#define all(v) (v).begin(),(v).end()
#define len(v) (int)(v).size()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define cmx(x,y) x=max(x,y)
#define cmn(x,y) x=min(x,y)
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define sar(a,n) cout<<#a<<":";rep(pachico,n)cout<<" "<<a[pachico];cout<<endl

using namespace std;

template<typename S,typename T>auto&operator<<(auto&o,pair<S,T>p){return o<<"{"<<p.fi<<","<<p.se<<"}";}
template<typename T>auto&operator<<(auto&o,set<T>s){for(auto&e:s)o<<e<<" ";return o;}
template<typename S,typename T,typename U>
auto&operator<<(auto&o,priority_queue<S,T,U>q){while(!q.empty())o<<q.top()<<" ",q.pop();return o;}
template<typename K,typename T>auto&operator<<(auto&o,map<K,T>&m){for(auto&e:m)o<<e<<" ";return o;}
template<typename T>auto&operator<<(auto&o,vector<T>v){for(auto&e:v)o<<e<<" ";return o;}
void ashow(){cout<<endl;}template<typename T,typename...A>void ashow(T t,A...a){cout<<t<<" ";ashow(a...);}
template<typename S,typename T,typename U>
struct TRI{S fi;T se;U th;TRI(){}TRI(S f,T s,U t):fi(f),se(s),th(t){}};
template<typename S,typename T,typename U>
auto& operator<<(auto& o,TRI<S,T,U>& t){return o<<"{"<<t.fi<<","<<t.se<<","<<t.th<<"}";}

typedef pair<int, int> P;
typedef pair<ll, ll> pll;
typedef TRI<int, int, int> tri;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<P> vp;
typedef vector<double> vd;
typedef vector<string> vs;

const int MAX_N = 2005;

int t[MAX_N][MAX_N], a[MAX_N][MAX_N];
int h, w;

int calc()
{
	int ans = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
			if(a[i][j]) t[i+1][j] = 0;
			else t[i+1][j] = t[i][j] + 1;
		}
		t[i+1][w] = 0;
		stack<pair<int, int> > st;
		for(int j = 0; j <= w; j++){
			if(st.empty()){
				st.push({j, t[i+1][j]});
				continue;
			}
			pair<int, int> p = st.top();
			if(p.second < t[i+1][j]){
				st.push({j, t[i+1][j]});
			}else if(p.second > t[i+1][j]){
				int pos;
				while(p.second >= t[i+1][j]){
					ans = max(ans, (p.second+1)*(j-(pos=p.first)+1));
					st.pop();
					if(!st.empty()) p = st.top();
					else break;
				}
				st.push({pos, t[i+1][j]});
			}
		}
	}
	return ans;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> h >> w;
    rep(i,h){
        string s;
        cin >> s;
        rep(j,w){
            t[i][j] = (s[j] == '#');
        }
    }
    h--, w--;
	rep(i,h){
		rep(j,w){
			a[i][j] = (t[i][j]+t[i+1][j]+t[i][j+1]+t[i+1][j+1])%2;
		}
	}
    rep(j,w+1){
        t[0][j] = 0;
    }
	cout << max({h+1, w+1, calc()}) << "\n";
    return 0;
}
