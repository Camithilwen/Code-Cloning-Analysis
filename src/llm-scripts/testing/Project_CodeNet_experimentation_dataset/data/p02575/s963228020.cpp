#include<bits/stdc++.h>
using namespace std;
int main(){
    int h, w;
    cin >> h >> w;
    map<int, int> m;
    multiset<int> v;
    for(int i = 0; i < w; i++)
        m[i] = i;
    for(int i = 0; i < w; i++)
        v.insert(0);
    for(int i = 0; i < h; i++){
        int a, b;
        cin >> a >> b;
        a--;
        auto it = m.lower_bound(a);
        int mm = -1;
        while(it != m.end() && it->first <= b){
            mm = max(mm, it->second);
            int x = it->first - it->second;
            v.erase(v.find(x));
            m.erase(it++);
        }
        if(mm != -1 && b < w){
            v.insert(b - mm);
            m[b] = mm;
        }
        int ans = -1;
        if(v.size() > 0)
            ans = *v.begin() + (i + 1);
        cout << ans << endl;
    }
    return 0;
}