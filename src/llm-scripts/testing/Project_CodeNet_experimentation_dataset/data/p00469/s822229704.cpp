#include<iostream>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<stdio.h>
#include<stdlib.h>

using namespace std;
int main(){
	int n,k;
	while(cin>>n>>k){
		if(n==0){
			break;
		}

	int d[20]={},cnt[10000]={},c;
	for(int i=0;i<n;i++){
		cin>>d[i];
	}
	if(k==2){
	c=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i!=j){
					if(d[j]>=10){
						cnt[c]+=d[i]*100+d[j];
						
					}
				else{
				cnt[c]+=d[i]*10+d[j];
				
				}
				c++;
				}
			}
		}

	}
	if(k==3){
	c=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i!=j){
				for(int k=0;k<n;k++){
					if(i!=k && j!=k){
						if(d[k]>=10){
							if(d[j]>=10){
								cnt[c]=d[i]*10000+d[j]*100+d[k];
							}
							else{
								cnt[c]=d[i]*1000+d[j]*100+d[k];
							}
						}
						else{
							if(d[j]>=10){
								cnt[c]=d[i]*1000+d[j]*10+d[k];
							}
							else{
								cnt[c]=d[i]*100+d[j]*10+d[k];
							}
						}
					c++;
					}

			}
				}
		}

	}
	}
	if(k==4){
	c=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
			if(i!=j){
				for(int k=0;k<n;k++){
				if(i!=k && j!=k){
					for(int l=0;l<n;l++){
						if(i!=l && j!=l && k!=l){
					if(d[l]>=10){
						if(d[k]>=10){
							if(d[j]>=10){
								cnt[c]=d[i]*1000000+d[j]*10000+d[k]*100+d[l];
							}
							else{
								cnt[c]=d[i]*100000+d[j]*10000+d[k]*100+d[l];
							}
						}
						else{
							if(d[j]>=10){
								cnt[c]=d[i]*100000+d[j]*1000+d[k]*100+d[l];
							}
							else{
								cnt[c]=d[i]*10000+d[j]*1000+d[k]*100+d[l];
							}
						}
					}
					else{
						if(d[k]>=10){
							if(d[j]>=10){
								cnt[c]=d[i]*100000+d[j]*1000+d[k]*10+d[l];
							}
							else{
								cnt[c]=d[i]*10000+d[j]*1000+d[k]*10+d[l];
							}
						}
						else{
							if(d[j]>=10){
								cnt[c]=d[i]*10000+d[j]*100+d[k]*10+d[l];
							}
							else{
								cnt[c]=d[i]*1000+d[j]*100+d[k]*10+d[l];
							}
						}
					}
					c++;
				}
					}
				}
				}
			}
			}
			}
		
	}
	sort(cnt,cnt+c+1,greater<int>());
	int ans=0;
	for(int i=0;i<c;i++){
		if(cnt[i]>cnt[i+1]){
				ans++;
		}
	}
	cout<<ans<<endl;
	}
	return 0;
	}