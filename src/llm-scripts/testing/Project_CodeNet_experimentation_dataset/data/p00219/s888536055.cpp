#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstdio>
#include<string>
#include<cmath>
typedef long long int ll;
#define VI vector<int>

#define rep(i,a) for(int i=0;i<(a);i++)

int n,m;

using namespace std;


int main(){
	while(1){
		int num[10]={};
		int a=0;
		cin>>a;
		if(a==0)break;
		for(int cou=0;cou<a;cou++){
			int n;
			cin>>n;
			num[n]++;
		}
		rep(i,10){
			if(num[i]==0)cout<<"-"<<endl;
			else{
				rep(j,num[i])cout<<"*";
				cout<<endl;
			}
		}
	}
	return 0;
}