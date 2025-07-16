#include<iostream>
#include<string>
#include<stdio.h>
#include <algorithm>
#include <set>
#include<math.h>
#include<vector>

using namespace std;

int main(){
    int N,M,X,Y;cin >> N >> M >> X >> Y;
    int x[100]={};
    int y[100]={};
    int flag = 1;
    for(int i = 0;i < N;i++)cin >> x[i];
    for(int i = 0;i < M;i++)cin >> y[i];
    for(int i = X+1;i <= Y;i++){
        flag = 1;
        for(int j=0;j < N;j++){
            if(x[j] >= i){
                flag = 0;
                continue;
            }
        }
        if(flag==0)continue;
        for(int j = 0;j < M;j++){
            if(y[j] < i){
                flag = 0;
                continue;
            }
        }
        if(flag == 1)break;
    }
    if(flag == 1)cout << "No War" << endl;
    else cout << "War" << endl;
}