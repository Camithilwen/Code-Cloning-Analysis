#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, b, c; cin >> a >> b >> c;
    bool ok = true;
    if(a==b && b!=c){ok = false;}
    if(b==c && c!=a){ok = false;}
    if(c==a && a!=b){ok = false;}
    if(!ok){cout << "Yes" << endl;}
    else cout << "No" << endl;
    return 0;
}