#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using ll= long long;
using namespace std;

int main(){
    int N,A;
    cin>>N;
    
    vector<vector<pair<int,int>>> data;
    data.resize(N);
    rep(i,N){
        cin>>A;
        data[i].resize(A);
        rep(j,A){
            cin>>data[i][j].first>>data[i][j].second;
            data[i][j].first--;
        }
    }
    
    int ans=0;
    for (int bit=0;bit<(1<<N);bit++){
        int cnt=0;
        bool ok=true;
        rep(i,N){
             if(!(bit & (1<<i))){
                    continue;
                }
            for (auto xy:data[i]){
                int x=xy.first;
                int y=xy.second;
               
                if((bit & (1 << x))&&y==0){
                    ok=false;
                    
                }
                else if(!(bit & (1 << x))&&y==1){
                    ok=false;
                    
                }
                
            }
            
        }
        if(ok==true){
            rep(i,N){
                if(bit&(1<<i)){
                    cnt++;
                }
            }
            ans=max(ans,cnt);
        }
        
    }
    cout<<ans<<endl;
    
    }
    
    
    
    
    
  
 
 


