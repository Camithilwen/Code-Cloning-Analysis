#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
#define fr(i,k,n) for (int i = k; i < n; ++i)
#define fri(i,k,n) for (int i = k; i >= n; --i)
#define INF (int)1e9
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define all(arr) arr.begin(),arr.end()

void boost(){
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int N=5e5+5;
ll tree[N];

ll read(int idx) {
  ll sum = 0;
  while (idx > 0) {
    sum += tree[idx];
    idx -= (idx & -idx);
  }
  return sum;
}

void update(int idx, ll val) {
  while (idx <N) {
    tree[idx] += val;
    idx += (idx & -idx);
  }
}


void solve(){
  int n,q;
  cin>>n>>q;
  int x;
  fr(i,1,n+1){
    cin>>x;
    update(i,x);
  }
  int t,l,r;
  while(q--){
    cin>>t>>l>>r;
    if(t==0){
      update(l+1,r);
    }
    else{
      cout<<read(r)-read(l)<<endl;
    }
  }
  return;
}

int main()
{
  boost();
  
  int tc=1;
  //cin>>tc;
  while(tc--)
    solve();
  return 0;
}