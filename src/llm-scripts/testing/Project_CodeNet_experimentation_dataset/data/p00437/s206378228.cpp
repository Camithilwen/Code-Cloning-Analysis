#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int a,b,c;
    while(cin>>a>>b>>c,a||b||c){
        int n,parts[500],input[10000][4],bd;
        for(int i=0;i<500;i++) parts[i]=2;
        cin>>n;
        for(int _i=0;_i<n;_i++){
            for(int _j=0;_j<4;_j++){
                cin>>input[_i][_j];
            }
            if(input[_i][3]==1){
                for(int i=0;i<3;i++){
                    parts[input[_i][i]]=1;
                }
            }
            for(int i=0;i<=_i;i++){
                if(input[i][3]==1) continue;
                bd=-1;
                for(int j=0;j<3;j++){
                    if(parts[input[i][j]]==2 && bd==-1) bd=input[i][j];
                    else if(parts[input[i][j]]!=1){
                        bd=-1;
                        break;
                    }
                }
                if(bd!=-1) parts[bd]=0;
            }
        }
        for(int i=1;i<=a+b+c;i++){
            printf("%d\n",parts[i]);
        }
    }
    return 0;
}