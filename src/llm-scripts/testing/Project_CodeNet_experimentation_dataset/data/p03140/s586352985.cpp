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
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define reps(i,n) for(int i=1;i<=(int)n;i++)
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
#define MOD 1000000007
#define itn int
#define enld endl
using namespace std;
typedef long long ll;
const double pi = 3.141592653589793;
template<class T> bool chmax(T &a, const T &b){if(a<b){a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b){if(b<a){a=b; return 1;} return 0;}
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main(){
    int N; cin>> N;
    string A,B,C; cin >> A >> B >> C;
    int ans  =0;
    rep(i,N){
        int cnt = 0;
        if((A[i] != B[i]) && (B[i] != C[i]) && (C[i] != A[i])) ans += 2;
        else if((A[i] == B[i]) && (B[i] == C[i]) && (C[i] == A[i])) continue;
        else ans += 1;
    }
    cout << ans << enld;
    return 0;
}