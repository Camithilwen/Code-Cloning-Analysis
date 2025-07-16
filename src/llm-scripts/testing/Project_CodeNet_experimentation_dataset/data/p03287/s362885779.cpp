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
#include <queue>
#include <stack>
#include <deque>
#include <iterator>
#include <iomanip>
using namespace std;

int main(){
    long long n, m;
    cin >> n >> m;
    vector<long long> a(n), ps(n);
    map<long long, long long> mp;
    long long ans = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        ps[i] = a[i];
        if(i) ps[i] += ps[i - 1];
        ps[i] %= m;
        if(!ps[i]) ans++;
        ans += mp[ps[i]];
        mp[ps[i]]++;
    }
    cout << ans;
}