#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
int INF = 1000000009;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cout << 0 << endl;
    cin >> s;
    if(s == "Vacant"){
        return 0;
    }
    int ok = n;
    int ng = 0;
    string tmp;
    while(tmp!="Vacant")
    {
        int mid = (ok + ng) / 2;
        cout << mid << endl;
        cin >> tmp;
        if(mid%2^tmp==s){
            ng = mid;
        }
        else
        {
            ok = mid;
        }
    }
    return 0;
}