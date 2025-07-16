#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxm=2e5+5;
const int mod=1e9+7;
int a[maxm];
int b[maxm];
int n;
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<int>ans;
    for(int i=n;i>=1;i--){
        int cnt=0;
        for(int j=i;j<=n;j+=i){
            cnt+=b[j];
        }
        if(cnt%2==a[i]){
            continue;
        }else{
            b[i]=1;
            ans.push_back(i);
        }
    }
    cout<<ans.size()<<endl;
    for(auto i:ans){
        cout<<i<<' ';
    }
    return 0;
}
/*

*/
