#include<bits/stdc++.h>
using namespace std;
const int N=1001000;
int n;
char s[N],t[N];
deque<int> deq;
int main(){
	cin>>n;
	scanf("%s%s",s+1,t+1);
	int he=0,ta=1,l=n+1,tag=0,ans=0;
	deq.push_back(n+1);
	for(int i=n;i;--i){
		int tmp=l;
		while(l&&(l>i||s[l]!=t[i])) --l;
		if(!l) return puts("-1")&0;
		if(tmp==l){
			while(!deq.empty()&&deq.back()-tag>=i) deq.pop_back();
			deq.push_back(i+tag);
		}
		else{
			++tag;
			if(l!=i) ans=max(ans,(int)deq.size()),deq.push_front(l+tag);
		}
	}
	cout<<ans<<endl;
	return 0;
}