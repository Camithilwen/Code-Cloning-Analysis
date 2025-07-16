#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100001,INF=1<<30;
vector<int> S[MAX],color(MAX,0),odd,even;

void DFS(int u){
    int cnt=1;
    bool ok=true;
    stack<int> ST;
    color[u]=1;
    ST.push(u);
    
    while(!ST.empty()){
        int a=ST.top();
        ST.pop();
        for(int i=0;i<S[a].size();i++){
            int b=S[a][i];
            if(color[b]==0){
                if(color[a]==1){
                    color[b]=2;
                    ST.push(b);
                    cnt++;
                }else{
                    color[b]=1;
                    ST.push(b);
                    cnt++;
                }
            }else if(color[a]==color[b]){
                ok=false;
            }
        }
    }
    
    if(ok) even.push_back(cnt);
    else odd.push_back(cnt);
    
    return;
}

int main(){
    
    int N,M;cin>>N>>M;
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        S[a].push_back(b);
        S[b].push_back(a);
    }
    
    for(int i=0;i<N;i++){
        if(S[i].size()==0||color[i]) continue;
        DFS(i);
    }
    
    int rem=N;
    
    ll ans=0;
    
    for(int i=0;i<odd.size();i++){
        rem-=odd[i];
    }
    
    for(int i=0;i<even.size();i++){
        rem-=even[i];
    }
    
    ans+=odd.size()+even.size()*2;
    ans+=ll(N)*ll(N)-ll((N-rem))*ll((N-rem));
    
    ans+=ll(4)*ll(even.size())*ll((even.size()-1))/2;
    ans+=ll(2)*ll(even.size())*ll(odd.size());
    ans+=ll(2)*ll(odd.size())*ll((odd.size()-1))/2;
    
    cout<<ans<<endl;
    //cout<<rem<<" "<<odd.size()<<" "<<even.size()<<endl;
    
}


