#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> gusu(100000);
    vector<pair<int,int>> kisu(100000);
    rep(i,0,100000){
        gusu[i].second = i;
        kisu[i].second = i;
    }
    
    rep(i,0,n){
        int a;
        cin >> a;
        if(i%2==0){
            gusu[a].first++;
        }else{
            kisu[a].first++;
        }
    }
    sort(gusu.begin(),gusu.end());
    reverse(gusu.begin(),gusu.end());
    sort(kisu.begin(),kisu.end());
    reverse(kisu.begin(),kisu.end());

    if(gusu[0].second==kisu[0].second){
        int M = max(gusu[1].first,kisu[1].first);
        cout<<n-M-gusu[0].first<<endl;
    }else{
        cout<<n-gusu[0].first-kisu[0].first<<endl;
    }

  return 0;
}