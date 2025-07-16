#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int data[100];

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n * (n - 1) / 2; i++){
		int b[4];
		for(int k=0;k<4;k++) scanf("%d",&b[k]);
		if(b[2]>b[3]) data[b[0]-1]+=3;
		if(b[2]<b[3]) data[b[1]-1]+=3;
		if(b[2]==b[3]){ data[b[0]-1]++; data[b[1]-1]++; }
	}
	for(int i=0;i<n;i++){
		int res=1;
		for(int j=0;j<n;j++){
			if(data[i]<data[j]) res++;
		}
		printf("%d\n",res);
	}
}