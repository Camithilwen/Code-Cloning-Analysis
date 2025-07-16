#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int main()
{
    int n; cin >> n;
    vector<int> a(n), groups;
    rep(i, n) cin >> a[i];

    groups.push_back(a[0]);
    rep(i, n-1){
        int ng = -1, ok = groups.size();
        while(ok - ng > 1){
            int mid = (ng + ok) / 2;
            if(groups[mid] < a[i + 1])
                ok = mid;
            else
                ng = mid;
        }
        if(ok == groups.size())
            groups.push_back(a[i + 1]);
        else
            groups[ok] = a[i + 1];
    }

    cout << groups.size() << endl;
    return 0;
}