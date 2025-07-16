#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
   string s;cin >>s;
   int n=s.size();
   vector<int>cnt(26,0);
    for (int i = 0; i < n; ++i) {
        cnt[s[i]-'a']++;
    }
    string ans;
    char nx;
    for (int i = 0; i < 26; ++i) {
        if(cnt[i]==0){
            nx=(char)('a'+i);
            break;
        }
    }
    if(s.size()!=26){
        ans=s+nx;
        cout <<ans <<endl;
    }
    else {
        ll mx=-1;
        reverse(all(s));
        int k=-1;
        vector<char>f;
        for (int i = 0; i < n; ++i) {
            if(mx>s[i]-'a'){
//                for (int i = 0; i < f.size(); ++i) {
//                    cout <<f[i]<<" ";
//                }
                int key=lower_bound(all(f),s[i])-f.begin();
                s[i]=f[key];
                k=n-i;
                break;
            }
            else {
                mx=s[i]-'a';
                f.push_back(s[i]);
            }
        }
        reverse(all(s));
        if(k>0){
            cout <<s.substr(0,k)<<endl;
        }
        else cout <<-1<<endl;
    }
}
