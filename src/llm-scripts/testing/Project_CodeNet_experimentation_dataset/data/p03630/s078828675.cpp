#include <bits/stdc++.h>
using namespace std;
#define int long long
#define stoi stoll
using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;
#define ALL(c) begin(c),end(c)
#define RALL(c) rbegin(c),rend(c)
#define ITR(i,b,e) for(auto i=(b);i!=(e);++i)
#define FORE(x,c) for(auto &x:c)
#define REPF(i,a,n) for(int i=a,i##len=(int)(n);i<i##len;++i)
#define REP(i,n) REPF(i,0,n)
#define REPR(i,n) for(int i=(int)(n);i>=0;--i)
#define SZ(c) ((int)c.size())
#define CONTAIN(c,x) (c.find(x)!=end(c))
#define OUTOFRANGE(y,x,h,w) ((y)<0||(x)<0||(y)>=(h)||(x)>=(w))
#define dump(...)
const signed INF_=1001001001; const ll INF=1001001001001001001LL;
const int DX[9]={0,1,0,-1,1,1,-1,-1,0},DY[9]={-1,0,1,0,-1,1,1,-1,0};
template<class T> ostream& operator<<(ostream &os,const vector<T> &v) {
    ITR(i,begin(v),end(v))os<<*i<<(i==end(v)-1?"":" ");return os;}
template<class T> istream& operator>>(istream &is,vector<T> &v) {
    ITR(i,begin(v),end(v)) is>>*i;return is;}
template<class T,class U> istream& operator>>(istream &is, pair<T,U> &p) {
    is>>p.first>>p.second;return is;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}return 0;}
template<class T> using heap=priority_queue<T,vector<T>,greater<T>>;
struct{template<class T> operator T(){T x;cin>>x;return x;}} IN;
struct before_main_function {
    before_main_function() {
        cin.tie(0);ios::sync_with_stdio(false);
        cout<<setprecision(15)<<fixed;
        #define endl "\n"
    }
} before_main_function;
//------------------8<------------------------------------8<--------------------

int H,W;
vector<vector<int>> b;
int calc(int y) {
    int ret=0;
    stack<pair<int,int>> st;
    REP(j,W) {
        if(st.empty() || st.top().first<b[y][j]) {
            st.push({b[y][j],j});
        } else if(st.top().first>b[y][j]) {
            int idx=0;
            while(!st.empty() && st.top().first>b[y][j]) {
                auto tp=st.top();
                idx=tp.second;
                st.pop();
                chmax(ret,(j-tp.second+1)*tp.first);
            }
            st.push({b[y][j],idx});
        }
    }
    return ret;
}
signed main() {
    cin>>H>>W;
    vector<string> S(H);
    cin>>S;
    b=vector<vector<int>>(H,vector<int>(W,0));
    REP(j,W-1) {
        b[0][j]=1;
        REPF(i,1,H) {
            if((S[i][j]==S[i][j+1])==(S[i-1][j]==S[i-1][j+1])) {
                b[i][j]=b[i-1][j]+1;
            } else {
                b[i][j]=1;
            }
        }
    }
    int ans=max(H,W);
    REP(i,H) {
        chmax(ans,calc(i));
    }
    cout<<ans<<endl;
    return 0;
}

