#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n;
    while(cin>>n,n){
        long long int syain,kakaku,kosuu,syains[5000]={0};
        long long int bango[5000]={0},flag[5000]={0};
        bool flag2=0;
        for(int i=0;i<n;i++){
            cin>>syain>>kakaku>>kosuu;
            bango[i]=syain;
            syains[syain]+=kakaku*kosuu;
        }
        for(int i=0;i<5000;i++){
            if(syains[bango[i]]>=1000000){
                if(flag[bango[i]]==0){
                        cout<<bango[i]<<endl;
                        flag[bango[i]]=1;
                }
            }
        }
        for(int i=0;i<5000;i++){
            if(flag[i]==1)flag2=1;
        }
    if(flag2==0)cout<<"NA"<<endl;
    }
    return 0;
}