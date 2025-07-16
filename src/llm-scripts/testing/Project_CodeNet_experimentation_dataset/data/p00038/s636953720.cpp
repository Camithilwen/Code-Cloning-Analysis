
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>

using namespace std;

#define ll long long
#define ld long double
#define EPS 0.0000000001
#define INF 1e9
#define MOD 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define loop(i,a,n) for(i=a;i<n;i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

typedef vector<int> vi;
typedef pair<int,int> pii;

int main(void) {
  int i,j;
  int a,b,c,d,e;
  while(scanf("%d,%d,%d,%d,%d",&a,&b,&c,&d,&e)!=EOF){
    vi v(14,0);
    v[a]++;
    v[b]++;
    v[c]++;
    v[d]++;
    v[e]++;

    bool ans=false;
    if(v[1]&&v[10]&&v[11]&&v[12]&&v[13]){
      cout<<"straight"<<endl;
      ans=true;
    }
    rep(i,10)
      if(v[i]&&v[i+1]&&v[i+2]&&v[i+3]&&v[i+4]){
	cout<<"straight"<<endl;
	ans=true;
      }
    if(ans)continue;

    int na=0,nb=0,nc=0;
    rep(i,14)
      if(v[i]==2)na++;
      else if(v[i]==3)nb++;
      else if(v[i]==4)nc++;

    if(nc)cout<<"four card"<<endl;
    else if(na&&nb)cout<<"full house"<<endl;
    else if(nb)cout<<"three card"<<endl;
    else if(na==2)cout<<"two pair"<<endl;
    else if(na)cout<<"one pair"<<endl;
    else cout<<"null"<<endl;
  END:;
  }
}