#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
int n, m;
int main(){
	scanf("%d%d", &n, &m);
	rep(i,m) printf("%d %d\n", i+1, n-i-(~n&1 && n<=i*4+2));
}