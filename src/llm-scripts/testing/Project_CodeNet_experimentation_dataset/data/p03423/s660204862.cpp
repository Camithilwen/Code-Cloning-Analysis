#include<iostream>
using namespace std; 
int main(){
	int a,b=0;
	cin>>a;
	if(a%3==0 && a>0){
		b=(a/3)+b;
		
	}
	else if(a%3==1 && a>1){
		a-=4;
		b++;
		b=(a/3)+b;
	}
	else if(a%3==2 && a>2){
		a-=5;
		b++;
		b=(a/3)+b;
	}
	else{
		system("pause");
	}
	cout<<b;
}