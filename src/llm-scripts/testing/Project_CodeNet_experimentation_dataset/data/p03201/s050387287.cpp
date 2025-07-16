#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define PB push_back
#define ALL(x)      (x).begin(),(x).end()
#define REP(i,n)    for(int i=0;i<(n);i++)
#define REP1(i,n)   for(int i=1;i<(n);i++)
#define REP2(i,d,n) for(int i=(d);i<(n);i++)
#define RREP(i,n)   for(int i=(n);i>=0;i--)
#define CLR(a)      memset((a),0,sizeof(a))
#define MCLR(a)     memset((a),-1,sizeof(a))
#define RANGE(x,y,maxX,maxY) (0 <= (x) && 0 <= (y) && (x) < (maxX) && (y) < (maxY))

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<string> VS;
typedef vector<LL> VLL;
typedef pair<int,int> PII;

const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-9;

const int DX[]={1,0,-1,0},DY[]={0,-1,0,1};

void solve(long long N, std::vector<long long> A){
    map<int, int> memo;
    REP(i, N) {
        if(memo.count(A[i]) == 0) {
            memo[A[i]] = 0; 
        }

        memo[A[i]]++;
    }

    VLL beki;
    LL idx = 1;
    while(idx <= 2000000000LL) {
        beki.PB(idx);
        idx *= 2LL;
    }

    sort(ALL(A));
    A.erase(unique(ALL(A)), A.end());
    int ans = 0;
    RREP(i, A.size()-1) {
        REP(j, beki.size()) {
            int idx = beki[j] - A[i];
            if(memo.count(idx) == 1) {
                if(A[i] == idx) {
                    int add_ans = memo[idx] / 2;
                    memo[idx] -= add_ans * 2;
                    ans += add_ans;
                } else {
                    int add_ans = min(memo[idx], memo[A[i]]);
                    memo[idx] -= add_ans;
                    memo[A[i]] -= add_ans;
                    ans += add_ans;
                }
            }
        }
    }

    cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, std::move(A));
    return 0;
}

