#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int n, m, in[1001], data[1002001];

main(){
  while(scanf("%d %d", &n, &m) && (n|m)){
    in[0] = 0;
    for(int i=1;i<=n;i++) scanf("%d", &in[i]);
    for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) data[i*(n+1)+j] = in[i] + in[j];
    int size = (n+1)*(n+1), ans = 0;
    sort(data, data+size);
    for(int i=0;i<size;i++){
      int l = 0, r = size-1;
      while(r-l>1){
        int med = (l+r) / 2;
        if(data[i] + data[med] <= m) l = med;
        else r = med;
      }
      if(data[i] + data[l] <= m) ans = max(ans, data[i] + data[l]);
    }
    printf("%d\n", ans);
  }
}