#include <iostream>
#include <map>
using namespace std;

struct UF{
    int par[200000];
    int rank[200000];
    
    void init(int n){
        for(int i=0;i<n;i++){
            par[i]=i;
            rank[i]=0;
        }
    }
    
    int find(int x){
        if(par[x]==x)return x;
        return par[x]=find(par[x]);
    }
    
    void unite(int x, int y){
        x=find(x);
        y=find(y);
        if(x!=y){
            if(rank[x]<rank[y]){
                par[x]=y;
            }else{
                par[y]=x;
                if(rank[x]==rank[y])rank[x]++;
            }
        }
    }
    
    bool same(int x, int y){
        return par[x]==par[y];
    }
};

int main(void){
    int n,k,l;
    map<pair<int, int>, int> u;
    cin>>n>>k>>l;
    UF a,b;
    a.init(n);
    b.init(n);
    
    for(int i=0;i<k;i++){
        int p,q;
        cin>>p>>q;
        a.unite(p, q);
    }
    for(int i=0;i<l;i++){
        int p,q;
        cin>>p>>q;
        b.unite(p, q);
    }
    for(int i=1;i<=n;i++){
        u[pair<int,int>(a.find(i),b.find(i))]++;
    }
    for(int i=1;i<=n;i++){
        cout<<u[pair<int,int>(a.find(i),b.find(i))];
        if(i<n)cout<<" ";
        else cout<<endl;
    }
    
}
