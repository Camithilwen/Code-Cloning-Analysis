#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

typedef pair <int,int> pi;
typedef pair <int,pi> pii;

struct point{
    point(int x, int y, int ind){
        this->x=x;
        this->y=y;
        this->ind=ind;
    }
    int x,y;
    int ind;
};

int getdist(int i,int j, vector <pi> &a){
    return min(abs(a[i].fi-a[j].fi),abs(a[i].se-a[j].se));
}

int par[100005],Size[100005];

int root(int i)
{
    while (par[i] != i)
    {
        par[i] = par[par[i]];
        i = par[i];
    }
    return i;
}

void wunion(int A, int B)
{
    int root_A = root(A);
    int root_B = root(B);
    if (Size[root_A] < Size[root_B])
    {
        par[root_A] = par[root_B];
        Size[root_B] += Size[root_A];
    }
    else
    {
        par[root_B] = par[root_A];
        Size[root_A] += Size[root_B];
    }

}

bool Find(int A, int B)
{
    if (root(A) == root(B))       //if A and B have same root,means they are connected.
        return true;
    else
        return false;
}

int main(){
    int n;
    cin >> n;
    vector <pi> a(n);
    vector <point> st;
    for(int i=0;i<n;i++){
        cin >> a[i].fi >> a[i].se;
        st.emplace_back(a[i].fi,a[i].se,i);
    }
    sort(st.begin(),st.end(),[](const point &l,const point &r){
        return l.x<r.x;
    });
    set <pii> e;
    for(int i=1;i<n;i++){
        e.insert({getdist(st[i].ind,st[i-1].ind,a),{st[i].ind,st[i-1].ind}});
        e.insert({getdist(st[i].ind,st[i-1].ind,a),{st[i-1].ind,st[i].ind}});
    }
    sort(st.begin(),st.end(),[](const point &l,const point &r){
        return l.y<r.y;
    });
    for(int i=1;i<n;i++){
        e.insert({getdist(st[i].ind,st[i-1].ind,a),{st[i].ind,st[i-1].ind}});
        e.insert({getdist(st[i].ind,st[i-1].ind,a),{st[i-1].ind,st[i].ind}});
    }
    for(int i=0;i<n;i++){
        par[i]=i;
        Size[i]=1;
    }
    long long ans=0;
    for(auto x:e){
        int i=x.se.fi, j =x.se.se;
        if(!Find(i,j)){
            wunion(i,j);
            ans+=x.fi;
        }
    }
    cout << ans << endl;
    return 0;
}