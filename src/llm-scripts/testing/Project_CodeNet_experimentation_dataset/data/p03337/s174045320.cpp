#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int a,b;cin>>a>>b;
    int c[3];
    c[0]=a+b;
    c[1]=a-b;
    c[2]=a*b;
    sort(c,c+3);
    cout<<c[2]<<endl;
	return 0;
}