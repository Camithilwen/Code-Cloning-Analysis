#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,h,w; scanf("%d%d%d",&n,&h,&w);
	printf("%d\n",(n-h+1)*(n-w+1));
	return 0;
}
