#include<iostream>
using namespace std;
int main(){
	int n,a,b,c=0,max=0,x;
	cin >> n;
	if(n==2)cin >> a >> b ;
	else if(n==3)cin >> a >> b >> c ;
	if(n==2){
		if(a<b){
			x=a;a=b;b=x;
		}
	}
	if(n==3){
		if(a<b){
			x=a;a=b;b=x;
		}
		if(b<c){
			x=b;b=c;c=x;
		}
		if(a<b){
			x=a;a=b;b=x;
		}
	}
	for(int i=0;i<a;i++){
		if(a%(i+1)==0&&b%(i+1)==0&&c%(i+1)==0){
			cout << i+1 <<endl;
		}

	}
	return 0;
}