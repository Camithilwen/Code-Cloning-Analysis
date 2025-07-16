#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    while(1){
        int A,B,C,N;
        cin>>A>>B>>C;
        if(A==0&&B==0&&C==0)break;
        cin>>N;
        int lis[1000][4];
        for(int i=0;i<N;i++)cin>>lis[i][0]>>lis[i][1]>>lis[i][2]>>lis[i][3];
        int che[301];
        for(int i=1;i<=300;i++)che[i]=2;

        for(int i=0;i<N;i++){
            if(lis[i][3]==1)che[lis[i][0]]=1,che[lis[i][1]]=1,che[lis[i][2]]=1;
        }
        for(int i=0;i<N;i++){
            if(che[lis[i][0]]==1&&che[lis[i][1]]==1&&lis[i][3]==0)che[lis[i][2]]=0;
            if(che[lis[i][0]]==1&&che[lis[i][2]]==1&&lis[i][3]==0)che[lis[i][1]]=0;
            if(che[lis[i][1]]==1&&che[lis[i][2]]==1&&lis[i][3]==0)che[lis[i][0]]=0;
        }
        for(int i=1;i<=A+B+C;i++)cout<<che[i]<<endl;
    }
    return 0;
}