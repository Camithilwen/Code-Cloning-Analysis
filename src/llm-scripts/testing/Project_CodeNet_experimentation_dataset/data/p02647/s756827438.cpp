#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define vec vector
#define fi first
#define se second
#define eb emplace_back
#define ef emplace_front
#define pof pop_front()
#define pob pop_back()
#define Rep(i,n) for(li i=0,nn=(li)(n);i!=nn;++i)
#define Rep1(i,n) for(li i=1,nn=(li)(n)+1;i!=nn;++i)
#define Size(v) (li)(v.size())
#define SortA(v) sort(v.begin(),v.end())
#define SortD(v) sort(v.rbegin(),v.rend())
#define All(a) (a).begin(),(a).end()
#define Input(a) for(li ii=0,nn=(li)(a.size());ii!=nn;++ii){cin>>(a).at(ii);}
#define Input2(a,b) for(li ii=0,nn=(li)(a.size());ii!=nn;++ii){cin>>(a).at(ii)>>(b).at(ii);}
#define mp make_pair
using li = int64_t;
using intl = int64_t;
using vi = vec<li>;
using vb = vec<bool>;
using vvi = vec<vi>;
using qi = deque<li>;
using pi = pair<li,li>;
using vpi = vec<pi>;
using si = set<li>;
using vsi = vec<si>;
using mii = map<li,li>;
using vmii = vec<mii>;
vec<li> dx = {0, 1, 0, -1, 1, 1, -1, -1};
vec<li> dy = {1, 0, -1, 0, 1, -1, 1, -1};
constexpr li INF = 9223372036854775807;

void Yes(li b){
  if(b)cout<<"Yes";
  else cout<<"No";
}
void yes(li b){
  if(b)cout<<"yes";
  else cout<<"no";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cout.precision(16);

  li N=200000,K=41;
  cin >>N>>K;

  vector<int> A(N,0),B(N,0);
  
  if(K>41){
    Rep(i,N){
      cout<<N<<' ';
    }
    return 0;
  }

  Input(A);

  li l,r;
  Rep(j,K){
  Rep(i,N){
  	l=max(0L,i-A[i]);
  	r=min(N-1,i+A[i]);
  	B[l]++;
  	if(r+1<N){B[r+1]--;}
  }
  Rep1(i,N-1){
  	B[i]+=B[i-1];
  }
  Rep(i,N){
  	A[i]=B[i];
  	B[i]=0;
  }
}

for(auto&& a:A){
	cout<<a<<' ';
}

}