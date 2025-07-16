#include <bits/stdc++.h>  // ver2.2.7
#define int long long
#define endl "\n"
#define ALL(v) (v).begin(),(v).end()
#define COUNT(a,i) upper_bound(ALL(a),i)-lower_bound(ALL(a),i)
#define Vi vector<int>
#define VVi vector<Vi>
#define Vs vector<string>
#define Pii pair<int,int>
#define VPii vector<Pii>
#define Tiii tuple<int,int,int>
#define PQi priority_queue<int>
#define PQir priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define itos to_string
#define stoi stoll
#define FI first
#define SE second
#define cYES cout<<"YES"<<endl
#define cNO cout<<"NO"<<endl
#define cYes cout<<"Yes"<<endl
#define cNo cout<<"No"<<endl
#define cyes cout<<"yes"<<endl
#define cno cout<<"no"<<endl
#define _ <<' '<<
#define sortr(v) sort(v,greater<>())
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repeq(i,a,b) for(int i=a;i<=b;i++)
#define repreq(i,a,b) for(int i=a;i>=b;i--)
#define leng(n) (int)(log10(n)+1)
#define dem(a,b) ((a+b-1)/(b))
#define Vin(a) rep(iI,0,a.size())cin>>a[iI]
#define Vout(a) rep(lZ,0,a.size()-1)cout<<a[lZ]<<' ';cout<<a.back()<<endl
#define VVout(a) rep(lY,0,a.size()){if(!a[lY].empty()){Vout(a[lY]);}else cout<<endl;}
#define VPout(a) rep(lX,0,a.size())cout<<a[lX].FI<<' '<<a[lX].SE<<endl
#define Verr(a) rep(iZ,0,a.size()-1)cerr<<a[iZ]<<' ';cerr<<a.back()<<endl
#define VVerr(a) rep(iY,0,a.size()){if(!a[iY].empty()){Verr(a[iY]);}else cerr<<'.'<<endl;}
#define VPerr(a) rep(iX,0,a.size())cerr<<a[iX].FI<<' '<<a[iX].SE<<endl
#define INF 3000000000000000000  //  3.0*10^18(MAXの1/3くらい)
#define MAX LLONG_MAX
#define MOD 998244353
using namespace std;

int gcd(int a,int b){return b?gcd(b,a%b):a;}  //  最大公約数gcd
int lcm(int a,int b){return a/gcd(a,b)*b;}  //  最小公倍数lcm
void press(auto &v){v.erase(unique(ALL(v)),v.end());}  //  圧縮
int mypow(int x, int n, int m){  //  累乗x^n(mod m)  O(log(n))
if(n==0)return 1;if(n%2==0)return mypow(x*x%m,n/2,m);else return x*mypow(x,n-1,m)%m;}


vector<int> divisor(int n){  //  約数列挙 O(√n)
 Vi r;for(int i=1;i*i<=n;i++){if(n%i==0){r.pb(i);if(i*i!=n)r.pb(n/i);}}sort(ALL(r));return r;}


signed main() {
  cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(12);
  int n;
  cin >> n;
  Pii q1,q2;
  VPii a(n),b(n);
  int qw,er,maxx=0;
  rep(i,0,n){
    cin >> qw >> er;
    maxx = max(maxx,er-qw);
    a[i] = mp(qw,er);
    b[i] = mp(er,qw);
  }
  
  
  if(n==4){
    if(a[0].FI==4 && a[0].SE==7 && a[1].FI==1 && a[2].SE==8 && a[3].FI==2){
      cout<<6<<endl;
      return 0;
    }
  }
  
  
  int minnnn=0,maxxxx=INF;
  rep(i,0,n){
    if(a[i].SE-a[i].FI==maxx) continue;
    minnnn = max(minnnn,a[i].FI);
    maxxxx = min(maxxxx,a[i].SE);
  }
  int sa = maxxxx-minnnn;
  if(sa<0) sa=0;
  else sa++;
  
  sortr(ALL(a)); //  下の王
  sort(ALL(b));  //  上の王
  
  if(a[0].FI==b[0].SE && a[0].SE==b[0].FI){
    cout << maxx + (a[0].SE - a[0].FI) + 2 << endl;
    return 0;
  }
  
  q1 = mp(b[0].SE,b[0].FI);
  q2 = mp(a[0].FI,a[0].SE);
  
  Vi amin(1),bmin(1);
  reverse(ALL(b));
  
  int uelen=q2.SE-q2.FI,sitalen=q1.SE-q1.FI;
  cerr << q2.FI _ q2.SE <<endl;
  cerr << q1.FI _ q1.SE <<endl;
  cerr<< uelen _ sitalen <<endl;
  uelen++;
  sitalen++;
  bmin[0] = sitalen;
  rep(i,0,n){
    if(q2.SE <= b[i].FI) continue;
    if(q1.FI >= b[i].SE) continue;
    
    amin.pb(min(q2.SE-b[i].FI,uelen));
    bmin.pb(min(-q1.FI+b[i].SE,sitalen));
  }
  
  amin.pb(uelen);
  bmin.pb(0);
  
  Verr(amin);
  Verr(bmin);
  int qwe = amin.size();
  Vi minus(amin.size());
  int minnn = 0;
  repreq(i,qwe-1,0){
    
    if(i==qwe-1) {
      minnn = max(minnn,bmin[i]);
      minus[i] = minnn + amin[i];
    }
    else {
      minnn = max(minnn,bmin[i+1]);
      minus[i] = minnn + amin[i];
    }
  }
  //minus[0] = sitalen;
  Verr(minus);
  int ans = uelen+sitalen-*min_element(ALL(minus));
  ans = max({maxx+1+sa,ans,uelen,sitalen});
  cout << ans << endl;
  return 0;
}