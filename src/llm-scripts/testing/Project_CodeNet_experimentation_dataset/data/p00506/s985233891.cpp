#include "bits/stdc++.h"
#define rep(i,a,n) for(int i = a;i < n;i++)
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

int main(){
    int n,memo;
    priority_queue<int,vector<int>,greater<int> > que;
    cin >> n;
    int a[n];
    
    rep(i,0,n){
        cin >> a[i];
    }
    
    sort(a,a+n);
    
    rep(i,1,sqrt(a[n-1])+1){
        rep(j,0,n){
            if(a[j] % i)break;
            else if(j == n-1)que.push(i);
        }
        
        if(a[n-1]/i == i)continue;
        
        rep(j,0,n){
            if(a[j] % (a[n-1]/i))break;
            else if(j == n-1)que.push(a[n-1]/i);
        }
    }
    
    while(!que.empty()){
        if(que.top() == memo){
            que.pop();
            continue;
        }
        memo = que.top(); que.pop();
        
        cout << memo << endl;
    }
}
