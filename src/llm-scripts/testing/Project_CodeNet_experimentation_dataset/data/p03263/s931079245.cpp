#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h,w;
    cin >> h >> w;
    vector<int> a(h*w);
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(i%2) cin >> a[i*w+w-1-j];
            else    cin >> a[i*w+j];
        }
    }
    vector<string> ans;
    for(int i = 0; i < h*w-1; i++) {
        if(a[i]%2){
            a[i]--;
            a[i+1]++;
            int r=i/w;
            int c=i%w;
            int nr=(i+1)/w;
            int nc=(i+1)%w;
            if(r%2) c=w-1-c;
            if(nr%2) nc=w-1-nc;
            string tmp=to_string(r+1)+" "+to_string(c+1)+" "+to_string(nr+1)+" "+to_string(nc+1);
            ans.emplace_back(tmp);
        }
    }
    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << "\n";

    return 0;
}