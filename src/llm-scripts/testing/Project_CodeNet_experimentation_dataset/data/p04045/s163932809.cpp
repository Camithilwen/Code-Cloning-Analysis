#include<iostream>
using namespace std;
const int N=2e5+10;
int n,k;
int d[N];
int hs(int x){
	int f=0;
	while(x>0){
		if(d[x%10]) f=1;
		x/=10;
	}
	if(f) return 0;
	else return 1;
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		d[x]=1;
	}
	for(int i=n;;i++)
		if(hs(i)){
			printf("%d",i);
			break;
		}
	return 0;
}