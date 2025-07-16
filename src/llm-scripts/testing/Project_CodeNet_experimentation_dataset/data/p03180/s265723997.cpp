#include <bits/stdc++.h>
using namespace std;

#define ll  long long
#define PII pair<ll,ll>
#define VI  vector<ll>
#define VB  vector<bool>
#define VC vector<char>
#define VVI vector<vector<ll>>
#define VVC vector<vector<char>>
#define VS  vector<string>
#define VP  vector<PII>
#define lf(i,a,b) for(ll i=a;i<=b;i++)
#define lr(i,a,b) for(ll i=a;i>=b;i--)
#define lfl(i,v) for(ll i=0;i<v.size();i++)
#define lrl(i,v) for(ll i=(ll)(v.size())-1;i>=0;i--)
#define chk2(a,b) cout<<"check :  "<<a<<" "<<b<<endl
#define chk3(a,b,c) cout<<"check :  "<<a<<" "<<b<<" "<<c<<endl
#define chk4(a,b,c,d) cout<<"check :  "<<a<<" "<<b<<" "<<c<<" "<<d<<endl
#define chk5(a,b,c,d,e) cout<<"check :  "<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl
#define l_b(v,k)  lower_bound(v.begin(),v.end(),k)-v.begin()
#define u_b(v,k)  upper_bound(v.begin(),v.end(),k)-v.begin()
#define mod 1000000007
#define sort(v) sort(v.begin(),v.end())
#define p_b push_back
#define p_f push_front
#define m_p make_pair
#define fir first
#define sec second
#define sz size()
#define maxn 1<<17
ll n;
ll dp[maxn];
ll dpsmm[maxn];
ll valor[maxn];
VVI sub(maxn);
VVI mat;


void calcula(){

    for(int bitmask = 1;bitmask < (1 << n);bitmask++){
        for(int i = 0;i<n;i++){
            if(!(bitmask & (1 << i))) continue;
            for(int j = i+1;j<n;j++){
                if(!(bitmask & (1 << j))) continue;
                valor[bitmask] += mat[i][j];
            }
        }
    }

}


void fill_sub(ll ind,ll bm,ll subm)
    {   if(ind==n)
        {   if(__builtin_popcount(subm) == 0) return;
            sub[bm].p_b(subm);return ;
        }
        fill_sub(ind+1,bm,subm);
        fill_sub(ind+1,bm^(1<<ind),subm^(1<<ind));
        fill_sub(ind+1,bm^(1<<ind),subm);
    }
ll smm(ll bm)
    {   VI v1;
        if(dpsmm[bm]!=-1)
            return dpsmm[bm];
        lf(i,0,n-1)
        {   if(bm&(1<<i))
            {   v1.p_b(i);
            }
        }
        ll len=v1.size();
        ll sum=0;
        lfl(i,v1)
            lf(j,i+1,len-1)
                sum+=mat[v1[i]][v1[j]];
        return dpsmm[bm]=sum;
    }
ll fun(ll bm)
    {   if(bm==0)
        {   return 0;
        }   
        if(dp[bm]!=-1)
            return dp[bm];
        //cout<<bm<<endl;
        ll maxi=0;
        lfl(i,sub[bm])
        {   maxi=max(maxi,valor[sub[bm][i]]+fun(bm^sub[bm][i]));
        }
        return dp[bm]=maxi;
    }
int main() 
{   cin>>n;
    mat=VVI(n,VI(n,0));
    lf(i,0,n-1)
        lf(j,0,n-1)
            cin>>mat[i][j];
    memset(dp,-1,sizeof(dp));
    memset(dpsmm,-1,sizeof(dpsmm));
    fill_sub(0,0,0);
    calcula();
    cout<<fun((1<<n)-1);
}