/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \|     |//  `.
            /  \|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
            pass the Test!
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<string,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
ll INF=1LL<<60;
ll MOD=1000000007;

int main(){
    ll N;
    cin >> N;
    ll M;
    cin >> M;
    ll V;
    cin >> V;
    ll P;
    cin >> P;
    vector<ll> A(N,0);
    for(ll i=0;i<N;i++){
        cin>>A[i]
    ;}
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    vector<ll> ikou(N+1,0);
    for(ll i=N-1;i>=0;i--){
        ikou[i]=ikou[i+1]+A[i]
    ;}
    ll ans=P-1;
    for(ll i=P;i<N;i++){
        if(A[P-1]-A[i]<=M&&M*V-M*(N-i+P-1)<=(A[i]+M)*(i-P+1)-(ikou[P-1]-ikou[i]))ans=i;
        else break;
    ;}
    cout<<ans+1<<endl;
    return 0;
}
