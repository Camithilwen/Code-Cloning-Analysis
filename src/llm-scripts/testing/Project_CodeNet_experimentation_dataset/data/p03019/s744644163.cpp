#include <bits/stdc++.h>
using namespace std;

long long n, x, cur = 0;
vector<vector<long long>> tests;

long long check(long long k){

    long long best, complete = k / x, other = k % x, cursum = 0;

    if(complete >= n)
        return cur + 1;

    for(int i = 0; i < complete; ++i)
        cursum += tests[i][0];

    best = cursum;

    for(int i = 0; i < n; ++i){
        if(i < complete){
            best = max(best, tests[complete][0] + (cursum - tests[i][0]) + tests[i][3] * other - tests[i][1] * (tests[i][3] - tests[i][2]));
            best = max(best, tests[complete][0] + (cursum - tests[i][0]) + tests[i][2] * other);
        } else {
            best = max(best, cursum + tests[i][3] * other - tests[i][1] * (tests[i][3] - tests[i][2]));
            best = max(best, cursum + tests[i][2] * other);
        }
    }
    return best;
}

int main(){

    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

    long long b, l ,u; cin >> n >> x;

    for(int i = 0; i < n; ++i){
        cin >> b >> l >> u;
        cur += b * l;
        tests.push_back({(x - b) * u + b * l, b, l, u});
    }

    sort(tests.begin(), tests.end(), greater<vector<long long>>());

    long long mid, lef = -1, rig = n * x;
    for(;lef < rig - 1;){
        mid = lef + rig >> 1;
        if(check(mid) >= cur)
            rig = mid;
        else
            lef = mid;
    }
    cout << rig << "\n";
    return 0;
}