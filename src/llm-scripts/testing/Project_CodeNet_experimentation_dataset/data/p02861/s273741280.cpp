#include <bits/stdc++.h>
#define ull unsigned long long 
#define ul unsigned long
#define ll long long
#define pb push_back
#define sodayoda_C  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define f(i,a,b) for(int i = a;i<b;i++)
#define fb(i,a,b) for(int i = a;i>b;i--)
#define endl "\n"
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define mp make_pair
//memset(name,'',size)
//reverse(s,begin(),s.end())

using namespace std;

int fact(int n){
	if(n == 0) return 1;
	return n*fact(n-1);
}

int main(){	
	sodayoda_C;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int t;
	//cin>>t;
	t = 1;
	while(t--){
		int n;
		cin>>n;
		double x[n],y[n];
		f(i,0,n) cin>>x[i]>>y[i];
		double ans = 0;
		f(i,0,n){
			f(j,0,n){
				if(j!=i){
					ans+= (1/(double)n)*sqrt(pow(x[i]-x[j],2) + pow(y[i]-y[j],2));
				}
			}
		}
		printf("%.7f",ans);
	}
	return 0;
}
