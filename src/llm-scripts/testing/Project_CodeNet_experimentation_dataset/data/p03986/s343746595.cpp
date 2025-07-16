#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

template<typename T>
istream& operator>> (istream& is, vector<T> &vec){
    for(T& x: vec) is >> x;
    return is;
}

int main(){
    string s; cin >> s;
    ll length = s.length();
    reverse(s.begin(), s.end());
    ll tcnt = 0;
    rep(i, s.length()){
        if(s[i] == 'S') {
            if(tcnt > 0){
                length -= 2;
                tcnt--;
            }
        }else{
            tcnt++;
        }
    }
    cout << length << endl;
    return 0;
}