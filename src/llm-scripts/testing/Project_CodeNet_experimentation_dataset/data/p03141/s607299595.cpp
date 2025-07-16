#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp(a,b) make_pair(a,b)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
#define YN(a) if(a){cout<<"Yes"<<endl;}else cout<<"No"<<endl;//条件によってYes、Noを出力する
const int MOD=1000000007;
const double pi = 3.141592653589793;
int main(){
    int n;
    cin>>n;
    vector<int64_t> a(n),b(n);
    //方針:自分が幸福度高い皿を取りたいし、相手の幸福度高い皿を先にとってしまいたい
    //->おのおのa[i]+b[i]が高い順に取っていけばいいのでは？
    priority_queue<pair<int64_t,int>> dish;
    rep(i,n){
        cin>>a[i]>>b[i];
        dish.push(mp(a[i]+b[i],i));
    }
    vector<bool> eaten(n,false);
    int64_t tp=0,ap=0;
    rep(turn,n){
           while(eaten[dish.top().second]){
               dish.pop();
           }
           eaten[dish.top().second]=true;
           if(turn%2==0)tp += a[dish.top().second];
           else ap += b[dish.top().second];
           dish.pop();
    }
    cout<<tp-ap<<endl;
}