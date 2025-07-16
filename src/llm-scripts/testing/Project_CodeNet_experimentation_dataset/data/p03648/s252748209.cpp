#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i,n) for(int i=0,_n=(int)(n);i<_n;++i)
#define ALL(v) (v).begin(),(v).end()
#define CLR(t,v) memset(t,(v),sizeof(t))
template<class T1,class T2>ostream& operator<<(ostream& os,const pair<T1,T2>&a){return os<<"("<<a.first<<","<<a.second<< ")";}
template<class T>void pv(T a,T b){for(T i=a;i!=b;++i)cout<<(*i)<<" ";cout<<endl;}
template<class T>void chmin(T&a,const T&b){if(a>b)a=b;}
template<class T>void chmax(T&a,const T&b){if(a<b)a=b;}

bool f(vector<ll> &a) {
  int N = (int)a.size();
  if (*max_element(ALL(a)) < N)
    return false;
  REP(i, N) a[i]++;
  *max_element(ALL(a)) -= (N+1);
  return true;
}

void rev(vector<ll> &a) {
  int N = (int)a.size();
  REP(i, N) a[i]--;
  *min_element(ALL(a)) += (N+1);
}

void print(const vector<ll> &a) {
  int N = (int)a.size();
  cout << N << endl;
  REP(i, N) {
    if (i > 0) cout << " ";
    cout << a[i];
  }
  cout << endl;
}

int main2() {
  ll K; cin >> K;
  int N = 50;
  vector<ll> a(N, N-1);
  REP(i, N) a[i] += K/N;
  REP(_, K % N) {
    rev(a);
  }

  print(a);

  // if (K <= 100) {
    // ll count = 0;
    // while (f(a)) {
      // count++;
      // print(a);
    // }
    // cout << "check=" << count << endl;
  // }
  
  return 0;
}

int main() {
  for (;!cin.eof();cin>>ws)
    main2();
  return 0;
}
