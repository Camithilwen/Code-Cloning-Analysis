#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int N=1e5+2;
pair<int,pair<int,int> > ar[N];
pair<int,int> wow[N];
int sum[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,x,i,j,k,l=0,val,val1,max1;
	int lef=0,rig=0,mid;
	cin>>n>>x;
	for(i=1;i<=n;i++){
		cin>>ar[i].first>>ar[i].second.first>>ar[i].second.second;
		rig+=ar[i].first;
		l+=-ar[i].first*ar[i].second.first;
		wow[i].first=ar[i].first*(ar[i].second.first-ar[i].second.second)+x*ar[i].second.second;
		wow[i].second=i;
	}
	sort(wow+1,wow+1+n,[&](pair<int,int> cac,pair<int,int> cac1){
		return cac.first>cac1.first;
	});
	for(i=1;i<=n;i++){
		sum[i]=sum[i-1]+wow[i].first;
	}
	while(rig>lef){
		mid=(lef+rig)/2;
		val=mid/x;
		val1=mid%x;
		max1=sum[val];
		for(i=1;i<=n;i++){
			j=wow[i].second;
			if(i<=val){
				if(val1>ar[j].first){
max1=max(max1,sum[val+1]-wow[i].first+ar[j].first*(ar[j].second.first-ar[j].second.second)+val1*ar[j].second.second);
				}
				else{
					max1=max(max1,sum[val+1]-wow[i].first+val1*ar[j].second.first);
				}
			}
			else{
				if(val1>ar[j].first){
				max1=max(max1,sum[val]+ar[j].first*(ar[j].second.first-ar[j].second.second)+val1*ar[j].second.second);
				}
				else{
					max1=max(max1,sum[val]+val1*ar[j].second.first);
				}
			}
		}
		if(max1+l>=0){
			rig=mid;
		}
		else{
			lef=mid+1;
		}
	}
	cout<<rig;
}