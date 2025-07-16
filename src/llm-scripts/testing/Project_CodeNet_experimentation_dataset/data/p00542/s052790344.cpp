//2015
#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
int main(void){
	int i,ad[4]={0},e=0,f=0,sum=0;
	for(i=0;i<4;i++){
		cin>>ad[i];
	}
	cin>>e;
	cin>>f;
	sort(ad,ad+4,greater<int>());//降順,昇順＝＝sort(ad,ad+4);
	for(i=0;i<3;i++){
		sum+=ad[i];
	}
	if(e<f){
		sum+=f;
	}
	else{
		sum+=e;
	}
	cout<<sum<<endl;
	return 0;
}
