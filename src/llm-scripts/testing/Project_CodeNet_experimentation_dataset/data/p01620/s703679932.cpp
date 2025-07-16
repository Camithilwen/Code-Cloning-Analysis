#include <bits/stdc++.h>
using namespace std;
#define lp(i,n) for(int i=0;i<n;i++)

int main(){
	while(1){
		int n;
		cin>>n;
		if(n==0) break;
		int a[100];
		lp(i,n){
			cin>>a[i];
		}
		int count=0;
		char x;
		scanf("%c",&x);
		while(1){
			scanf("%c",&x);
			if('A'<=x&&'z'>=x){
				lp(i,a[count]){
					x--;
					if(x==64) x=122;
					if(x==96) x=90;
				}
				cout<<x;
				count++;
				if(count==n) count=0;
			}
			else break;
		}
		cout<<endl;
	}
	return 0;
}
