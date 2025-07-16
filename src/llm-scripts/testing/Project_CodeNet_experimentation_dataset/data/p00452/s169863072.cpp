#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1<<30;

int N,M;

int main(){
  while(scanf("%d%d", &N,&M) && N||M){
    vector<int>a,v;
    a.push_back(0);
    for(int i=0;i<N;i++){
      int x;scanf("%d", &x);
      a.push_back(x);
    }
    for(int i=0;i<=N;i++) for(int j=0;j<=N;j++){
	if(a[i]+a[j] <= M) v.push_back(a[i]+a[j]);
    }
    v.push_back(INF);

    sort(v.begin(), v.end());
    int res = 0;
    for(int i=0;i<v.size()-1;i++){
      int x = M-v[i];
      vector<int>::iterator it = upper_bound(v.begin(), v.end(), x); if(it != v.begin()) it--;
      res = max(res, v[i] + *it);
    }
    printf("%d\n", res);
  }
  return 0;
}