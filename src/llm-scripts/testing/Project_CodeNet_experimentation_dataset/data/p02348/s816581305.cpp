#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INIVAL 2147483647

int *a, *ts, c, s, t, v;

void update(int k, int l, int r)
{
  if (r<s || t<=l) return;
  if (s<=l && r<=t) {
    a[k] = v;
    ts[k] = c;
  } else if (l<r-1) {
    update(((k+1)<<1)-1, l, (l+r)>>1);
    update((k+1)<<1, (l+r)>>1, r);
  }
}

int main()
{
  int i, k, n, z, w, latest;
  char *p,buf[64] = {0};
  buf[62] = '\n';
  fgets(buf, 64, stdin);
  for (n=0,p=buf; *p>' '; n=n*10+*(p++)-'0');
  w = n>1 ? pow(2,(int)ceil(log2(n)))-1 : 1;
  ts = (a = (int*)malloc((w+n)*2*sizeof(int))) + w+n;
  for (i=0; i<w+n; i++)  ts[i] = -1;
  a[0] = INIVAL;
  ts[0] = 0;
  c = 0;
  while (fgets(buf, 64, stdin)) {
    for (s=0,p=buf+2; *p>' '; s=s*10+*(p++)-'0');
    if (*buf=='0') { // update(s, t, x)
      for (t=0,p++; *p>' '; t=t*10+*(p++)-'0');
      for (v=0,p++; *p>' '; v=v*10+*(p++)-'0');
      t++;
      update(0, 0, w+1);
      c++;
    } else { // find(x) x->s
      latest = -1;
      for (k=w+s; ; k=(k-1)>>1) {
	if (ts[k]>latest) {
          latest = ts[k];
          z = a[k];
        }
	if (k==0) break;
      }
      if (z<10) {
	putc_unlocked('0'+z, stdout);
	putc_unlocked('\n', stdout);
      } else {
        for (i=62; z>0; buf[--i]='0'+z%10,z/=10);
        fputs(buf+i, stdout);
      }
    }
  }
  return 0;
}

