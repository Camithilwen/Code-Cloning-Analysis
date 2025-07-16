#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+2;
int ar[N],num[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,i,j,k,l,r,s,ans=0,lst=-1;
	cin>>n>>s;
	for(i=1;i<=n;i++){
		cin>>ar[i]>>num[i];
	}
	l=1;
	r=n;
	while(true){
		if(ar[r]<s){
			ans+=s-ar[l];
			break;
		}
		if(ar[l]>s){
			ans+=ar[r]-s;
			break;
		}
		if(num[l]>=num[r]){
			num[l]+=num[r];
			if(lst!=l){
				ans+=ar[r]-ar[l];
			}
			r--;
			lst=l;
		}
		else{
			num[r]+=num[l];
			if(lst!=r){
				ans+=ar[r]-ar[l];
			}
			l++;
			lst=r;
		}
	}
	cout<<ans;
}