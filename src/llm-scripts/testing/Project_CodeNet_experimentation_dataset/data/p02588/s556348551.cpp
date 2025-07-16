// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
// #define maxn 100005

// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     ll t=1;
//     //cin>>t;
//     while(t--){
//     	int n;
//     	cin>>n;
//     	double d;
//     	ll x;
//     	int num2,num5;
//     	map<pair<int,int>,int> num;
//     	for(int i=0;i<n;i++){
//     		cin>>d;
//     		x=llround(d*1e9);
//     		//cout<<x<<"\n";
//     		num2=0,num5=0;
//     		while(x%2==0) num2++,x/=2;
//     		//cout<<x<<"\n";
//     		while(x%5==0) num5++,x/=5;
//     		num[{num2,num5}]++;
//     	}
//     	int ans=0;
//     	for(auto p1:num){
//     		for(auto p2:num){
//     			if(p1.first.first+p2.first.first>=18 && p1.first.second+p2.first.second>=18){
//     				if(p1<p2) ans+= p1.second*p2.second;
//     				if(p1==p2)ans+=(p1.second*(p2.second-1))/2;
//     			}
//     		}
//     	}
//     	cout<<ans<<"\n";
//     }
// }



#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100005
 
int num[19][19];
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    //cin>>t;
    while(t--){
    	ll n;
    	cin>>n;
    	double d;
    	ll x,y=1000000000;
    	int num2,num5;
    	for(int i=0;i<=18;i++)
    		for(int j=0;j<=18;j++)
    			num[i][j]=0;
    	vector<pair<int,int>> vec;
    	for(int i=0;i<n;i++){
    		cin>>d;
    		x=llround(d*1e9);
    		//cout<<x<<"\n";
    		num2=0,num5=0;
    		while(x%2==0) num2++,x/=2;
    		//cout<<x<<"\n";
    		while(x%5==0) num5++,x/=5;
    		if(num2>18) num2=18;
    		if(num5>18) num5=18;
    		vec.push_back({num2,num5});
    		//cout<<num2<<" "<<num5<<"\n";
    		for(int j=0;j<=18;j++){
    			for(int k=0;k<=18;k++){
    				if(18-num2<=j && 18-num5<=k) num[j][k]++;
    			}
    		}
    	}
    	
    	ll ans=0;
    	for(int i=0;i<n;i++){
    		num2=vec[i].first;
    		num5=vec[i].second;
    		for(int j=0;j<=18;j++){
    			for(int k=0;k<=18;k++){
    				if(18-num2<=j && 18-num5<=k) num[j][k]--;
    			}
    		}
    		ans+=num[num2][num5];
    	}
    	cout<<ans<<"\n";
    }
}