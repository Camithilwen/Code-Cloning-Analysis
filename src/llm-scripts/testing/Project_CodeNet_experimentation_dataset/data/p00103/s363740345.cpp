#include<iostream>
using namespace std;

int main(){
	int n,cnt=0,num=0;
	int base[4]={0};
	cin>>n;
	string s;
	while(1){
		cin>>s;
		if(s=="HIT"){
			base[3]+=base[2];
			base[2]=base[1];
			base[1]=base[0];
			base[0]=1;
		}
		if(s=="HOMERUN"){
			for(int i=0;i<3;i++){
				base[3]+=base[i];
				base[i]=0;
			}
			base[3]++;
		}
		if(s=="OUT"){
			cnt++;
		}
		if(cnt==3){
			cout<<base[3]<<endl;
			cnt=0;
			num++;
			base[0]=base[1]=base[2]=base[3]=0;
		}
		if(num==n)break;
	}
	return 0;
}