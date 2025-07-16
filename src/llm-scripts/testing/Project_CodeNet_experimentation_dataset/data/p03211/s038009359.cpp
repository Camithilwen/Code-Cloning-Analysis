#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=unsigned long long;
using namespace std;

int main() {
    string s;
    cin>>s;
    int minv=1000000005;
    size_t l=s.length();
    rep(i,l-2){
        string ss=s.substr(i,3);
        int num=stoi(ss);
        minv=min(minv,abs(num-753));
    }
    cout<<minv<<"\n";
    return 0;
}