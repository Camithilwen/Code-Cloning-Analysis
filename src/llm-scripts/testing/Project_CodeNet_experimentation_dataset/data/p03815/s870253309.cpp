#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll x;
    cin >> x;
    if(x%11==0) cout << 2*x/11;
    else if(x%11<=6) cout << (x/11)*2+1;
    else cout << (x/11)*2+2;
    cout << endl;
}