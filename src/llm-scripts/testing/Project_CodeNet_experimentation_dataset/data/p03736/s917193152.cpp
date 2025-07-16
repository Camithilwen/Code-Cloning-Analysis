#include <bits/stdc++.h>
#define ll long long
#define fr(i, l, r) for(int i = l;i < r;i++)

using namespace std;

const int N = 200001;
const ll OO = 1e13;
ll tr[3][4 * N];
ll lz[4 * N];

void init(int in, int l, int r){
  if(l == r){
    fr(i, 0, 3)
      tr[i][in] = 1e13 + 1ll * (i - 1) * l;
    return;
  }
  int m = (l + r) / 2;
  init(in * 2, l, m);
  init(in * 2 + 1, m + 1, r);
  fr(i, 0, 3)
    tr[i][in] = min(tr[i][2 * in], tr[i][2 * in + 1]);
}

void push(int in, int l, int r){
  fr(i, 0, 3)
    tr[i][in] += lz[in];
  if(l != r){
    lz[2 * in] += lz[in], lz[2 * in + 1] += lz[in];
  }
  lz[in] = 0;
}

void ass(int in, int l, int r, int j, ll v){
  push(in, l, r);
  if(l > j || r < j)
    return;
  if(l == r){
    fr(i, 0, 3)
      tr[i][in] = v + 1ll * l * (i - 1);
    return;
  }
  int m = (l + r) / 2;
  ass(in * 2, l, m, j, v);
  ass(in * 2 + 1, m + 1, r, j, v);
  fr(i, 0, 3)
    tr[i][in] = min(tr[i][2 * in], tr[i][2 * in + 1]);
}

struct MnRes{
  ll mn[3];
  MnRes(){
    mn[0] = mn[1] = mn[2] = OO;
  }
  MnRes(ll a, ll b, ll c){
    mn[0] = a, mn[1] = b, mn[2] = c;
  }
  void upd(const MnRes& ot){
    fr(i, 0, 3)
      mn[i] = min(mn[i], ot.mn[i]);
  }
};


MnRes get(int in, int l, int r, int s, int e){
  push(in ,l, r);
  if(l > e || r < s)
    return MnRes();

  if(l >= s && r <= e){
    return MnRes(tr[0][in], tr[1][in], tr[2][in]);
  }
  int m = (l + r) / 2;
  MnRes res = get(2 * in, l, m, s, e);
  res.upd(get(2 * in + 1, m + 1, r, s, e));
  return res;
}

void add(int in, int l, int r, int s, int e, ll v){
  push(in, l, r);
  if(l > e || r < s)
    return;
  if(l >= s && r <= e){
    lz[in] += v;
    push(in, l, r);
    return;
  }
  int m = (l + r) / 2;
  add(2 * in, l , m, s, e, v);
  add(2 * in + 1, m + 1, r, s, e, v);
  fr(i, 0, 3)
    tr[i][in] = min(tr[i][2 * in], tr[i][2 * in + 1]);
}
int n, q, a, b;
//
//void print(int in = 1, int l = 0, int r = n -1){
//  push(in, l, r);
//  printf("l= %d, r= %d, tr[0]= %lld, tr[1]= %lld, tr[2]= %lld, lz[0]= %lld, lz[1]= %lld, lz[2]= %lld\n", l, r, tr[0][in], tr[1][in], tr[2][in], lz[0][in], lz[1][in], lz[2][in]);
//  if(l == r){
//    return;
//  }
//  int m = (l + r) / 2;
//  print(2 * in, l, m);
//  print(2 * in + 1, m + 1, r);
//}

int x[N];

int main(){
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  cin >> n >> q >> a >> b;
  a--, b--;
  fr(i, 0, q){
    cin >> x[i];
    x[i]--;
  }
  init(1, 0, n - 1);
//  print();
  ass(1, 0, n - 1, a, abs(b - x[0]));
//  print();
  ass(1, 0, n - 1, b, abs(a - x[0]));
  for(int i = 1;i < q;i++){
    // calc dp[i][x[i]]
    MnRes r1 = get(1, 0, n - 1, 0, x[i]);
    MnRes r2 = get(1, 0, n - 1, x[i], n - 1);
    ll val = min(x[i] + r1.mn[0], r2.mn[2] - x[i]);
    add(1, 0, n - 1, 0, n - 1, abs(x[i] - x[i -1]));
    ass(1, 0, n - 1, x[i - 1], val);
//    print();
//    cout << endl;
  }
//  print();
  cout << get(1, 0, n - 1, 0, n - 1).mn[1] << endl;
//  cout << get(1, 0, n - 1, 0, n - 1).mn[1];
}
