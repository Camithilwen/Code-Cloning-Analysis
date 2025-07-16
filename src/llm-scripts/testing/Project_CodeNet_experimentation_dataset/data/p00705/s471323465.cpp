#include<iostream>
using namespace std;
int main(void){
	int date[100];
	int n,q;
	int i,j;
	
	while(cin>>n>>q,(n||q)){
		for(i=0;i<100;i++)date[i]=0;

		for(i=0;i<n;i++){
			int m;
			cin>>m;
			for(j=0;j<m;j++){
				int d;
				cin>>d;
				date[d]++;
			}
		}
		int max=0;
		for(i=0;i<100;i++){
			if(date[i]>date[max]){
				max=i;
			}
		}
		if(date[max]>=q){
			cout<<max<<endl;
		}else{
			cout<<0<<endl;
		}
	}
	return 0;
}