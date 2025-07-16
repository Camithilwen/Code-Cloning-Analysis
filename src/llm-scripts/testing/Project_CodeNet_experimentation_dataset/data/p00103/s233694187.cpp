#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#define PI 3.141592653589793
using namespace std;
int main(){
	int n;
	string str;
	cin>>n;
	for(int i=0;i<n;i++){
		int cnt=0,num=0;
		int rui[5]={0};
		while(cin>>str){
			if(str=="HIT"){
				rui[4]=rui[3];
				rui[3]=rui[2];
				rui[2]=rui[1];
				rui[1]=1;
				if(rui[4]==1){
					rui[4]=0;
					cnt++;
				}
			}else if(str=="HOMERUN"){
				for(int j=1;j<=3;j++){
					if(rui[j]==1){
						rui[j]=0;
						cnt++;
					}
				}
				cnt++;
			}else{
				num++;
				if(num==3)break;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}