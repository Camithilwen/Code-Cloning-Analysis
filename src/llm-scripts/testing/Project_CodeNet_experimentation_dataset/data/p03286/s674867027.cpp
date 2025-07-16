#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
struct edge { ll s, t, x; };
typedef pair<ll, ll> P;
typedef pair<ll,P> event;
#define MOD 1000000007
const int MAX = 510000;


int main(){
  ll N;
  cin>>N;
  ll num=N;
  queue<char>memo;
  for(ll i=35;i>=0;i--){
    if(i%2==0){
      ll k=i/2ll;
      ll upper=((ll)pow(4,k+1)-1ll)/3ll;
      ll neupper=((ll)pow(4,k)-1ll)/3ll;;
      if(neupper<num&&num<=upper){memo.push('1');num-=(ll)pow(2,i);}
      else{memo.push('0');}
    }
    if(i%2==1){
      ll k=i/2ll;
      ll lower=((-2)*((ll)pow(4,k+1)-1ll))/3ll;;
      ll nelower=(-2)*((ll)pow(4,k)-1ll)/3ll;;
      if(lower<=num&&num<nelower){num+=(ll)pow(2,i);memo.push('1');}
      else{memo.push('0');}
    }
  }
  while(!memo.empty()){
    auto t=memo.front();
    if(t=='1'){break;}
    else{memo.pop();}
  }
  if(memo.empty()){cout<<0<<endl;}
  else{
    while(!memo.empty()){
      cout<<memo.front();
      memo.pop();
    }
    cout<<endl;
  }
  
  
}

