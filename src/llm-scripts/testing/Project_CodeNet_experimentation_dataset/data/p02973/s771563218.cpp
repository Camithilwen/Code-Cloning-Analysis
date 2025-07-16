#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin>>n;
    deque<int>q;
    rep(i,n){
        int a; cin>>a;
        int x=lower_bound(q.begin(),q.end(), a)-q.begin();
        if(x==0)q.push_front(a);
        else q[x-1]=a;
    }
    cout<<q.size()<<endl;
}