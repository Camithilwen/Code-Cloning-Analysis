#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<string>
#define rep(i,n,m) for(int i=(n);i<(int)(m);i++)
#define reps(i,n,m) for(int i=(n);i<=(int)(m);i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define LB(a,x) lb(all(a), x) - a.begin()
#define UB(a,x) ub(all(a), x) - a.begin()
#define printfdouble(x) printf("%.12f\n",(x))
#define chartoint(c) (int)((c) - '0')
#define chartoll(c) (long long)((c) - '0')
#define MOD 1000000007
#define itn int
#define enld endl
#define ednl endl
#define icn cin
#define stirng string
using namespace std;
typedef long long ll;
const double pi = 3.141592653589793;
using Graph = vector<vector<int>>;
template<class T> bool chmax(T &a, const T &b){if(a<b){a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b){if(b<a){a=b; return 1;} return 0;}
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}


int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    int N; cin >> N;
    pair<int,int> red[105];
    pair<int,int> blue[105];
    rep(i,0,N){
        int a,b; cin >> a >> b;
        red[i] = {a,b};
    }
    rep(i,0,N){
        int c,d; cin >> c >> d;
        blue[i] = {c,d};
    }
    sort(red,red+N);
    sort(blue,blue+N);
    int ptr = 0;
    int ans = 0;
    bool used[105];
    Fill(used,false);
    rep(i,0,N){
        int cnt = -1;
        int maxy = -1;
        rep(j,0,N){
            if(blue[i].first > red[j].first && blue[i].second > red[j].second && used[j] == false){
                if(maxy < red[j].second){
                    maxy = red[j].second;
                    cnt = j;
                }
            }
        }
        if(cnt != -1){
            used[cnt] = true;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}