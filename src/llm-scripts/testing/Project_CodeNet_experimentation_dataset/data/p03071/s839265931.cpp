#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long ;
int main(){
    int a,b;
    cin >> a >> b;
    int ans=0;
    if(a>b) cout << 2*a-1 << endl;
    else if(a<b) cout << 2*b-1 << endl;
    else cout << 2*a << endl;
}