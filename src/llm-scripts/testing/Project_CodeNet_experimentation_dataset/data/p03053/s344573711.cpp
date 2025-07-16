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
    vector<bool> a(h*w,false);

    queue<int> que;
    for(int i = 0; i < h; i++) {
        string tmp;
        cin >> tmp;
        for(int j = 0; j < w; j++) {
            int idx=i*w+j;
            if(tmp[j]=='#'){
                a[idx]=true;
                que.push(idx);
            }
        }
    }

    int cnt=0;
    int ans=0;
    while(cnt<h*w) {
        int n=que.size();
        cnt+=n;
        for(int i = 0; i < n; i++) {
            int idx=que.front();
            int add[4]={1,-1,w,-w};
            for(int j = 0; j < 4; j++) {
                int t=idx+add[j];
                int r=idx/w+add[j]/w;
                int c=idx%w+add[j]%w;
                if(r<0||r>=h||c<0||c>=w||a[t]==true) continue;
                a[t]=true;
                que.push(t);
            }
            que.pop();
        }
        ans++;
    }
    cout << ans-1 << "\n";

    return 0;
}