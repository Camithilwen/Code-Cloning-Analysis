#include<stdio.h>
#include<iostream>
using namespace std;
int main(void){
	int n,a[4],t[100],i,c,j;
		cin>>n;
	for(i=0;i!=n;i++){
		t[i]=0;
	}
		for(i=0;i!=n*(n-1)/2;i++){
			for(j=0;j!=4;j++)
				cin>>a[j];
			if(a[2]<a[3])
				t[a[1]-1]+=3;
			else if(a[2]>a[3])
				t[a[0]-1]+=3;
			else{
				t[a[0]-1]++;
				t[a[1]-1]++;
			}
		}
	for(i=0;i!=n;i++){
		c=1;
		for(j=0;j!=n;j++){
			if(t[i]<t[j])
				c++;
		}
		cout<<c<<endl;
	}
}