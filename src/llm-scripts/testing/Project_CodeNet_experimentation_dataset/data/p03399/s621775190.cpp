#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i < (int)n;++i)

int main() {
    int a[4];
    rep(i,4)cin>>a[i];
    cout<<min(a[0], a[1])+min(a[2], a[3])<<endl;
	return 0;
}