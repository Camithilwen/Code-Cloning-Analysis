#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
#define int long long
using namespace std;
typedef pair<int,int>P;
#define F first
#define S second

int a[100009][20];
int b[100009];
int n,L,test;

signed main(){
	cin>>n;
	r(i,n) cin>>b[i];
	cin>>L;
	r(j,20){
		if(j==0){
			int id=0,sum=0;
			r(i,n){
				while(id<n-1 && sum+(b[id+1]-b[id])<=L) sum += b[id+1]-b[id],id++;
				a[i][j] = id;
				//cout<<id<<endl;
				if(i!=n-1 && sum)sum -=b[i+1]-b[i];
			}
		}
		else{
			r(i,n){
				a[i][j] = a[a[i][j-1]][j-1];
			}
		}
	}



	cin>>test;
	while(test--){
		int l,r;
		cin>>l>>r; l--; r--;
		if(r<l)swap(l,r);
		int sum=0;
		while(l<r){
			//cout<<l<<endl;
			for(int i=19;i>=0;i--){
				if(i&&( a[l][i]>=r ))continue;
				//cout<<l<<' '<<i<<' '<<a[l][i]<<' '<<i<<endl;
				l=a[l][i];
				sum+=pow(2,i);
				break;
			}
			//cout<<l<<endl;
		}
		cout<<sum<<endl;
	}
}
