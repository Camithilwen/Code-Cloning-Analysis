#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define int long long
#define INF 1000000000000000000
using namespace std;

#define ANS(f) if(f) cout << "YES" << endl; else cout << "NO" << endl;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;

template<typename T>
void readv(vector<T> &a){ REP(i, a.size()) cin >> a[i]; }
void readi(vector<int> &a){ REP(i, a.size()){cin >> a[i]; a[i]--;} }
void debug(mat m){REP(i, m.size()){ REP(j, m[0].size()){ cout << m[i][j] << ","; } cout << endl; }}

class RMQ_segment_tree
{
    using data_type = int;

public:

    vector<data_type> dat;
    int N;
    data_type inf;

    RMQ_segment_tree(int n, data_type inf): inf(inf) {
        N = 1;
        while(n > N) N = N << 1;
        dat = vector<data_type>(2 * N - 1, inf);
    }

    //k番目の値をaに更新
    void update(int k, data_type a){
        k += N - 1;
        dat[k] = a;
        while(k > 0){
            k = (k - 1) / 2;
            dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    //[a, b)の最小値
    data_type minval(int a, int b){
        return query(a, b, 0, 0, N);
    }

    data_type query(int a, int b, int k, int l, int r){
        if(r <= a || b <= l) return inf;
        if(a <= l && r <= b) return dat[k];
        else{
            data_type vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
            data_type vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
            return min(vl, vr);
        }
    }
};

signed main(){

    int N, Q, A, B; cin >> N >> Q >> A >> B;
    vec x(Q); readv(x);
    RMQ_segment_tree P(N + 1, INF), M(N + 1, INF);

    P.update(A, llabs(x[0] - B) + A);
    M.update(A, llabs(x[0] - B) - A);
    P.update(B, llabs(x[0] - A) + B);
    M.update(B, llabs(x[0] - A) - B);

    int ans = 0;
    FOR(i, 1, Q){
        int tmp = llabs(x[i] - x[i - 1]);
        ans += tmp;
        int mm = M.minval(0, x[i]) + x[i] - tmp;
        int mp = P.minval(x[i], N + 1) - x[i] - tmp;
        int v = P.minval(x[i - 1], x[i - 1] + 1) - x[i - 1];
        int m = min(v, min(mm, mp));
        P.update(x[i - 1], m + x[i - 1]);
        M.update(x[i - 1], m - x[i - 1]);
    }
    int m = INF;
    FOR(i, 1, N + 1) m = min(m, P.minval(i, i + 1) - i);
    ans += m;
    cout << ans;
    
    return 0;
}