#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <set>
#include <map>
#include <stack>
#include <deque>
#include <iterator>
#include <iomanip>
#include <queue>
using namespace std;


int main(){
    long long n;
    cin >> n;
    vector<vector<long long> > a(n + 1, vector<long long>(n));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j < n; ++j){
            cin >> a[i][j];
        }
    }
    vector<long long> round;
    vector<long long> cnt(n + 1, 1);
    for(int i = 1; i <= n; ++i){
        if(a[a[i][1]][1] == i){
            round.push_back(i);
        }
    }
    long long ans = 0;
    while(!round.empty()){
        ans++;
        vector<long long> nw;
        for(long long i: round){
            cnt[i]++;
            if(cnt[i] <= n - 1){
                long long x = a[i][cnt[i]];
                if(i == a[x][cnt[x]]){
                    nw.push_back(i);
                    nw.push_back(x);
                }
            }
        }
        round = nw;
    }
    for(int i = 1; i <= n; ++i){
        if(cnt[i] != n){
            cout << -1;
            return 0;
        }
    }
    cout << ans;
}