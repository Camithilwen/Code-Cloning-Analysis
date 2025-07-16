#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#define INF 999999
using namespace std;
int main(){
    int N;
    while(cin>>N,N){
        int ice[15]={0},X;
        while(N--){
            cin>>X;
            ice[X]++;
        }
        for(int i=0;i<10;i++){
            if(ice[i]==0)cout<<"-";
            else{
                while(ice[i]--){
                    cout<<"*";
                }
            }
            puts("");
        }
    }
    return 0;
}