#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    int n;
    cin>>n;
    int cnt = 0;
    if(n<3){
        cout<<0<<endl;
        return 0;
    }
    cnt = 0;
    while(n>=3){
        cnt++;
        n-=3;
    }
    cout<<cnt<<endl;
    return 0;
}