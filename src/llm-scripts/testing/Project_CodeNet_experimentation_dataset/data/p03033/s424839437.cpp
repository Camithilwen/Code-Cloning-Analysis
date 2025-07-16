#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
typedef pair<int, int> P;

int main()
{
    int n, q;
    cin >> n >> q;
    int s[200005], t[200005], x[200005];
    P p[400005];
    for(int i = 0; i < n; i++){
        cin >> s[i] >> t[i] >> x[i];
        p[i * 2] = P(s[i] - x[i], x[i]);
        p[i * 2 + 1] = P(t[i] - x[i], -x[i]);
    }
    sort(p, p + n * 2);
    set<int> st;
    int i = 0;
    while(q--){
        int d;
        cin >> d;
        while(i < n * 2 && p[i].first <= d){
            if(p[i].second > 0) st.insert(p[i].second);
            else st.erase(-p[i].second);
            i++;
        }
        if(st.empty()) cout << -1 << endl;
        else cout << *st.begin() << endl;
    }
}
