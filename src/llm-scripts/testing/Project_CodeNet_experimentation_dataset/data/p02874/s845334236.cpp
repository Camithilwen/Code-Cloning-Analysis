/*
 * @Author: RBQRBQ
 * @Date: 2020-04-05 15:08:15
 * @LastEditors: RBQRBQ
 * @LastEditTime: 2020-04-05 19:16:50
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef pair<ll,ll> pii;
namespace IO{
    template<typename T>inline void read(T &x){
        x=0;ll f=1;char ch=getchar();
        while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
        while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
        x=x*f;
    }
}
using namespace IO;
vector<pii> pp;
vector<pii> T;
ll mxL,minR,mxR,minL;


int main()
{
    int N;
    cin>>N;
    mxL=mxR=-1;
    minL=minR=10000000000ll;
    int P,Q;
    for(int i=1;i<=N;i++)
    {
        ll x,y;
        read(x),read(y);
        y++;
        pp.push_back(make_pair(x,y));
        if(x>mxL)
        {
            mxL=x;
            P=i;
        }
        if(minR>y)
        {
            minR=y;
            Q=i;
        }
    }
    ll ans1=0,ans2=0;
    minL=0;
    for(int i=1;i<=N;i++)
    {
            minL=max(minL,pp[i-1].second-pp[i-1].first);
    }

    ans1=max((minL),0ll)+max((minR-mxL),0ll);

    int ca=1;
    for(auto p:pp)
    {
        if(ca!=P&&ca!=Q)
        T.push_back(make_pair(max(p.second-mxL,0ll),max(minR-p.first,0ll)));
        ca++;
    }
    sort(T.begin(),T.end());
    ll P1=pp[P-1].second-pp[P-1].first;
    ll Q1=pp[Q-1].second-pp[Q-1].first;
    ll x1=0,x2=Q1;
    // for(auto p:T)
    // {
    //     cout<<p.first<<" "<<p.second<<endl;
    // }
    for(int i=0;i<T.size();i++)
    {
        
        x1=min(T[i].first,P1);
        ans2=max(ans2,x1+x2);
        x2=min(T[i].second,x2);
    }
    ans2=max(ans2,P1+x2);
    cout<<max(ans1,ans2);

}