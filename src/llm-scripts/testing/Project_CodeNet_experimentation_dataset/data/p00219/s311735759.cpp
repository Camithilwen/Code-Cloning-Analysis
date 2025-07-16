#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,t;
	while(cin>>n,n){
		int c[10];fill(c,c+10,0);
		for(int i=0;i<n;i++)cin>>t,c[t]++;
		for(int i=0;i<10;i++){if(!c[i])cout<<'-';else for(int j=0;j<c[i];j++)cout<<'*';cout<<endl;}
	}
}