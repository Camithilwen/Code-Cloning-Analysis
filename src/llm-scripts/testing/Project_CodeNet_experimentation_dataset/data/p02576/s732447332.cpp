#include<iostream>
#include<string>
using namespace std;
int main(){
int a,b,c,i,d;
cin>>a>>b>>c;
i=c;
d=b;
while(a>b){
	b=b+d;
    c=c+i;
    }
	cout<<c;
}
