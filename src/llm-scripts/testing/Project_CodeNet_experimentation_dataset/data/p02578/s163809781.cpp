#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int a[N];

int main(){
int n;cin>>n;
ll sum=0;
for(int i=0;i<n;i++){
    cin>>a[i];
}
for(int i=1;i<n;i++){
    if(a[i]<a[i-1])
        sum+=a[i-1]-a[i],a[i]=a[i-1];
}
cout<<sum<<endl;
return 0;
}