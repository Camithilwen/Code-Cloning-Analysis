#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<ll, ll>;
/* ちゃんと考えてわかって実装 */

int main(void){
    ll d, g;
    cin >> d >> g;
    vector<P> pc;
    for(int i=0; i<d; i++){
        ll tmpp, tmpc;
        cin >> tmpp >> tmpc;
        pc.push_back(P(tmpp, tmpc));
    }

    ll ans = 10000000000000000;
    for(int i=0; i<(1<<d); i++){
        ll tmp_ans = 0;
        ll tmp_score = 0;
        priority_queue<ll> mada;
        for(int j=0; j<d; j++){
            if(i>>j & 1){
                tmp_ans += pc[j].first;
                tmp_score += 100 * (j+1) * pc[j].first;
                tmp_score += pc[j].second;
            }
            else{
                for(int k=0; k<pc[j].first-1; k++){
                    mada.push(100 * (j+1));
                }
            }
        }
        while(tmp_score < g && !mada.empty()){
            tmp_score += mada.top();
            mada.pop();
            tmp_ans++;
        }
        if(tmp_score >= g){
            ans = min(ans, tmp_ans);
        }
    }
    cout << ans << endl;
    return 0;
}