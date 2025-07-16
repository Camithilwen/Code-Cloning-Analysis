#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(ll)n;i++)

int main(){
    string s; cin >> s;
    rep(i,3){
        if(s[i] == '7'){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}