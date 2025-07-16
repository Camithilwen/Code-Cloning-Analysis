#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int,int_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define ordered_set_pair tree<pair<int,int>,int_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update> 
 
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
typedef pair<int,int> pi; 
#define PI 3.1415926535897932384
#define FOR(i,vv,n) for(int i=vv;i<n;i++)
#define FORR(i,n,vv) for(int i=n-1;i>=vv;i--)
#define ve vector 
#define maxind(v) (max_element(v.begin(),v.end())-v.begin())
#define minind(v) (min_element(v.begin(),v.end())-v.begin())
#define maxe(v) *max_element(v.begin(),v.end())
#define mine(v) *min_element(v.begin(),v.end())
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mp make_pair
#define M 1000000007ll
#define M1 100000000000000000ll
#define PRECISE cout.precision(18);
#define BS(v,n) binary_search(v.begin(),v.end(),n)
#define srt(v) sort(v.begin(),v.end())
#define rsrt(v) sort(v.begin(),v.end(),greater <int>())
#define F first
#define S second
 
bool comp(pair <ll,ll> &p1,pair <ll,ll> &p2){

if(p1.F<p2.F)
	return 1;
if(p1.F==p2.F){
	return p1.S>p2.S;
}
return 0;

}

 
 
int main(){
 

    FAST
//	PRECISE



ll n;
cin>>n;
ll z=0;
ll L=0,LL=0;
ll R=M,LR=0;
ll MA=0;
ve <pair <ll,ll> > dummy;
FOR(i,0,n){
	ll x,y;
	cin>>x>>y;
	y++;
	R=min(R,y);
	if(R==y)
		LR=max(LR,y-x);
	
	L=max(L,x);
	if(L==x)
		LL=max(LL,y-x);
	dummy.pb({x,y});
	MA=max(MA,y-x);
} 
ll ans=max(z,R-L)+MA;

ve <pair <ll,ll> > v;
FOR(i,0,n){
	ll a1=max(z,dummy[i].S-L);
	ll a2=max(z,R-dummy[i].F);
	v.pb({a1,a2});
} 
sort(v.begin(),v.end(),comp);
ll cm=LR;
FOR(i,0,v.size()){

	ll lans=0;
	ll a1=v[i].F;
	lans=a1+cm;
	ans=max(ans,lans);
	cm=min(cm,v[i].S);

}
ans=max(ans,cm+LL);
cout<<ans;






 
return 0;
 }	