#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N,K;
    cin >> N >> K;
    deque<int> V_origin;
    REP(i,N){
        int v;
        cin >> v;
        V_origin.push_back(v);
    }


    int ans = 0;
    int KK = K;
    K = min(K,N);

    REP(i,K/2+1){
        REP(j,K-i+1){
            //cout << "front: "<< j <<  ", back: " << K-i-j << ", return: " << i << endl;
            deque<int> V(V_origin);
            vector<int> my;
            REP(k,j){
                int d = V.front();
                V.pop_front();
                my.push_back(d);
            }
            FOR(k,j+1,K-i+1){
                int d = V.back();
                V.pop_back();
                my.push_back(d);
            }
            sort(ALL(my));

            REP(x,KK-K+i+1){
                int count = 0;
                FOR(k,x,my.size()){
                    count += my[k];
                }
                ans = max(ans,count);
                //cout << count << endl;
            }
        }
    }
    ans = max(ans, 0);
    cout << ans << endl;
    return 0;
}