#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,a,b) for(ll i=a ; i<b ; i++)
const int max_n = 1e5;
const ll mod = 1e9+7;
const ll INF = 1LL<<60;
typedef long double ld;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
ll gcd(ll a, ll b) { return a ? gcd(b%a, a) : b; }
bool betemp(string sleft, string sright, int left, int right){
  if(sleft==sright){
    return (right-left)%2 == 1;
  }else{
    return (right-left)%2 == 0;
  }
}
void solve(int N){
  string vct = "Vacant";
  string sleft, sright, str;
  int left=0, right=N/2;
  cout << left << endl;
  cin >> sleft;
  if(sleft==vct) return ;
  cout << right << endl;
  cin >> sright;
  if(sright==vct) return ;
  if(!betemp(sleft, sright, left, right)){
    swap(sleft, sright), left = right, right = N;
  }
  while(left+1<right){
    int mid = (left+right)/2;
    cout << mid << endl;
    cin >> str;
    if(str==vct) return;
    if(betemp(sleft, str, left, mid)){
      sright = str, right = mid;
    }else{
      left = mid, sleft = str;
    }
  }
}
int main(){
  int N;
  while(cin>>N) solve(N);
  return 0;
}
