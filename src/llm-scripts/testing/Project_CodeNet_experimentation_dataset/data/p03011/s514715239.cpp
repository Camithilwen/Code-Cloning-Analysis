#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sidha(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int> 
#define pb push_back

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
	int n,m,p;cin>>n>>m>>p;
	cout<<min({n+m,m+p,n+p})<<endl;
	return 0;
}