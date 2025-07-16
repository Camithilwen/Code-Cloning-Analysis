#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<pair<int,int>>> v(n,vector<pair<int,int>>());
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        for(int j=0;j<a;j++){
            int x,y;
            cin>>x>>y;
            x--;
            v[i].push_back(make_pair(x,y));
        }
    }
    int ans=0;
    for(int i=0;i<(1<<n);i++){
        int c=0;
        vector<bool> f(n,false);
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                f[j]=true;
                c++;
            }
        }
        bool ok=true;
        for(int j=0;j<n;j++){
            if(f[j]){
                for(auto p : v[j]){
                    if(p.second==1 && !f[p.first]) ok=false;
                    if(p.second==0 && f[p.first]) ok=false;
                }
            }
        }
        if(ok) ans=max(ans,c);
    }
    cout<<ans<<endl;
}
