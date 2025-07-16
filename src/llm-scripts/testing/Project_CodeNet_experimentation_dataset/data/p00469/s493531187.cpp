#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>

using namespace std;

set<string>mo;
int N,k;
bool use[15];
map<string,int>memo;
string n[10];
void g(int m,string a){
    if(m==k){
        memo[a]=1;
    return;
    }
        for(int i=0;i<N;i++){
        if(!use[i]){
                string _a=a+n[i];
            use[i]=1;
            g(m+1,_a);
            use[i]=0;
        }
    }
}
//??¨??????????????????(????????????)
int main(){
while(1){
        int ans=0;
        cin >> N >> k;
    if(N==0&&k==0)break;
    for(int y=0;y<N;y++){
        cin >> n[y];
    }
    fill(use,use+15,0);
    memo.clear();
    g(0,"");
    cout << memo.size() << endl;
}

return 0;
}