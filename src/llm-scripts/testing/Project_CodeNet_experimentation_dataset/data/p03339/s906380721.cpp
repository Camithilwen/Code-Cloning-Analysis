#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int n;cin>>n;
    string s;cin>>s;
    
    int a[n+1],sum[n+1];
    memset(a,0,sizeof(a));
    memset(sum,0,sizeof(sum));

    rep(i,n){
        if(s[i]=='W'){
        ++a[i];
        --a[n];
        }
        else{
        ++a[0];
        --a[i+1];            
        }
    }
    
    sum[0]=a[0];
    rep(i,n)sum[i+1]=a[i+1]+sum[i];
    
    sort(sum,sum+n);
    cout<<sum[0]-1<<endl;
	return 0;
}