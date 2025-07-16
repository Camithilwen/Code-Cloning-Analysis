#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int main(){
	int N;string A,B,C;cin>>N>>A>>B>>C;
	int ans=0;int a=0;
	rep(i,N){
		if(A.at(i)==B.at(i)){
			a++;
		}
		if(B.at(i)==C.at(i)){
			a++;
		}
		if(C.at(i)==A.at(i)){
			a++;
		}
		if(a==0){
			ans++;
			ans++;
		}else if(a==1){
			ans++;
		}else if(a==3){

		}
		a=0;
	}
	cout<<ans<<endl;
}