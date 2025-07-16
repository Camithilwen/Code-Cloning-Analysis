#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n;cin>>n;
    vector<vector<int>> a(n,vector<int>(n-1));
    rep(i,n)rep(j,n-1){
        cin>>a[i][j];
        a[i][j]--;
    }
    int f=0;
    vector<int> t(n,0);
    queue<int> que;
    rep(i,n)que.push(i);
    ll res=0;
    while(true){
        res++;
        queue<int> que2;
        bool used=false;
        vector<bool> ft(n,false);
        while(que.size()){
            int x=que.front();que.pop();
            if(ft[x])continue;
            int op=a[x][t[x]];
            if(ft[op])continue;
            if(a[op][t[op]]==x){
                used=true;
                ft[x]=ft[op]=true;
                t[x]++;t[op]++;
                if(t[x]==n-1)f++;
                else que2.push(x);
                if(t[op]==n-1)f++;
                else que2.push(op);
            }
        }
        if(!used){
            cout<<-1<<endl;
            return 0;
        }
        if(f==n){
            cout<<res<<endl;
            return 0;
        }
        swap(que,que2);
    }
}