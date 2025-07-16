#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
ll INF=1LL<<60;
ll MOD=1000000007;



int main(){
    ll N;
    cin >> N;
    vector<ll> L(N,0);
    vector<ll> R(N,0);
    ll recL=0;ll MaxL=0;
    for(ll i=0;i<N;i++){
        cin>>L[i]>>R[i];
        if(MaxL<L[i]){
            MaxL=L[i];
            recL=i;
        }
    ;}
    if(N==2){
        cout<<R[0]+R[1]-L[0]-L[1]+2<<endl;return 0;
    }
    vector<P> pq(0);
    for(ll i=0;i<N;i++){
        if(i!=recL)pq.push_back(P(R[i],L[i]))
    ;}
    sort(pq.begin(), pq.end());
    vector<ll> lmax(N-1,0);
    ll q=0;
    for(ll i=0;i<N-1;i++){
        q=max(q,pq[i].second);
        lmax[i]=q
    ;}
    //L[recL]が最大
    //最終的にrecL側のRの選考基準をｒとする
    //Rがpq[r]以上は仲間

    ll ans=0;

    //pq[0]が敵の時かつ仲間いるとき
    for(ll r=1;r<=N-2;r++){
        ans=max(ans,max(min(pq[r].first,R[recL])-MaxL+1,0LL)+max(pq[0].first-lmax[r-1]+1,0LL));
    ;}
    //全員敵
    ans=max(ans,max(pq[0].first-lmax[N-2]+1,0LL)+R[recL]-MaxL+1);
    //pq[0]が味方の時;
    ll ans2=0;
    ans2+=max(0LL,min(pq[0].first,R[recL])-MaxL+1);//味方
    ll check;
    for(ll i=0;i<N;i++){
        if(L[i]==pq[0].second&&R[i]==pq[0].first&&i!=recL){check=i;break;}
    ;}
    priority_queue<ll> vec;
    for(ll i=0;i<N;i++){
        if(i!=recL&&i!=check){
            vec.push(R[i]-L[i]+1);
        }
    ;}
    ans2+=vec.top();
    ans=max(ans,ans2);

    cout<<ans<<endl;


    return 0;
}
