#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;

int n,k,d[10];

int sum(int a,int b,int c=0,int d=0){
	int x=a*(b>=10?100:10)+b;
	if(k==2)return x;
	x=x*(c>=10?100:10)+c;
	if(k==3)return x;
	return x=x*(d>=10?100:10)+d;
}

int main(){
	while(scanf("%d%d",&n,&k),n){
		for(int i=0;i<n;i++)scanf("%d",&d[i]);
		sort(d,d+n);
		vector<int> data;
		for(int i=n-1;i>=0;i--){
			for(int j=n-1;j>=0;j--){
				if(i==j)continue;
				if(k==2){
					data.push_back(sum(d[i],d[j]));
					continue;
				}
				for(int r=n-1;r>=0;r--){
					if(i==r||j==r)continue;
					if(k==3){
						data.push_back(sum(d[i],d[j],d[r]));
						continue;
					}
					for(int z=n-1;z>=0;z--){
						if(i==z||j==z||r==z)continue;
						data.push_back(sum(d[i],d[j],d[r],d[z]));
					}
				}
			}
		}
		sort(data.begin(),data.end());
		data.erase(unique(data.begin(),data.end()),data.end());
		printf("%ld\n",data.size());
	}
}