#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
int ans;
vector<int>v;
vector<int>pos;
int sol(int i,int j){
	int smsm=0;
	int tmp=k;
	priority_queue<int>pq;
	for(int s=0;s<=i&&tmp;s++){
		smsm+=v[s];
		pq.push(-v[s]);
		tmp--;if(tmp==0)break;
	}
	if(j<=i){
		int ssss=smsm;
		int ttmp=tmp;
		priority_queue<int>ppq=pq;
		while(ppq.size()&&ttmp){
			if(ppq.top()<=0)break;
			ssss+=ppq.top();ppq.pop();
			ttmp--;if(ttmp==0)break;
		}
		ans=max(ans,ssss);
	}else{
		priority_queue<int>ppq=pq;
		int ttmp=tmp;
		int ssss=smsm;
		for(int z=i+1;z<=j&&ttmp;z++){
			ppq.push(-v[z]);
			ssss+=v[z];
			ttmp--;
			if(ttmp==0)break;
		}
		while(ppq.size()&&ttmp){
			if(ppq.top()<=0)break;
			ssss+=ppq.top();ppq.pop();
			ttmp--;
			if(ttmp==0)break;
		}
		ans=max(ans,ssss);
		ppq=pq;ttmp=tmp;ssss=smsm;
		for(int z=n-1;z>=j&&ttmp;z--){
			ppq.push(-v[z]);
			ssss+=v[z];
			ttmp--;if(ttmp==0)break;
		}
		while(ppq.size()&&ttmp){
			if(ppq.top()<=0)break;
			ssss+=ppq.top();ppq.pop();
			ttmp--;if(ttmp==0)break;
		}
		ans=max(ans,ssss);
	}
	priority_queue<int>cls;
	smsm=0;tmp=k;pq=cls;
	for(int z=n-1;z>=i&&tmp;z--){
		smsm+=v[z];
		pq.push(-v[z]);
		tmp--;if(tmp==0)break;
	}
	if(j>=i){
		int ssss=smsm;
		int ttmp=tmp;
		priority_queue<int>ppq=pq;
		while(ppq.size()&&ttmp){
			if(ppq.top()<=0)break;
			ssss+=ppq.top();ppq.pop();
			ttmp--;if(ttmp==0)break;
		}
		ans=max(ans,ssss);
	}else{
		priority_queue<int>ppq=pq;
		int ttmp=tmp;
		int ssss=smsm;
		for(int z=i-1;z>=j&&ttmp;z--){
			ppq.push(-v[z]);
			ssss+=v[z];
			ttmp--;if(ttmp==0)break;
		}
		while(ppq.size()&&ttmp){
			if(ppq.top()<=0)break;
			ssss+=ppq.top();ppq.pop();
			ttmp--;if(ttmp==0)break;
		}
		ans=max(ans,ssss);
		ppq=pq;ttmp=tmp;ssss=smsm;
		for(int z=0;z<=j&&ttmp;z++){
			ppq.push(-v[z]);
			ssss+=v[z];
			ttmp--;if(ttmp==0)break;
		}
		while(ppq.size()&&ttmp){
			if(ppq.top()<=0)break;
			ssss+=ppq.top();ppq.pop();
			ttmp--;if(ttmp==0)break;
		}
		ans=max(ans,ssss);
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		v.push_back(a);
		if(a>0)pos.push_back(i);
	}
	for(int i=0;i<pos.size();i++){
		for(int j=0;j<pos.size();j++){
			sol(pos[i],pos[j]);
			// cout<<"---------------"<<endl;
			// cout<<pos[i]<<' '<<pos[j]<<endl;
			// cout<<ans<<endl;
		}
	}
	cout<<ans;
	return 0;
}