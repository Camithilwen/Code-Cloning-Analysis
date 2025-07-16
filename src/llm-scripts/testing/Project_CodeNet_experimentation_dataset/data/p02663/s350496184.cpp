#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int a,b,c,d,e;

int main(){
  scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
  printf("%d\n",max(c*60+d-a*60-b-e,0));
  return 0;
}