#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#include<cmath>

#define REP(i,n) for (int i = 0; (i) < (n); ++ (i))
#define FOR(i,n) for (int i = 1; (i) <= (n); ++ (i))
#define dump(x)  cout << #x << " = " << (x) << endl;
#define pb push_back
#define int long long

const int INF = 1e18;
const int MOD = 1e9+7;
//const lint LINF = 1e18;
const double eps = 0.000000001;//もとの値の10^(-16)まで

using namespace std;

//typedef pair<int, int> P;
//priority_queue< P, vector<P>, greater<P> > q;//ダイクストラの時、greaterで小さい順
//cout << fixed << setprecision(10) << ans << endl;
//int gcd(int a,int b){return b?gcd(b,a%b):a;}


int a[200000];
int b[200000];
signed main(){
  int n,m,v,p;
  cin >> n >> m >> v >> p;
  REP(i,n){
    cin >> a[i];
  }
  sort(a,a+n);
  reverse(a,a+n);


  int left = 0;
  int right = n;
  while(right - left >= 2){
    int v2 = v;
    int mid = (left+right)/2;
    if(mid < p){
      left = mid;
      continue;
    }
    v2 -= p-1;
    v2 -= n-mid;
    if(v2 <= 0 && a[mid] + m-a[p-1]>=0){
      left = mid;
      continue;
    }
    else if(v2 <= 0 && a[mid] + m-a[p-1]<0){
      right = mid;
      continue;
    }
    int nokori = 0;
    int f = 0;
    for(int i = p-1;i<=mid-1;i++){
      int now = a[mid] + m - a[i];
      if(now < 0) f=1;
      nokori += min(now,m);
    }
    if(f==1){
      right = mid;
      continue;
    }
    if(nokori >= m*v2){
      left = mid;
      continue;
    }
    else{
      right = mid;
      continue;
    }
  }
  cout << right << endl;




    return 0;
}