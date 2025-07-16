#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int main(){
	int n,dum;
	vector<int> p;
	
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&dum);
		p.push_back(dum);
	}
	sort(p.begin(),p.end());
	if(n==2){
		for(int i=1;i<=p[0];i++){
			if(p[0]%i==0&&p[1]%i==0)
			printf("%d\n",i);
		}
	}
	else{
		for(int i=1;i<=p[0];i++){
			if(p[0]%i==0&&p[1]%i==0&&p[2]%i==0)
			printf("%d\n",i);
		}
	}
}
