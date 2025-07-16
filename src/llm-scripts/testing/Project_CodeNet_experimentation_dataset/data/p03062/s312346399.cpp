#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll nature(ll a){//絶対値を返す
  if(a>=0){return(a);}
  else{return(-1*a);}
}
int main(){
    long long N,count=0,count0=0;
    cin>>N;
    long long ans=0,m=10000000007;
    vector<long long> vec(N);
    for(int i=0;i<N;i++){
        cin>>vec.at(i);
        if(vec.at(i)==0){
            count0++;
        }
        if(vec.at(i)<0){
            count++;
        }
        long long M=nature(vec.at(i));
        ans+=M;
        m=min(m,M);
    }
    for(int i=0;i<N;i++){
    }
    if(count%2==0){
        cout<<ans<<endl;
    }
    else{
        cout<<ans-2*m<<endl;
    }
}