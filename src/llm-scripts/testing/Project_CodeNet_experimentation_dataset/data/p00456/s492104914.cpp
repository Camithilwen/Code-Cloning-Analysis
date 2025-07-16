#include<cstdio>
#include<iostream>
int main(){
    int nowpoint,wran[3]={0},kran[3]={0},wsum=0,ksum=0;
    for(int i=0;i<10;i++){
        scanf("%d",&nowpoint);
        if(wran[0]<nowpoint)
            wran[2]=wran[1],wran[1]=wran[0],wran[0]=nowpoint;
        else if(wran[1]<nowpoint)
            wran[2]=wran[1],wran[1]=nowpoint;
        else if(wran[2]<nowpoint)
            wran[2]=nowpoint;
    }
    for(int i=0;i<10;i++){
        scanf("%d",&nowpoint);
        if(kran[0]<nowpoint)
            kran[2]=kran[1],kran[1]=kran[0],kran[0]=nowpoint;
        else if(kran[1]<nowpoint)
            kran[2]=kran[1],kran[1]=nowpoint;
        else if(kran[2]<nowpoint)
            kran[2]=nowpoint;
    }
    for(int i=0;i<3;i++)
        wsum+=wran[i],ksum+=kran[i];
    printf("%d %d\n",wsum,ksum);
    return 0;
}