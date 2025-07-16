#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;

bool g(ll a,ll b){
    return a>b;
}
int main(){
    string S;
    cin>>S;
    
    set<char> s;
    if(S.length()<26){
        for(ll i=0;i<S.length();++i){
            s.insert(S[i]);
        }
        cout<<S;
        for(ll i=0;i<26;++i){
            if(s.count('a'+i)==0){
                cout<<char('a'+i);
                break;
            }
        }
    }else{
        // string p=S;
        // next_permutation(p.begin(),p.end());
        // cout<<S<<endl;
        // cout<<p<<endl;
        s.insert(S[S.length()-1]);
        for(ll i=S.length()-2;i>=0;--i){
            s.insert(S[i]);
            if(S[i]<S[i+1]){
                S[i]= *s.upper_bound(S[i]);
                S=S.substr(0,i+1);
                cout<<S;
                return 0;
            }
        }
        cout<<-1;
    }
}