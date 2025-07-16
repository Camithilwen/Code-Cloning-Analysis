#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;
pair<ll,int> p[100005];
int main(){
	ll n,x; cin >> n >> x;
	vector<ll> b(n),l(n),u(n);
	for(int i=0;i<n;i++){
		cin >> b[i] >> l[i] >> u[i];
	}
	ll sum=0;
	for(int i=0;i<n;i++){
		p[i]=pair<ll,int>((x-b[i])*u[i]+b[i]*l[i],i);
		sum-=b[i]*l[i];
	}
	sort(p,p+n);
	ll ret=0;//満点を取る教科を数える
	int last=0;
	for(int i=n-1;i>=0;i--){
		if(sum+p[i].first>=0){
			ret+=(ll)(n-i-1)*(ll)x;//満点を取る教科はn-i-1個である
			last=i+1;
			break;
		}
		sum+=p[i].first;
	}
	ll Min=x;//中途半端に解く科目の得点の最小値
	sum=-sum;
	for(int i=0;i<last;i++){
		int v=p[i].second;
		Min=min(Min,(sum+l[v]-1)/l[v]);//中途半端に解く科目に最小の重みをつけた場合
		ll nsum=sum+b[v]*(u[v]-l[v]);//最大の重みをつける場合には更にディスアドバンテージが広がる
		Min=min(Min,(nsum+u[v]-1)/u[v]);
	}
	//貪欲に見ると満点を取る科目になる科目のうち中途半端に解くものを探索する場合、
	//満点を取る科目としてi=last-1も追加される
	for(int i=last;i<n;i++){
		int v=p[i].second;
		ll nsum=sum+p[i].first-p[last-1].first;
		Min=min(Min,(nsum+l[v]-1)/l[v]);
		ll nsum2=nsum+b[v]*(u[v]-l[v]);
		Min=min(Min,(nsum2+u[v]-1)/u[v]);
	}
	cout << ret+Min << endl;
}