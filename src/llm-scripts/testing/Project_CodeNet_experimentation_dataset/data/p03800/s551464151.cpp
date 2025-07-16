#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
typedef long long ll;
bool check(int m, char c, int l, int r){
    bool res = true;
    if(m == 0){
        if(c == 'o'){
            if(l != r) res = false;
        }else{
            if(l == r) res = false;
        }
    }else{
        if(c == 'o'){
            if(l == r) res = false;
        }else{
            if(l != r) res = false;
        }
    }
    return res;
}

int main(){
    int n; cin >> n;
    string s; cin >> s;
    string v[4] = {"00", "01", "10", "11"};
    rep(i,4){
        vector<int> t(n);
        rep(j,2) t[j] = (v[i][j] == '0') ? 0 : 1;

        FOR(k, 1, n-1){
            if(t[k] == 0){
                if(s[k] == 'o'){
                    t[k+1] = t[k-1];
                }else{
                    t[k+1] = 1-t[k-1];
                }
            }else{
                if(s[k] == 'o'){
                    t[k+1] = 1-t[k-1];
                }else{
                    t[k+1] = t[k-1];
                }
            }
        }

        if(!check(t[n-1], s[n-1], t[n-2], t[0])) continue;
        if(!check(t[0], s[0], t[n-1], t[1])) continue;

        rep(l, n) printf("%c", t[l] == 0 ? 'S' : 'W');
        cout << endl;
        return 0;
    }

    cout << "-1" << endl;
    return 0;
}