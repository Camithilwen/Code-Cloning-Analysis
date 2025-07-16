#include<bits/stdc++.h>
using namespace std;

vector < int > v;

bool check(int n, int m, int mid){

    int x=(m-mid);
    long long int y=(n-1)*1LL*mid;
    return (x>=y && x%mid==0);
    ///return (m/mid>=n && m%mid==0);
}

int cal(int n, int m){
    int ans=0;
    for(int i=1; i*i<=m; i++){
        if(m%i==0){
             if(check(n,m,i))ans=max(ans,i);
             if(check(n,m,m/i))ans=max(ans,m/i);
        }
    }
    return ans;
}

int main(){

    int n,m;
    cin>>n>>m;
    int ans=cal(n,m);
    cout<<ans<<endl;
    return 0;
}
