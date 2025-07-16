#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
typedef vector<int>vint;
typedef pair<int,int>pint;


signed main(){
    int N,p[100]={0},r[100];

    cin>>N;
    rep(i,N*(N-1)/2){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        a--;b--;
        if(c>d)p[a]+=3;
        else if(c<d)p[b]+=3;
        else{
            p[a]++;p[b]++;
        }
    }

    vector<pint>vec(N);
    rep(i,N)vec[i]=pint(p[i],i);
    sort(all(vec));reverse(all(vec));

    int tmp=0;
    rep(i,N){
        if(i&&vec[i-1].first!=vec[i].first)tmp=i;
        r[vec[i].second]=tmp;
    }

    rep(i,N)cout<<r[i]+1<<endl;
    return 0;
}