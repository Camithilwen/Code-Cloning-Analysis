#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    cin >> s;

    char cbuff='a';
    rep(i,26) {
        cbuff='a'+i;
        string::size_type pos=s.find(cbuff);
        if (pos==string::npos) {
            cout << cbuff << endl;
            return 0;
        }
    }

    cout << "None" << endl;
    return 0;
}