#include <bits/stdc++.h>
#define rep(i, n)  for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int numOf1s(ll bit){
    int cnt = 0;
    while(bit){
        if(bit & 1 == 1) ++cnt;
        bit = bit >> 1;
    }
    return cnt;
}

int main(){
    int N; cin >> N;
    vector<vector<P>> vec(N);
    rep(i, N){
        int a; cin >> a;
        rep(j, a){
            int x,y; cin >> x >> y;
            --x;
            vec[i].push_back(P(x,y));
        }
    }

    int result = 0;
    for(ll bit=0; bit < (1<<N); ++bit){
        bool valid = true;
        for(int i=0; i<N; ++i){
            if((bit >> i & 1) != 1) continue;
            for(auto p : vec[i]){
                if(p.second != (bit >> p.first & 1)){
                    valid = false;
                }
            }
        }
        if(valid) result = max(result, numOf1s(bit));
    }
    cout << result << endl;
}
