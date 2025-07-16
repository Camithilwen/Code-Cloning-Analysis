#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,k; scanf("%d%d%d",&a,&b,&k);
	rep(i,k){
		if(i%2==0){
			if(a%2==1) a--;
			b+=a/2;
			a/=2;
		}
		else{
			if(b%2==1) b--;
			a+=b/2;
			b/=2;
		}
	}
	printf("%d %d\n",a,b);
	return 0;
}
