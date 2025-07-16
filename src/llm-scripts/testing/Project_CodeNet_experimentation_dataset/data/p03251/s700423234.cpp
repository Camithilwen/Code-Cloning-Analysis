#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define fo(a,b) for(int a=0;a<b;a++)
#define Sort(a) sort(a.begin(),a.end())
#define rev(a) reverse(a.begin(),a.end())
#define fi first
#define se second
#define bgn begin()
#define sz size()
#define en end()
#define pb push_back
#define pp() pop_back()
#define V vector
#define P pair
#define yuko(a) setprecision(a)
#define uni(a) a.erase(unique(a.begin(),a.end()),a.end())
#define Q queue
#define pri priority_queue
#define Pri priority_queue<int,vector<int>,greater<int>>
#define PriP priority_queue<P<int,int>,vector<P<int,int>>,greater<P<int,int>>>
#define all(a)  (a).begin(),(a).end()
#define ff first.first
#define fs first.second

signed main(){
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  V<int> X(n);
  fo(i,n){
    cin >> X[i];
  }
  V<int> Y(m);
  fo(i,m){
    cin >> Y[i];
  }
  Sort(X);
  Sort(Y);

  int Max_x = X[n-1];
  int Min_y = Y[0];

  bool can = 0;
  for(int i = x+1; i <= y; i++){
    if(Max_x < i && Min_y >= i){
      can = 1;
      break;
    }
  }
  if(can)
    cout << "No War" << endl;
  else
    cout << "War" << endl;
}
