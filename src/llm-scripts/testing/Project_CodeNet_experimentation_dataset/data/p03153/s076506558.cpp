#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<18;
const ll INF=1LL<<55;

int n;
pair<ll,int> dat[2*MAX-1][2];

void init(int n_){
    n=1;
    while(n<n_) n*=2;
    for(int i=0;i<2*n-1;i++){
        dat[i][0]={INF,i-(n-1)};
        dat[i][1]={INF,i-(n-1)};
    }
}

void update(int k,ll a,int kind){
    k+=n-1;
    dat[k][kind].first=a;
    
    while(k>0){
        k=(k-1)/2;
        dat[k][kind]=min(dat[k*2+1][kind],dat[k*2+2][kind]);
    }
}

pair<ll,int> query(int a,int b,int k,int l,int r,int kind){
    
    if(r<=a||b<=l) return {INF,-1};
    if(a<=l&&r<=b) return dat[k][kind];
    else{
        pair<ll,int> vl=query(a,b,2*k+1,l,(l+r)/2,kind);
        pair<ll,int> vr=query(a,b,2*k+2,(l+r)/2,r,kind);
        return min(vl,vr);
    }
}

struct edge{
    int from;
    int to;
    ll dis;
};

bool compare(edge a,edge b){
    return a.dis<b.dis;
}

int par[MAX],size[MAX];

void initUF(int n){
    for(int i=0;i<n;i++){
        par[i]=i;
        size[i]=1;
    }
}

int root(int a){
    if(par[a]==a) return a;
    else return par[a]=root(par[a]);
}

void unite(int a,int b){
    if(root(a)!=root(b)){
        size[root(a)]+=size[root(b)];
        par[root(b)]=root(a);
    }
}

bool check(int a,int b){
    return root(a)==root(b);
}

int main(){
    
    ll N;
    ll D;cin>>N>>D;
    vector<ll> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    
    vector<int> id(N);
    iota(all(id),0);
    sort(all(id),[&](int i,int j){
        return A[i]<A[j];
    });
    
    init(N);
    
    vector<edge> S;
    
    for(int i:id){
        auto left=query(0,i+1,0,0,n,0),right=query(i,n+1,0,0,n,1);
        if(left.first!=INF){
            S.push_back({left.second,i,A[left.second]+A[i]+D*(i-left.second)});
        }
        if(right.first!=INF){
            S.push_back({i,right.second,A[i]+A[right.second]+D*(right.second-i)});
        }
        
        update(i,D*(N-1-i)+A[i],0);
        update(i,D*i+A[i],1);
    }
    
    sort(all(S),compare);
    
    initUF(N);
    
    ll ans=0;
    
    for(edge e:S){
        int a=e.from,b=e.to;
        ll c=e.dis;
        
        if(check(a,b)) continue;
        
        ans+=c;
        unite(a,b);
    }
    
    cout<<ans<<endl;
    
}

