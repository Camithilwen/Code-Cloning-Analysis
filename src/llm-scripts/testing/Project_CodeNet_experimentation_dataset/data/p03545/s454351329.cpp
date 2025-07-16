#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
	int a[5];
	char ans[5];
	string b;
	cin>>b;
	for(int i=0;i<4;i++){
		a[i]=b[i]-'0';
		ans[i]='+';
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			int sum=0;
			for(int k=0;k<4;k++){
				if(k==i  && k!=0 || k==j && k!=0){
					sum-=a[k];
				}
				else{
					sum+=a[k];
				}
			}
			if(sum==7){
				ans[i]='-';
				ans[j]='-';
				cout<<a[0]<<ans[1]<<a[1]<<ans[2]<<a[2]<<ans[3]<<a[3]<<"="<<"7"<<endl;
				return(0);
			}
		}
	}
	
    return(0);
}