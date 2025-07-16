#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

int n,m;
int map[501][501];

main(){
  fill((int*)map, (int*)(map+sizeof(map)/sizeof(*map)), 0);

  scanf("%d%d", &n, &m);

  if(n==0 && m == 0) return 0;

  int a,b;
  while(m--){
    scanf("%d%d", &a, &b);
    map[a][b] = 1;
    map[b][a] = 1;
  }

  set<int> s;
  for(int i=0;i<501;i++){
    if(map[1][i]){
      s.insert(i);
      for(int j=0;j<501;j++){
	if(map[i][j]){
	  s.insert(j);
	}
      }
    }
  }

  if(s.size())  printf("%d\n", (int)s.size()-1);
  else puts("0");

  main();
}