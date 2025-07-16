#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using ll = long long;

template <typename T>
T min(T a, T b){
  return (a < b) ? a : b;
}

template <typename T>
class SegTree{
  static const int MAXN = 100010;
  T INF;
  int n;
  T A[MAXN*4];
  T time[MAXN*4];
  public:
  SegTree(int size, T INF): INF(INF){
    n = 1;
    while(n < size){
      n *= 2;
    }
    n *= 2;
    for(int i = 0; i < MAXN*4; i++) A[i] = INF;
    for(int i = 0; i < MAXN*4; i++) time[i] = 0;
  }

  void update(int a, int b, T v, T t){
    return _update(a, b, 0, 0, n, v, t);
  }

  void _update(int a, int b, int k, int l, int r, T v, T t){
    if(a >= r || b <= l){
      return;
    }
    if(l >= a && r <= b){
      A[k] = v;
      time[k] = t;
      return;
    }
    _update(a, b, 2*k + 1, l, (l+r)/2, v, t);
    _update(a, b, 2*k + 2, (l+r)/2, r, v, t);
  }

  T query(int _idx){
    int offset = n - 1;
    int idx = _idx + offset;
    T t = 0;
    T ans = INF;
    while(idx > 0){
      if(time[idx] >= t){
        ans = A[idx];
        t = time[idx];
      }
      idx = (idx-1)/2;
    }
    return ans;
  }
};

int main(void){
  int n, q; cin >> n >> q;
  SegTree<int> rmq(n, 0x7FFFFFFF);
  for(int loop = 0; loop < q; loop++){
    int com;
    cin >> com;
    if(com == 0){
      int x, y, v; cin >> x >> y >> v;
      rmq.update(x, y+1, v, loop+1);
    }else{
      int i; cin >> i;
      cout << rmq.query(i) << endl;
    }
  }
}

