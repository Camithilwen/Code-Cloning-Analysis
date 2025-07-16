#include <bits/stdc++.h>
using namespace std;

#define int long long
struct Fast {Fast(){cin.tie(0);ios::sync_with_stdio(0);}} fast;
//const int MOD = 1e9 + 7;
using intpair = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define ceiv(a, b) ((int)((a) + (b) - 1)/(int)(b))

signed main(){
    int k;
    cin >> k;
    
    vector<string> board(8,string(8,'.'));
    vector<intpair> queen(k);
    
    rep(i,k){
        cin >> queen[i].first >> queen[i].second;
    }
    
    int a[8];
    rep(i,8) a[i] = i;
    
    do{
        bool ok = true;
        for(auto p : queen){
            ok = false;
            rep(i,8){
                if(p.first == i && p.second == a[i]) ok = true;
            }
            if(!ok) break;
        }
        
        rep(i,8)rep(j,8){
            if(i==j) continue;
            if(i+a[i] == j+a[j]) ok = false;
            if(i-a[i] == j-a[j]) ok = false;
        }
        
        if(ok){
            rep(i,8){
                board[i][a[i]] = 'Q';
            }
            break;
        }
    }while(next_permutation(a, a+8));
    
    for(string s : board){
        cout << s << endl;
    }
}
