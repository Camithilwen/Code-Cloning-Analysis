#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<double> a(n);
    vector<double> b(n);
    int sum=0;
    rep(i,n){
        cin >> a[i];
     sum+=a[i];
    }
    double ave=(double)sum/n;
    int ans=0;
    rep(j,n){  
     b[j]=abs(ave-a[j]);
    }
    sort(b.begin(),b.end());
    rep(i,n){
        if(abs(ave-a[i])==b[0]){
            ans=i;
            break;
        }
    }
  cout << ans << endl;
  return 0;
}