#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi  first
#define se  second

typedef pair<int,int>   ii;

priority_queue<int> q;
vector<ii>  v;
int n, sum = 0;

signed main()  {
    ios_base::sync_with_stdio(false);   cin.tie(0);
    cin >> n;
    for(int i = 0 ; i < n ; ++i)    {
        int D, L;   cin >> D >> L;
        v.push_back(ii(D + L,L));
    }
    sort(v.begin(),v.end());
    for(int i = 0 ; i < n ; ++i)    {
        q.push(v[i].se);
        sum += v[i].se;
        if(sum > v[i].fi)   {
            sum -= q.top();
            q.pop();
        }
    }

    cout << q.size() << endl;
}
