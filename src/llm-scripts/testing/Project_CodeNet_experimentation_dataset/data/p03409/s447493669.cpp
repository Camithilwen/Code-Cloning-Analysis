#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N;
    cin >> N;
    vector<pair<int,int> > red(N);
    vector<pair<int,int> > blue(N);
    rep(i,N){
        cin >> red[i].second >> red[i].first;
    }
    rep(i,N){
        cin >> blue[i].first >> blue[i].second;
    }
    sort(all(red));
    sort(all(blue));
    int ans = 0;
    rep(i,N){
        int len = red.size();
        for (int j = len - 1; j >= 0; j--){
            if (blue[i].first > red[j].second && blue[i].second > red[j].first){
                ans++;
                red.erase(red.begin() + j);
                break;
            }
        }
    }
    cout << ans << endl;
}
