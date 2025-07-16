#include<iostream>
using namespace std;

char getAns(int m,int e,int j){
	if(m==100||e==100||j==100)return 'A';
	if((m+e)/2>=90)return 'A';
	if((m+e+j)/3>=80)return 'A';
	if((m+e+j)/3>=70)return 'B';
	if((m+e+j)/3>=50&& (m>=80||e>=80))return 'B';
	return 'C';

}
int main(){
	int d;
	while(cin>>d){
		int pm,pe,pj;
		for(;d>0;d--){
			cin>>pm>>pe>>pj;
			cout<<getAns(pm,pe,pj)<<endl;
		}
	}
}