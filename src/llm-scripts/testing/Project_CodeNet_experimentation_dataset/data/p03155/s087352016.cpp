#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    int n,h,w;
    cin>>n>>h>>w;
    cout<<max(0,(n-h+1)*(n-w+1))<<endl;
    return 0;
}