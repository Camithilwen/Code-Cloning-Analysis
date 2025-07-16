#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    vector<int> cnt(26,0);

    for(int i=0; i<s.size(); i++){
        cnt[s[i] - 'a']++;
    }

    string ans;

    if(s.size() != 26){
        ans = s;
        for(int i=0; i<26; i++){
            if(cnt[i] == 0){
                ans += (char)('a'+i);
                break;
            }
        }
    }

    else{

        if(s == "zyxwvutsrqponmlkjihgfedcba") ans = "-1";

        else{
            string tmp = s;
            next_permutation(s.begin(),s.end());

            ans = "";

            for(int i=0; i<s.size(); i++){
                ans += s[i];
                if(s[i] > tmp[i]) break;
            }
        }
    }
    
    cout<<ans<<endl;

    return 0;
}