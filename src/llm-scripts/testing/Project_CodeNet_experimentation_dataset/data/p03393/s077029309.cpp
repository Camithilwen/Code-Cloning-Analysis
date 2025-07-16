#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    vector<int> cnt(26,0);
    for(int i = 0; i < s.size(); i++) {
        cnt[s[i]-'a']++;
    }
    if(s.size()==26) {
        int idx=25;
        while(idx>0 && s[idx-1]>s[idx]) idx--;
        if(idx==0) {
            cout << "-1" << "\n";
            return 0;
        }

        char e='z'+1;
        for(int i = idx; i < s.size(); i++) if(s[idx-1]<s[i]) e=min(e,s[i]);
        for(int i = 0; i < idx-1; i++) cout << s[i];
        cout << e << "\n";
    }
    else{
        cout << s;
        int idx=0;
        while(cnt[idx]!=0) idx++;
        cout << char('a'+idx) << "\n";
    }

    return 0;
}