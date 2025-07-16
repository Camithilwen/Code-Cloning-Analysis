#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
int main(void){
    string s;
    cin>>s;
    int n=s.size();
    bool ok=false;
    int L=-1,R=-1;
    if(n==2&&s[0]==s[1]){
        L=1,R=2;
    }
    for(int i=0;i<n-2;i++){
        if(s[i]==s[i+1]||s[i+1]==s[i+2]||s[i+2]==s[i]){
            L=i+1,R=i+3;
        }
    }
    cout<<L<<" "<<R<<endl;
}