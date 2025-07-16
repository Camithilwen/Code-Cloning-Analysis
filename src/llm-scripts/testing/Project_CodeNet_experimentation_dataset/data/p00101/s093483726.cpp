#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)

int main(void){
    int n;
    string h = "Hoshino";
    string s;
    cin >> n;
    getline(cin, s);
    stringstream ss(s);
    ss >> n;
    rep(loop, n) {
        getline(cin, s);
        rep(i, s.size()){
            if(i+h.size()-1 >= s.size()) break;
            bool same = true;
            rep(j, h.size()) {
                if(s[i+j]!=h[j]) {
                    same = false;
                    break;
                }
            }
            if(same) s[i+h.size()-1] = 'a';
        }
        cout << s << endl;
    }
}