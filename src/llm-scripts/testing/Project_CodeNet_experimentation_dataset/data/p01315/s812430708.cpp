#include <bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
using vs=vector<string>;
using msi=map<string,int>;
using mii=map<int,int>;
using pii=pair<int,int>;
using vlai=valarray<int>;
using ll=long long;
#define rep(i,n) for(int i=0;i<n;i++)
#define range(i,s,n) for(int i=s;i<n;i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define fs first
#define sc second
struct item{
    string name;
    int p,s1,s2,x,r,m;
    double y;
    item(){
        int a,b,c,d,e;
        cin>>name>>p>>a>>b>>c>>d>>e>>x>>r>>m; 
        s1=a+b+c;s2=d+e;
        y=(double)(x*r*m-p)/(s1+s2*m);
    }
};

int main(){
    int n;
    while(cin>>n,n){
        vector<item> v(n);
        sort(all(v),[](item a, item b){return a.y>b.y || (a.y==b.y && a.name<b.name);});
        for(auto p : v)cout<<p.name<<endl;
        cout<<"#"<<endl;
    }
}