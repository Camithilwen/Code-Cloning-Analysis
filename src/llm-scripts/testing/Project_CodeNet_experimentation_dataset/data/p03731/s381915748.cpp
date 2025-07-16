#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,t;
    cin>>n>>t;
    vector<int>vec(n);
    for(int i=0;i<n;i++)
      cin>>vec[i];
    int sum=0;
    for(int i=0;i<n-1;i++)
      sum+=min(t,vec[i+1]-vec[i]);
    sum+=t;
    cout<<sum<<endl;
    return 0;
}