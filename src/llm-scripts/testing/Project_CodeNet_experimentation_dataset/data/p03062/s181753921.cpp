#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    long long n,sum=0,he=0;
    cin>>n;
    long long a[n];
    for(int i=0;i<n;i++){ 
        cin>>a[i];
        he+=abs(a[i]);
        if(a[i]<0) sum++;
        a[i]=abs(a[i]);
    }
    sort(a,a+n);
    if(sum%2==0) cout<<he<<endl;
    else cout<<he-a[0]*2<<endl;
    return 0;
}