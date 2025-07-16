#include <bits/stdc++.h>
#include <time.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P  = pair<ll,ll>;
using vi = vector<ll>;
using vv = vector<vi>;
const ll INF = 1001001001;
const ll NUM = 1<<10;

//(開始, 今)を管理
//例:
//(0,0), (1,1), (2,2), (3,3), (4,4), (5,5)
//壁(1,2)   .      .(該当領域)
//(0,0), (1,3), (2,3), (3,3), (4,4), (5,5) ->(1,3),(2,3)は消す
//(0,0),               (3,3), (4,4), (5,5)
//壁(2,3)                 .(該当領域)
//(0,0),               (3,4), (4,4), (5,5) ->(3,4)は消す
//(0,0),                      (4,4), (5,5)
//
//・順序集合(map)を使う: map[今]=開始の最大値
//・ans = min(今-開始), multisetで管理
//・該当領域+1の範囲で開始が一番右のものだけ残す
//・それ以外はansからもmapからも消す

//

int main(){
    int h,w;
    cin >> h >> w;
    map<int,int> s;
    multiset<int> m;
    rep(i,w)s[i] = i;
    rep(i,w)m.insert(0);
    
    rep(i,h){
        int l,r;
        cin>>l>>r;
        --l;
        
        auto itr = s.lower_bound(l);
        int maxstart= -1;
        while(itr!=s.end() && itr->first<=r){
            maxstart= max(maxstart, itr->second);
            int c = itr->first - itr->second;
            m.erase(m.find(c));
            s.erase(itr++);
            //itr=s.erase(itr);//これでもいい
            //s.erase(*itr); itr++;//これはだめ
        }
        if(r<w && maxstart != -1){
            s[r] = maxstart;
            m.insert(r-maxstart);
        }
        int ans = -1;
        if(!m.empty())
            ans = *m.begin() + (i+1);
        cout<<ans<<endl;
    }
    return 0;
}