#include<iostream>
using namespace std;

int count(long long n){
    int cnt=0;
    while(n>0){
        n/=10;
        cnt++;
    }
    return cnt;
}

int main(){
    long long n;
  	long long b;
    int cur=0;
  	int ans=100000;
    cin>>n;
    for(long long i=1;i*i<=n;i++){
       if(n%i==0){
       b=n/i;
       cur=max(count(i),count(b));
       if(ans>cur)ans=cur;
        }
    }
    cout<<ans<<endl;
    return 0;
}