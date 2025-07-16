#include <bits/stdc++.h>
#define rep(i,l,n) for(int i=l;i<n;i++)
#define o(a) cout<<a<<endl
using namespace std;

int main(){
	int a;
	while(scanf("%d",&a)!=EOF){
		int d[14]={},p=0,m=0;
		char c;
		vector<int> n(5);
		n[0]=a;
		d[n[0]]++;
		rep(i,1,5){
			cin>>c>>n[i];
			d[n[i]]++;
		}
		sort(n.begin(),n.end());
		rep(i,1,14){
			m=max(m,d[i]);
			if(d[i]>=2) p++;
		}
		if(m==4){
			o("four card");
		}else if(m==3 && p==2){
			o("full house");
		}else if(m==3){
			o("three card");
		}else if(p==2){
			o("two pair");
		}else if(p==1){
			o("one pair");
		}else{
			bool f=1;
			rep(i,0,4){
				if(n[i+1]!=n[i]+1 && !(n[0]==1 && n[1]==10 && n[4]==13)){
					f=0; break;
				}
			}
			if(f) o("straight");
			else o("null");
		}
	}
}