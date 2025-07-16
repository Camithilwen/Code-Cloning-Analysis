#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int main(){
    string t("2018"),s;
    
    rep(i,10){
        char c; cin >> c;
        if(i>=0 && i<=3){
            cout << t[i];
        }else{
            cout << c;
        }
    }

    cout << endl;

    return 0;
}