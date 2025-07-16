#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    bool flag = false;
    for(int i=0;i<s.size();i++){
        if(s[i+1]=='C'&&s[i]=='A'){
            flag = true;
            break;
        }
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}
