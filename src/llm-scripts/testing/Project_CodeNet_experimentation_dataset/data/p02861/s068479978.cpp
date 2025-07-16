#include <bits/stdc++.h>
using namespace std;
#define pi 2*asin(1.0)
 
 
//template functions
/////////////////////////
long Comb(long N,long M){// nCm
long ans=1;
for(long i=N;i>N-M;i--){
    ans=ans*i;
}
for(long i=M;i>0;i--){
    ans=ans/i;
}
return ans;
}
long Perm(long N,long M){// nPm
long ans=1;
for(long i=N;i>N-M;i--){
    ans=ans*i;
}
return ans;
}
long GCM(long A,long B){
            long W,r;
    if(A<B){
 
        W=B;
        B=A;
        A=W;
    }
    while(A%B!=0){
        r=A%B;
        A=B;
        B=r;
    }
    return B;
}
long LCM(long A,long B){
    return (A*B)/GCM(A,B);
}
 
long upDiv(long a,long b){
  return (a+b-1)/b;
}
 
long fact(long N){
    if(N==0){
        return 1;
    }else{
        long ans=1;
        for(long i=1;i<N+1;i++){
        ans=ans*i;
        }
        return ans;
    }
 
 
 
}
 
/////////////////////////
 
 
//Answer
 
 
int main() {
 
long double N;
long double dis,sum=0.0,answer;
cin>>N;
vector<long double> x(N);
vector<long double> y(N);
for(long i=0;i<N;i++){
cin>>x.at(i);
cin>>y.at(i);
}
for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      double dx=x.at(i)-x.at(j);
      double dy=y.at(i)-y.at(j);
        sum+=pow((dx*dx+dy*dy),0.5);
    }
}
answer=sum*2.0/N;
 
cout<< fixed << setprecision(10) << answer<<endl;
 
}