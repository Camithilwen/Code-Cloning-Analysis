#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <cassert>

using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i < n+1; i++){
        cin >> a[i];
    }
    vector<int> b(n+1);
    for(int i = n; i >= 1; i--){
        int sum = 0;
        for(int j = i+i; j <= n; j += i){
            sum ^= b[j];
        }
        b[i] = sum^a[i];
    }
    vector<int> ans;
    for(int i = 1; i <= n; i++){
        if(b[i]) ans.push_back(i);
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}