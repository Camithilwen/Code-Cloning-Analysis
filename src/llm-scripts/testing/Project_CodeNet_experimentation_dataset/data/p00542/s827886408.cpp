#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
	int a[4],e,f,sum=0,x=120;
	for(int i=0;i<4;i++){
	cin >> a[i];
	sum=sum+a[i];
	if(a[i]<x)x=a[i];
	}
	sum=sum-x;
	cin >> e;
	cin >> f;
	if(e>f){sum=sum+e;}
	else if(e<f){sum=sum+f;}
	else if(e==f){sum=sum+e;}
	cout << sum << endl;
	return 0;
}