#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    int n,l;
    cin>>n>>l;
    int mini;
    if(l>=0) mini=l;
    else if(n+l-1<=0) mini=n+l-1;
    else mini=0;
    cout<<(l+n+l-1)*n/2-mini;
}