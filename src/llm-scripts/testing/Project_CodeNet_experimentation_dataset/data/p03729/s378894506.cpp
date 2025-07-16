#include<bits/stdc++.h>
using namespace std;

#define Bye return 0
#define ll long long
const ll MAX = 1e2;

void solve(){
    string a, b, c; cin>>a>>b>>c;
    int size_a = a.size(), size_b = b.size();
    cout<<(a[size_a-1] == b[0] && b[size_b-1] == c[0] ?  "YES" : "NO")<<endl; 
}

int main(){
    solve();
    Bye;
}