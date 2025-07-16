#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        mp[a]++;
    }
    int t = (1 << 30);
    int ans = 0;
    for(auto itr = mp.rbegin(); itr != mp.rend(); itr++){
        int a = itr->first, c = itr->second;
        while(t > a * 2) t /= 2;
        if(t == a * 2) ans += c / 2;
        else{
            ans += min(mp[a], mp[t - a]);
            mp[t - a] -= min(mp[a], mp[t - a]);
        }
    }
    cout << ans << endl;
}
