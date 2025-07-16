#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
#define f2(i,j,k) for(int i=j;i>k;i--)
using namespace std;
int main(){
    long long n,now=0;
    cin>>n;
    string s,t;
    cin>>s>>t;
    while(1){
        if(s.substr(now,n-now)==t.substr(0,n-now)){
            break;
        }
        now++;
    }
    cout<<n+now<<endl;
    return 0;
}
