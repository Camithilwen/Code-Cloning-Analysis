#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
#define loop(i,a,b) for(int i=(a);i<int(b);i++)
#define rep(i,b) loop(i,0,b)

typedef pair<int, int> pii;
int main(){
    int n;
    while(cin >> n && n){
        vector<pii> v(n);
        rep(i,n) v[i].second = i;
        int game = n * (n-1) / 2;

        rep(i,game){
            int a,b,c,d;
            cin >> a >> b >> c >> d;
            if(c>d) v[a-1].first += 3;
            else if(c < d) v[b-1].first += 3;
            else v[a-1].first++, v[b-1].first++;
        }

        sort(v.rbegin(), v.rend());
        int score = -1;
        int rank = 1;
        rep(i,n){
            if (v[i].first == score) v[i].first = rank;
            else {
                score=v[i].first;
                v[i].first=i+1;
                rank=i+1;
            }
        }
        sort(v.begin(), v.end(), [](pii l,pii r){
                return l.second < r.second;
            });
        rep(i,n)cout<<v[i].first<<endl;
    }
}