#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000001
//0=48,A=65,a=97

int main() {
    int n;cin >> n;
    string s,t;cin >> s >>t;
    string m;
    for(int i = 0; i < n; i++) {
        bool x=true;
        string y;
        for(int j = i; j < n; j++) {
            if(s[j]==t[j-i]) y += s[j];
            else{
                x=false;
                break;
            }
        }
        if(x){
            m=y;
            break;
        }
    }

    cout << 2*n-m.size() << endl;
    

    return 0;
}