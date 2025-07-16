#include <bits/stdc++.h>
using namespace std;
long long INF = 1e18;
int main(){
    long long d, g;
    cin >> d >> g;
    vector<long long> p(d), c(d), score(d);
    for(int i = 0; i < d; i++) {
        cin >> p[i] >> c[i];
        score[i] = (i + 1) * 100;
    }
    long long ans = INF;
    for(int bit = 0; bit < (1 << d); bit++){
        long long G = g;
        long long res = 0;
        vector<int> flag(d, 1);
        for(int i = 0; i < d; i++){
            if(bit & (1 << i)) {
                G -= p[i]*score[i] + c[i];
                flag[i] = 0;
                res += p[i];
            }
        }
        int t = -1;
        for(int j = 0; j < d; j++){
            if(flag[j] == 1) t = j;
        }
        if(G > 0 && G <= p[t] * score[t] + c[t]){
            res += min(p[t], (G + score[t] - 1) / score[t]);
            ans = min(res, ans);
        }
        else if(G <= 0) ans = min(res, ans);
    }
    cout << ans << endl;
}
