#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const char* sol3[3]={"aab","c.b","cdd"};
const char* sol4[4]={"aacd","bbcd","efgg","efhh"};
const char* sol5[5]={"aabbc","dee.c","d..fg","h..fg","hiijj"};
const char* sol6[6]={"aabbc.","ddeec.",".f.g.h",".f.g.h","i.j.kk","i.j.ll"};
const char* sol7[7]={"aa.bb.c",".dd..ec","f.gg.e.","f...h.i",".j..h.i","kj..ll.","k.mm.nn"};

char ans[1005][1005];

int main() {
  int n;
  scanf("%d",&n);
  if (n<=2) {
  	puts("-1");
  	return 0;
  }
  if (n==3) {
  	for(int i=0;i<3;i++) puts(sol3[i]);
  	return 0;
  }
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++) ans[i][j]='.';
  int d=0;
  while (n-d>=8) {
  	for(int i=0;i<4;i++)
  	  for(int j=0;j<4;j++) ans[d+i][d+j]=sol4[i][j];
  	d+=4;
  }
  if (n-d==4) {
  	for(int i=0;i<4;i++)
  	  for(int j=0;j<4;j++) ans[d+i][d+j]=sol4[i][j];
  }
  else if (n-d==5) {
  	for(int i=0;i<5;i++)
  	  for(int j=0;j<5;j++) ans[d+i][d+j]=sol5[i][j];
  }
  else if (n-d==6) {
  	for(int i=0;i<6;i++)
  	  for(int j=0;j<6;j++) ans[d+i][d+j]=sol6[i][j];
  }
  else {
  	for(int i=0;i<7;i++)
  	  for(int j=0;j<7;j++) ans[d+i][d+j]=sol7[i][j];
  }
  for(int i=0;i<n;i++) puts(ans[i]);
  return 0;
} 