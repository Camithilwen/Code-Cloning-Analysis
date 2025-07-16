#include <bits/stdc++.h>
using namespace std;

int a[1010],p[1010];

int main(){
	int N,M,l,max=0,r;
	cin>>N>>M;
	for(int i=0;i<N;i++) cin>>a[i];
	for(int i=0;i<M;i++){
		cin>>l;
		for(int j=0;j<N;j++){
			if(a[j]<=l){
				p[j]++;
				break;
			}
		}
	}
	for(int i=0;i<N;i++){
		if(max<p[i]){
			max=p[i];
			r=i+1;
		}
	}
	cout<<r<<endl;
	return 0;
}
