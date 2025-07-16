#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

struct BIT {
  int n;
  vector<long long> d;
  BIT(int n=0):n(n),d(n+1) {}
  void add(int i, long long x=1) {
    for (i++; i <= n; i += i&-i) {
      d[i] += x;
    }
  }
  long long sum(int i) {
    long long x = 0;
    for (i++; i; i -= i&-i) {
      x += d[i];
    }
    return x;
  }
  long long sum(int l, int r) {
    return sum(r-1) - sum(l-1);
  }
};

int main(){
    int n,q;
    cin >> n >> q;
    vector<int> c(n);
    for(int i = 0; i < n; i++) cin >> c[i], c[i]--;

    vector<pair<pair<int,int>,int>> pq;
    for(int i = 0; i < q; i++){
        int l,r;
        cin >> l >> r;
        l--;r--;
        pq.push_back(make_pair(make_pair(l,r),i));
    }

    vector<int> memo(n,-1);
    vector<pair<int,int>> cp;
    for(int i = 0; i < n; i++){
        if(memo[c[i]] != -1) cp.push_back(make_pair(memo[c[i]],i));
        memo[c[i]] = i;
    }

    sort(pq.rbegin(),pq.rend());
    sort(cp.rbegin(),cp.rend());

    BIT tree(n);
    vector<int> ans(q,0);

    int ncp = 0;
    for(int i = 0; i < q; i++){
        while(true){
            if(ncp < (int)cp.size() && pq[i].first.first <= cp[ncp].first){
                tree.add(cp[ncp].second,1);
                ncp++;
            } else break;
        }
        ans[pq[i].second] = pq[i].first.second-pq[i].first.first+1-tree.sum(pq[i].first.second);
    }

    for(int i = 0; i < q; i++) cout << ans[i] << endl;


    return 0;
}