#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
	while(1){
		int n,a,u[10]={0,1,2,3,4,5,6,7,8,9},p[10]={};
		cin >> n;
		if(n==0)return 0;
		for(int i=0;i<n;i++){
			cin >> a;
			for(int i=0;i<10;i++){
				if(a==u[i])p[i]=p[i]+1;
				/*cout << "p["<< i << "]=" << p[i];*/ 
			}
			/*cout << endl;*/
		}
		/*for(int i=0;i<10;i++){
			cout << "p["<< i << "]=" << p[i]; 
		}*/
		for(int r=0;r<10;r++){
			if(p[r]==0){cout << "-";}
			else if(p[r]!=0){
				for(int i=0;i<p[r];i++){
					cout << "*";
				}
			}
			cout << endl;
		}

	}
	return 0;
}