#include <stdio.h>

int main(){
  
  int l, r, ll, rr, minn;
  
  scanf("%d%d", &l, &r);

  ll = l % 2019;
  rr = r % 2019;
  
  minn = 2019;
  if(r - l > 2019) rr += 2019;

  for (int i=ll;i<rr;i++){
      for (int j=ll+i-ll+1;j<rr+1;j++){
          if(minn > i * j % 2019){
              minn = i * j % 2019;
          }
      }
  }
  printf("%d\n", minn);
  return 0;
}
