#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
#define rep(i,n) for(int i = 0;i < (n); i++)
typedef pair<int, int> P;

int main(){
    int h,w;
    cin >> h >> w;
    int a[h][w];
    vector<P>orig;
    vector<P>after;
    rep(i,h){
        rep(j,w){
            int temp;
            cin >> temp;
            a[i][j] = temp;
        }
    }
    int count = 0;
    rep(i,h-1){
        rep(j,w){
            if(a[i][j] % 2 != 0){
                a[i][j]--;
                a[i+1][j]++;
                count++;
              P hoge;
                hoge.first = i+1;
                hoge.second = j+1;
                orig.push_back(hoge);
                hoge.first = i+2;
                after.push_back(hoge);
            }
        }
    }
    rep(i,w-1){
        if(a[h-1][i] % 2 != 0){
            a[h-1][i]--;
            a[h-1][i+1]++;
            count++;
          P hoge;
            hoge.first = h;
            hoge.second = i+1;
            orig.push_back(hoge);
            hoge.second = i+2;
            after.push_back(hoge);
        }
    }
    cout << count << endl;
    rep(i,count){
        cout << orig[i].first << ' ' << orig[i].second << ' ' << after[i].first << ' ' << after[i].second << endl; 
    }

}