#include <iostream>
using namespace std;
int sports[1001];
int money,ans,maxvote,n,m,k;
int vote[1001];
int main(){
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >>sports[i];
	}
	for(int i=1;i<=m;i++){
		cin >> money;
		k=1;
		while(money<sports[k]){
			k++;
		}
		vote[k]++;
	}
	ans=1;
	maxvote=0;
	for(int i=1;i<=n;i++){
		if(vote[i]>maxvote){
			maxvote=vote[i];
			ans=i;
		}
	}
	cout << ans<<endl;
	return 0;
}