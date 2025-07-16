#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

string station = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int n;
int main() {
    while(cin>>n) {
        if(n==0) return 0;
        vector<int> vec(n);
        rep(i,n) {
            int a; cin>>a;
            vec[i]=a;
        }
        string ss;
        cin>>ss;
        rep(i,ss.size()) {
            int a = i % vec.size();
            int t = station.find(ss[i])-vec[a];
            if(t<0) t += station.size();
            t %= station.size();
            cout<<station[t];
        }
        cout<<endl;

    }

    return 0;
}