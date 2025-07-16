#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int N,M;
    int a[1002]={0},vt[1002]={0};
    cin>>N>>M;
    for(int i=1;i<=N;i++)cin>>a[i];
    for(int i=0;i<M;i++){
        int b;
        cin>>b;
        for(int j=1;j<=N;j++){
            if(a[j]<=b){
                vt[j]++;
                break;
            }
        }
    }
    int ans=0,ansvt=0;
    for(int i=1;i<=N;i++)if(ansvt<vt[i])ans=i,ansvt=vt[i];
    cout<<ans<<endl;
    return 0;
}