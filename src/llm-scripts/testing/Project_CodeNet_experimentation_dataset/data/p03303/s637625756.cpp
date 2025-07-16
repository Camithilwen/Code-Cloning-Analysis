#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
string s;
int w;
int main(void){
    cin>>s>>w;
    for(int i=0;i<s.size();i=i+w){
        cout<<s[i];
    }
    cout<<endl;
    
}
