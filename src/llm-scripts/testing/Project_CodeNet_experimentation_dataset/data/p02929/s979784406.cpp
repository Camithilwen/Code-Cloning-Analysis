#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>


long long  INF=1000000000000000000;
long long mod=1000000007;
using namespace std;


long long stair(int N){
long long i=1;
for(int k=2;k<=N;k++){
    i*=k;
    if(i>mod){
        i%=mod;
    }
}
return i;

}

int main(){
int N;
cin>>N;
string s;
cin>>s;
char white='W';
char black='B';
if(s[0]==white || s[2*N-1]==white){
    cout<<"0"<<endl;
    return 0;
}


bool LorR[2*N];

LorR[0]=false;//L=false,R=trueとする


for(int i=1;i<2*N;i++){
    if(s[i-1]==s[i]){
        LorR[i]=!LorR[i-1];
    }
    else{
        LorR[i]=LorR[i-1];
    }
}
int countL[2*N+1];//Lの個数の累積和
int countR[2*N+1];//Lの個数の累積和
countL[0]=0;
countR[0]=0;
for(int i=0;i<2*N;i++){
    if(LorR[i]){
        countR[i+1]=countR[i]+1;
        countL[i+1]=countL[i];
    }
    else{
        countR[i+1]=countR[i];
        countL[i+1]=countL[i]+1;   
    }
}

if(countL[2*N]!=countR[2*N]){
    cout<<"0"<<endl;
    return 0;
}
long long ans=1;
for(int i=1;i<=2*N;i++){
    if(LorR[i-1]){
        if(countL[i]<countR[i]){
           cout<<"0"<<endl;
            return 0;
        }
        ans*=(countL[i]-countR[i-1]);
    }

    if(ans>mod){
        ans%=mod;
    }
}
//順列なのでnの階乗をかける
ans=(ans*stair(N))%mod;

cout<<ans<<endl;
 return 0;
}