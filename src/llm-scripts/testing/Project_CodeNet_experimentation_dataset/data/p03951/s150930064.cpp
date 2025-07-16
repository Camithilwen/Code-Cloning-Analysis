#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    string s; cin >> s;
    string t; cin >> t;

    int cnt=0;
    bool flg = false;
    for(int i=0; i<s.length(); i++){
        string s_sub = s.substr(i, s.length()-i);
        for(int j=0; j<t.length(); j++){
            string t_sub = t.substr(0, t.length()-j);
                if(s_sub==t_sub){
                    cnt = s_sub.length();  flg = true;
                    break;
                }
            }
        
        if(flg) break;
    }
    string res = s + t.substr(cnt, t.length()-cnt);
    int ans = res.length();
    cout << ans << endl;
    return 0;

}