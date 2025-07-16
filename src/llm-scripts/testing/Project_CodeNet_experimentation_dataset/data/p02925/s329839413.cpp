#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n;cin>>n;
    vector<vector<int>> a(n,vector<int>(n));
    rep(i,n)rep(j,n-1){
        cin>>a[i][j];a[i][j]--;
    }
    vector<int> t(n,0);
    vector<bool> used(n,false);
    ll cou=0;
    queue<int> que1;
    rep(i,n) que1.push(i);
    while(true){
        cou++;
        //cout<<que1.size()<<endl;
        rep(i,n)used[i]=false;
        bool changed=false;
        queue<int> que2;
        while(que1.size()){
            int i=que1.front();que1.pop();
            if(used[i]||t[i]==n-1)continue;
            int b=a[i][t[i]];
            if(!used[b]&&a[b][t[b]]==i&&t[b]<n-1){
                used[i]=true;used[b]=true;changed=true;
                t[i]++;t[b]++;
                que2.push(i);que2.push(b);
            }
        }
        
        if(!changed){
            cout<<-1<<endl;
            return 0;
        }
        rep(i,n){
            if(t[i]!=n-1)changed=false;
        }
        if(changed){
            cout<<cou<<endl;
            return 0;
        }
        swap(que1,que2);
    }
}