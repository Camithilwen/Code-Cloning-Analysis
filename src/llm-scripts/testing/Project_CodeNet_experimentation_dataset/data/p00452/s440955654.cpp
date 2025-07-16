#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int lislis[1003000];
int main(){
    while(1){
        int N,M;
        cin>>N>>M;
        if(N==0&&M==0)break;
        int lis[1002]={0};
        for(int i=1;i<=N;i++)cin>>lis[i];
        for(int i=0;i<1003000;i++)lislis[i]=0;
        for(int i=0;i<=N;i++){
            for(int j=0;j<=N;j++)lislis[i*(N+1)+j]=lis[i]+lis[j];
        }
        sort(lislis,lislis+((N+1)*(N+1)));
        lislis[(N+1)*(N+1)]=lislis[(N+1)*(N+1)-1];
        int maxans=0;
        for(int i=0;i<(N+1)*(N+1);i++){
            int l=0,r=(N+1)*(N+1),mid=(l+r)/2;
            for(int j=0;j<30;j++){
                if(lislis[i]+lislis[mid]<=M)l=mid;
                else r=mid;
                mid=(l+r)/2;
            }
            /*
            printf("[%d] [%d][%d][%d]\n",i,l,mid,r);
            */
            if(lislis[i]+lislis[l]<=M)maxans=max(maxans,lislis[i]+lislis[l]);
        }
        /*
        for(int i=0;i<20;i++)printf("[%d]",lis[i]);
        puts("");
        for(int i=0;i<30;i++)printf("[%d]",lislis[i]);
        puts("");
        */
        cout<<maxans<<endl;
    }
    return 0;
}