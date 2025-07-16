#include <bits/stdc++.h>
using namespace std;
int main() {
	char str;
	int n[3]={},ans=0,x;
	while(cin>>str){
		if(str=='J'&&n[1]==0&&n[2]==0)n[0]++;
		else if(str=='O'&&n[1]<n[0]&&n[2]==0)n[1]++;
		else if(str=='I'&&n[2]<(x=min(n[0],n[1]))){
			n[2]++;
			if(n[2]==x)ans=max(ans,x);
		}
		else{
			for(int i=0;i<3;i++)n[i]=0;
			if(str=='J')n[0]=1;
		}
	}
	cout<<ans<<endl;
}