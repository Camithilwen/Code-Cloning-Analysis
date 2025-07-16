#include<bits/stdc++.h>
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

template<typename F>
struct FixPoint : F{
  FixPoint(F&& f):F(forward<F>(f)){}
  template<typename... Args>
  decltype(auto) operator()(Args&&... args) const{
    return F::operator()(*this,forward<Args>(args)...);
  }
};
template<typename F>
inline decltype(auto) MFP(F&& f){
  return FixPoint<F>{forward<F>(f)};
}

__int128_t abs128(__int128_t val){return val<0?-val:val;}

ostream &operator<<(ostream &os,__int128_t val){
  if(ostream::sentry(os)){
    __uint128_t tmp=abs128(val);
    char buf[64];
    char *d=end(buf);
    do{
      --d;
      *d=char(tmp%10+'0');
      tmp/=10;
    }while(tmp);
    if(val<0) *--d='-';
    int len=end(buf)-d;
    if(os.rdbuf()->sputn(d,len)!=len){
      os.setstate(ios_base::badbit);
    }
  }
  return os;
}

istream &operator>>(istream &is,__int128_t &val){
  string s;
  is>>s;
  val=0;
  for(int i=0;i<(int)s.size();i++)
    if(isdigit(s[i])) val=val*10+s[i]-'0';
  if(s[0]=='-') val*=-1;
  return is;
}

//INSERT ABOVE HERE
signed main(){
  using ll = __int128_t;

  ll d;
  cin>>d;
  const ll MAX = 37;
  ll ans=0;

  vector<ll> po(MAX,1);
  for(int i=0;i+1<MAX;i++)
    po[i+1]=po[i]*10;

  vector<ll> c1(12,0),c2(12,0);
  for(int i=1;i<10;i++)
    for(int j=1;j<=i;j++)
      c1[abs(i-j)]++;

  for(int i=0;i<10;i++)
    for(int j=0;j<=i;j++)
      c2[abs(i-j)]++;

  for(int l=2;l<=MAX;l++){
    // [s, t]
    ans+=
      MFP([&](auto dfs,ll s,ll t,ll w)->ll{
            if(s>=t){
              if(w!=0) return 0;
              return s==t?10:1;
            }
            ll dif=po[t]-po[s];
            ll x=w/dif;
            if(x>=10) return 0;

            ll res=0;
            res+=(s==0?c1:c2)[x+0]*dfs(s+1,t-1,abs128(w-(x+0)*dif));
            res+=(s==0?c1:c2)[x+1]*dfs(s+1,t-1,abs128(w-(x+1)*dif));
            return res;
          })(0,l-1,d);
  }
  cout<<ans<<endl;
  return 0;
}
