#include<iostream>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;
const int N=42;
const int mod=2147483647;
const int mod1=1e9+9;
const int base=43;
int n,mul[N],mul1[N];
string s;
bool used[N];
vector<pair<int,int> > damn[N],damn1[N];
void check(){
	int i,dem=0,val=0,val1=0,val2=0,val3=0;
	for(i=1;i<=n;i++){
		if(!used[i]){
//			cout<<0;
			dem++;
			val=(val*base+(int)(s[i]-'a'))%mod;
			val2=(val2*base+(int)(s[i]-'a'))%mod1;
		}
	}
	for(i=n;i>0;i--){
		if(used[i]){
//			cout<<1;
			val1=(val1*base+(int)(s[i]-'a'))%mod;
			val3=(val3*base+(int)(s[i]-'a'))%mod1;
		}
	}
//	cout<<endl;
//	if(dem==0){
//		cout<<val<<' '<<val1<<endl;
//	}
	damn[dem].push_back({(val*mul[n-dem]-val1+mod)%mod,(val2*mul1[n-dem]-val3+mod1)%mod1});
}
void back(int idx,int lim){
	if(idx==lim+1){
		check();
		return;
	}
	used[idx]=false;
	back(idx+1,lim);
	used[idx]=true;
	back(idx+1,lim);
}
void check1(){
	int dem=0,val=0,val1=0,i,val2=0,val3=0;
	for(i=n+1;i<=2*n;i++){
		if(!used[i]){
//			cout<<0;
			val=(val*base+(int)(s[i]-'a'))%mod;
			val2=(val2*base+(int)(s[i]-'a'))%mod1;
		}
//		else{
//			cout<<1;
//		}
	}
	for(i=2*n;i>n;i--){
		if(used[i]){
			dem++;
			val1=(val1*base+(int)(s[i]-'a'))%mod;
			val3=(val3*base+(int)(s[i]-'a'))%mod1;
		}
	}
//	cout<<endl;
//	if(dem==0){
//		cout<<val<<' '<<val1<<endl;
//	}
	damn1[dem].push_back({(val1*mul[n-dem]-val+mod)%mod,(val3*mul1[n-dem]-val2+mod1)%mod1});
}
void back1(int idx,int lim){
	if(idx==lim+1){
		check1();
		return;
	}
	used[idx]=false;
	back1(idx+1,lim);
	used[idx]=true;
	back1(idx+1,lim);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int i,j,k,l,ans=0;
	cin>>n>>s;
	mul[0]=1;
	for(i=1;i<=2*n;i++){
		mul[i]=(mul[i-1]*base)%mod;
		mul1[i]=(mul1[i-1]*base)%mod;
	}
	s=" "+s;
	back(1,n);
	back1(n+1,2*n);
	for(i=0;i<=n;i++){
		sort(damn[i].begin(),damn[i].end());
		sort(damn1[i].begin(),damn1[i].end());
		for(j=0;j<damn[i].size();j++){
			//cout<<damn[i][j]<<' ';
			ans+=(int)(upper_bound(damn1[i].begin(),damn1[i].end(),damn[i][j])-lower_bound(damn1[i].begin(),damn1[i].end(),damn[i][j]));
		}
//		cout<<endl;
//		for(j=0;j<damn1[i].size();j++){
//			cout<<damn1[i][j]<<' ';
//		}
//		cout<<"cac "<<i<<endl;
	}
	cout<<ans;
}