#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;


bool sol(vector<int>d1,vector<int>d2){
    for(int i=0;i<4;i++){
        int tmp1=d1[0];
        d1[0]=d1[2], d1[2]=d1[5], d1[5]=d1[3], d1[3]=tmp1;
        for(int j=0;j<4;j++){
            int tmp2=d1[0];
            d1[0]=d1[1], d1[1]=d1[5], d1[5]=d1[4], d1[4]=tmp2;
            for(int k=0;k<4;k++){
                int tmp3=d1[1];
                d1[1]=d1[2], d1[2]=d1[4], d1[4]=d1[3], d1[3]=tmp3;
                if(equal(d1.cbegin(),d1.cend(),d2.cbegin())){
                    printf("No\n");
                    return false;
                }
            }
        }
    }
    return true;
}

int main(){
    int n;
    scanf("%d",&n);
    vector<vector<int>> d(n,vector<int>(6));
    for(int i=0;i<n;i++){
        for(auto&e:d[i]){
            scanf("%d",&e);
        }
    }
    bool flag;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            flag=sol(d[i],d[j]);
            if(flag==false) return 0;;
        }
    }
    printf("Yes\n");
    return 0;
}