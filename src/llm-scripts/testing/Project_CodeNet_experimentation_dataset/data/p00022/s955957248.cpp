#include <bits/stdc++.h>
#define loop(times) for(int i=0;i<(times);i++)

using namespace std;

int main() {
    while(1<2){
    int n;
    long long max;
    cin>>n;
    if(n==0)break;
    int a[n];
    int s[n];

    loop(n)cin>>a[i];
    max=a[0];
    s[0]=a[0];
        
    loop(n)s[i+1]=s[i]+a[i+1];
    for(int k=0;k<n;k++){
     loop(n-k){
         if(max<=s[k+i]-s[k-1])max=s[k+i]-s[k-1];   
    }
    }
    cout<<max<<endl;
    }
}
