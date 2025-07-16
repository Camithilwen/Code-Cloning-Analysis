#include <set>
#include <cstdio>
using namespace std;

char s[1000000 + 10];

int cnt[3];
char m[128];

int main(){
  scanf("%s", s);
  m['J'] = 0; m['O'] = 1; m['I'] = 2;

  int k = 0;
  for(char *c = s; *c; c++){
    int i = m[*c];

    if(i == 0 && cnt[1] + cnt[2])
      cnt[0] = cnt[1] = cnt[2] = 0;
    if(i == 1 && cnt[2])
      cnt[0] = cnt[1] = cnt[2] = 0;

    cnt[i]++;

    if(i == 2 && cnt[0] >= cnt[1] && cnt[2] >= cnt[1])
      k = max(k, cnt[1]);
  }

  printf("%d\n", k);

  return 0;
}