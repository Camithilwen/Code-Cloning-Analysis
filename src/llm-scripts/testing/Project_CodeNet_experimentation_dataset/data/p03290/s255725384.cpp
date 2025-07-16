#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> pii;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
#define all(a) a.begin(), a.end()

const int MOD = 1e9+7;
const int INF = 1e9;

int main(){
    int D, G;
    cin >> D >> G;
    vector<pii> points;
    rep(i, 0, D){
        int p, c;
        cin >> p >> c;
        points.push_back(make_pair(p, c));
    }
    int ans = INF;
    rep(i, 0, 1<<D){
        ll score = 0;
        int cnt = 0;
        int last, prob;
        rep(j, 0, D){
            if ((i>>j)&1){
                score += points[j].first * (j+1) * 100 + points[j].second;
                cnt += points[j].first;
            }
            else{
                last = j;
                prob = points[j].first;
            }
        }
        while (score < G && prob > 1){
            score += (last+1) * 100;
            cnt++;
            prob--;
        }
        if (score >= G){
            ans = min(ans, cnt);
        }
    }
    cout << ans << endl;
}