#include<bits/stdc++.h>
using namespace std;

int a[3][100000];
int x[100000];
int inv[100000];
int BIT[100001];

void init(){
	for(int i=1;i<=100000;i++)
		BIT[i]=0;
}

void add(int x){
	for(;x<=100000;x+=x&-x)
		BIT[x]++;
}

int query(int x){
	int res=0;
	for(;x>0;x-=x&-x)
		res+=BIT[x];
	return res;
}

void fail(){
	cout<<"No"<<endl;
	exit(0);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<3;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	vector<pair<int,int> > v0,v1;
	long long int cnt0=0,cnt1=0,inv0=0,inv1=0;
	for(int i=0;i<n;i++){
		if(abs(a[0][i]-a[1][i])!=1||abs(a[1][i]-a[2][i])!=1)
			fail();
		x[i]=a[1][i]/3;
		if((x[i]&1)^(i&1))
			fail();
		inv[i]=a[0][i]>a[1][i];
		if(i&1)
			v1.emplace_back(x[i],i),inv1+=inv[i];
		else
			v0.emplace_back(x[i],i),inv0+=inv[i];
	}
	sort(v1.begin(),v1.end(),greater<pair<int,int> >());
	sort(v0.begin(),v0.end(),greater<pair<int,int> >());
	for(auto it:v0){
		cnt0+=query(it.second+1);
		add(it.second+1);
	}	
	init();
	for(auto it:v1){
		cnt1+=query(it.second+1);
		add(it.second+1);
	}
	if((inv1+cnt0)&1)
		fail();
	if((inv0+cnt1)&1)
		fail();
	cout<<"Yes"<<endl;
}
