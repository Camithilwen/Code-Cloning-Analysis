#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define mem0(x) memset(x,0,sizeof(x))
#define meminf(x) memset(x,0x3f,sizeof(x))
#define VI vector<int>
#define VL vector<ll>
using namespace  std;

const int N = 1e5+5;
int a[N];
deque<int> q;
int num;
int main()
{
    ios::sync_with_stdio(0);
    int n;cin>>n;
    rep(i,1,n){
        cin>>a[i];
    }
    q.push_back(a[1]);++num;
    rep(i,2,n){

        // cout<<"t"<<i-1<<":";
        // rep(i,1,num){
        //     cout<<q[i-1]<<' ';
        // }
        //cout<<endl;
        int idx = upper_bound(q.begin(),q.end(),a[i],greater<int>())-q.begin();
        //cout<<"idx:"<<idx<<endl;
        if(idx==num){
            q.push_back(a[i]);
            ++num;
        }else{
            q[idx] = a[i];
        }
        //sort(q.begin(),q.end(),greater<int>());
    }
    cout<<num;
    
}
