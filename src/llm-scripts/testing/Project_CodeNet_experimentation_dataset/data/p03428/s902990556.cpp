#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define int long long
#define INF 1000000000000000
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;
typedef pair<double, int> Pdi;

template<typename T>
void readvec(vector<T> &a);
void readindex(vector<int> &a);

double pi = 3.141592653589793238;

signed main(){

    int N; cin >> N;
    vector<double> x(N), y(N);

    REP(i, N) cin >> x[i] >> y[i];

    vector<double> ans(N, 0.0);
    
    int n = 1000000;
    REP(i, n){
        double theta = 2.0 * pi * (double)i / (double)(n);
        double maxv = -1.0 * INF, v;
        int maxi;
        REP(j, N){
            v = x[j] * cos(theta) + y[j] * sin(theta);
            if(v > maxv){
                maxv = v;
                maxi = j;
            }
        }
        ans[maxi] += 1.0 / (double)n;
    }

    REP(i, N) cout << ans[i] << endl;
    
    return 0;
}


template<typename T>
void readvec(vector<T> &a){
    REP(i, a.size()){
        cin >> a[i];
    }
}
void readindex(vector<int> &a){
    REP(i, a.size()){
        cin >> a[i];
        a[i]--;
    }
}