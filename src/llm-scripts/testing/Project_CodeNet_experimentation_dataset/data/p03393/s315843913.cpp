#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    vector<bool> a(26,false);
    string s; cin >> s;
    if(s.size()<26){
        for(int i = 0; i < s.size(); i++) {
            a[(int)s[i]-97]=true;
        }
        for(int i = 0; i < 26; i++) {
            if(a[i]==false){
                s += (char)(97+i);
                cout << s << endl;
                return 0;
            }
        }
    }
    else{
        if(s=="zyxwvutsrqponmlkjihgfedcba"){
            cout << -1 << endl;
            return 0;
        }
        string t=s;
        string ans;
        next_permutation(t.begin(),t.end());
        for(int i = 0; i < 26; i++) {
            ans += t[i];
            if(s[i]!=t[i]) break;
        }
        cout << ans << endl;
        
    }

    return 0;
}