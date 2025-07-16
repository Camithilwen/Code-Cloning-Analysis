#include<bits/stdc++.h>
using namespace std;
 
#define pb 		push_back
#define mp 		make_pair
#define prior   priority_queue
#define MOD 	1000000007
#define INF64 	(long long)1e18
#define INF 	(int)1e9
#define PI 		3.1415926535897932384626433832795 
#define ll      long long
#define ld		long double
#define ret     return
#define NUM 	1000001
const int SIZE = 2e5+4;
void fastio(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
void input(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}
void swap(int& a, int& b){
	int t=a;
	a = b;
	b = t;
}
 
void solveTest(){
	int A,B,M;
	cin>>A>>B>>M;
	int a[A+1],b[B+1];
	int minA = INT_MAX;
	int minB = INT_MAX;
	for(int i=1;i<=A;i++){
		cin>>a[i];
		if(a[i]<minA){
			minA=a[i];
		}
	}
	for(int i=1;i<=B;i++){
		cin>>b[i];
		if(b[i]<minB){
			minB = b[i];
		}
	}
	int minprice = INT_MAX;
	for(int i=0;i<M;i++){
		int x,y,c;
		cin>>x>>y>>c;
		if((a[x]+b[y]-c)<minprice){
			minprice = a[x]+b[y]-c;
		}
	}
	cout<<min(minA+minB,minprice)<<endl;
	return ;
}
 
int main(){
	fastio();
	//input();
 
	int t=1;
	//cin>>t;
	while(t--){
		solveTest();
 
	}
	
	return 0;
}