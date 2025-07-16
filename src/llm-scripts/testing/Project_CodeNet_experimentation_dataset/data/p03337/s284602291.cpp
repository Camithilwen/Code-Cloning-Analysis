#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int a,b;
    cin>>a>>b;
    int c=a+b,d=a-b,e=a*b;
    c=max(c,d);
    c=max(c,e);
    cout<<c<<endl;
}
