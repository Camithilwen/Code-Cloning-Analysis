#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


int card[10],n,k,sen[10];
vector<int> vec;

void dfs(int h,int num){

    if(h==k){
        for(int i=0;i<vec.size();i++)
            if(vec[i]==num) return;
        vec.push_back(num);
        return;
    }
    
    for(int i=0;i<n;i++){
        if(!sen[i]){
            sen[i]=true;
            dfs(h+1,num*pow(10,((int)log10(card[i])+1))+card[i]);
            sen[i]=false;
        }
    }
    
    return;
}

void solve(){
    
    for(int i=0;i<n;i++)
        scanf("%d",&card[i]);

    dfs(0,0);
    
    printf("%d\n",(int)vec.size());
    
    vec.clear();
    
    return;
}


int main(){
    
    while(1){
        scanf("%d%d",&n,&k);
        if(n+k==0) break;
        solve();
    }
    
    return 0;
}