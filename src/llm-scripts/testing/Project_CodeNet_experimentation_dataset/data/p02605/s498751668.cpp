#include<bits/stdc++.h>
#define tmp(x) std::cout<<"& "<<(x)<<" &\n"
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
typedef long long ll;
#define  pii pair<int,int>
#define  pll pair<ll,ll>
#define  vi vector<int>


using namespace std;
const int maxn=3e5+100;
const int inf=(int)1e9+7;
int n;

vector<pair<int,char> > x[maxn],y[maxn],le[2*maxn],ri[2*maxn];
int ans=inf;
void work(vi v1,vi v2,int aa){

    if(!v2.empty()&&!v1.empty()){
        vector<int>::iterator it1,it2;
        sort(v2.begin(),v2.end());
        sort(v1.begin(),v1.end());
        it2=v2.begin(),it1=v1.begin();
        for(auto p1:v1){
            for(auto p2:v2){
                if(p2<p1)continue;
                else {
                    ans=min(ans,abs(p1-p2)*10/aa);
                    break;
                }
            }
        }
        
        /*while(*it1!=*v1.end()&&*it2!=*v2.end()){
            while(*it2!=*v2.end()&&*it2<*it1)++it2;
            if(*it2==*v2.end())break;
            ans=min(ans,abs(*it1-*it2)*10/aa);
            ++it1;
        }*/
    }
}
int main(){
//	freopen("in.txt","r",stdin);
    scanf("%d",&n);
    int xx,yy;char c;
    rep(i,1,n){
        scanf("%d%d %c",&xx,&yy,&c);

        x[xx].push_back(make_pair(yy,c));
        y[yy].push_back(make_pair(xx,c));
        le[xx-yy+200000].push_back(make_pair(xx,c));
        ri[xx+yy].push_back(make_pair(xx,c));
    }
    rep(i,0,200000){
        if(!x[i].empty()){
            vector<int>up,down;
            for(auto p:x[i]){
                if(p.second=='U')up.push_back(p.first);
                if(p.second=='D')down.push_back(p.first);
            }
            work(up,down,2);
        }
        if(!y[i].empty()){
            vector<int>right,left;
            for(auto p:y[i]){
                if(p.second=='R')right.push_back(p.first);
                if(p.second=='L')left.push_back(p.first);
            }
            work(right,left,2);
        }
    }

    rep(i,0,400000){
        if(!le[i].empty()){
            vector<int> right,down,left,up;
            for(auto p:le[i]){
                if(p.second=='D')down.push_back(p.first);
                else if(p.second=='R')right.push_back(p.first);
                else if(p.second=='U')up.push_back(p.first);
                else if(p.second=='L')left.push_back(p.first);
            }
            work(right,down,1);
            work(up,left,1);
        }
        if(!ri[i].empty()) {
            vector<int> right, up,left, down;
            for (auto p:ri[i]) {
                if (p.second == 'U')up.push_back(p.first);
                else if (p.second == 'R')right.push_back(p.first);
                else if (p.second == 'D')down.push_back(p.first);
                else if (p.second == 'L')left.push_back(p.first);
            }
            work(right, up,1);
            work(down, left,1);
        }
    }
    if(ans==inf)printf("SAFE");
    else  printf("%d",ans);




    return 0;
}