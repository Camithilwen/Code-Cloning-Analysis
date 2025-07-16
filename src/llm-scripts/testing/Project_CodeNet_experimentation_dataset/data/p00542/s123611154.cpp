#include<iostream>
using namespace std;
int main(){
	int a[3],e,f,x,y,z,i;
	cin>>a[0]>>a[1]>>a[2]>>a[3]>>e>>f;
	x=100;
	y=0;
	for(i=0;i<4;i++){
		y=y+a[i];
		if(x>a[i]){
			x=a[i];
		}
	}
	z=y-x;
	if(e>f){
		z=z+e;
	}else{
		z=z+f;
	}
	cout<<z<<endl;
	return 0;
}