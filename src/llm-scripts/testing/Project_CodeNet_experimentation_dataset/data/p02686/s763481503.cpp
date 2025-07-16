#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define Rep(i,s,n) for(int i=s;i<n;i++)
#define fi first
#define se second
#define all(c) c.begin(),c.end()
typedef long long int ll;
typedef pair<ll, ll> P;
typedef long double ld;
void Ans(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}

const ll INF=1001001001;
const ll mod=1000000007;

int main(){
  ll n;
  cin>>n;
  string s;
  P a[n];
  vector<P> b,c;
  ll s1,s2;
  
  rep(i,n){
    s1=0;
    s2=0;
    cin>>s;
    rep(j,s.size()){
      if(s[j]=='('){
        s1++;
      }
      else if(s[j]==')'&&s1==0){
        s2++;
      }
      else{
        s1--;
      }
    }
    a[i]=P(s1,s2);
    if(s1-s2>=0) b.push_back(P(s2,s1));
    else c.push_back(P(s1,s2));  
  }
  
  sort(all(b));
  sort(all(c));
  
  s1=0;
  s2=0;
  int ch=0;
  
  rep(i,b.size()){
    s2+=b[i].fi;
    
    if(s1<s2) ch++;
    s1+=b[i].se;
    
    if(s1<s2) ch++;
  }
  
  rep(i,c.size()){
    int j=c.size()-i-1;
    s2+=c[j].se;
    
    if(s1<s2) ch++;
    s1+=c[j].fi;
    
    
    if(s1<s2) ch++;
  }
  
  Ans(ch==0&&s1==s2);
  
  
  
}
  




