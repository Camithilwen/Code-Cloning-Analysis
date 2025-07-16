#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <fstream>
#include <numeric>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;

#define EPS (1e-7)
#define INF 1e18
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define rep(i, init, n) for(int i = init; i <(int)(n); i++)

int main() {
    ll N, M;
    cin >> N >> M;

    if ((N % 2) == 1){
        REP(i, M){
            cout << (i + 1) << " " << (N - i - 1) << endl;
        }
    }else{

        vector<P> v;
        int i = 1;
        while(v.size()<M+1){
            v.push_back(P(i, N + 1 - i));
            v.push_back(P(N / 2 - i, N / 2 + i));
            i++;
        }
        REP(i, M) cout << v[i].first << " " << v[i].second << endl;

    }

    return 0;
}