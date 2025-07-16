#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
// using ll = long long;
// using P = pair<int, int>;

int main() {
    int k;
    cin >> k;
    vector<pair<int, int> > in(k);
    rep(i, k) cin >> in[i].first >> in[i].second;
    
    
    vector<int> p(8);
    rep(i, 8) p[i] = i;
    
    do{
        bool check = true;
        rep(i, k){
            if(p[in[i].first] != in[i].second){
                check = false;
                break;
            }
        }
        if(!check) continue;
        
        bool flag = true;
        rep(i, 7){
            // (1, 1)方向チェック
            for(int j = i + 1; j < 8; ++j){
                int r_dif = j - i;
                int l_dif = p[i] + r_dif;
                if(l_dif == p[j]) flag = false;
            }
            // (1, -1)方向チェック
            for(int j = i + 1; j < 8; ++j){
                int r_dif = j - i;
                int l_dif = p[i] - r_dif;
                if(l_dif == p[j]) flag = false;
            }
        }
        if(flag) break;
    }while(next_permutation(p.begin(), p.end()));
    
    rep(i, 8){
        rep(j, 8){
            if(p[i] == j){
                cout << "Q";
            }else{
                cout << ".";
            }
        }
        cout << endl;
    }
    
    return 0;
}
