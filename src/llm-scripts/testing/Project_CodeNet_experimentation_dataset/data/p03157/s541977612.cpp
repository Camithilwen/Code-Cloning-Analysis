#include <cstdio>

int h, w, dx[] = {0,0,-1,1}, dy[] = {1,-1,0,0};
long long a, b, ans;
char s[405][405], t;

void dfs(int x, int y){
  char t;
  ((t = s[x][y]) == '#' ? a : b)++;
  s[x][y] = 0;
  for(int i = 0; i < 4; i++) if((s[x+dx[i]][y+dy[i]] | t) > t) dfs(x+dx[i], y+dy[i]);
}

int main(){
  scanf("%d %d\n", &h, &w);
  for(int i = 1; i <= h; i++){scanf("%s", s[i]+1);s[i][w+1] = 0;}
  for(int i = 1; i <= h; i++) for(int j = 1; j <= w; j++)
    if(s[i][j]) a = b = 0, dfs(i,j), ans += a*b;
  printf("%lld\n", ans);
}
