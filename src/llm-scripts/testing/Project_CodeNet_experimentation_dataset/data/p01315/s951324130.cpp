#include <iostream>
#include <algorithm>
#include <string>
#define N 50
using namespace std;
struct data{
  string l;
  int p,a,b,c,d,e,f,s,m;
  double cal;
};
int main(){
  int n,i,j,time;
  struct data d[N];
  while(1){
    cin >> n;
    if(n==0) break;
    for(i=0;i<n;i++){
      cin >> d[i].l >> d[i].p >> d[i].a >> d[i].b >> d[i].c;
      cin >> d[i].d >> d[i].e >> d[i].f >> d[i].s >> d[i].m;
      time=(d[i].a+d[i].b+d[i].c+d[i].d+d[i].e);
      d[i].m--;
      time+=(d[i].d+d[i].e)*d[i].m;
      d[i].cal=((double)d[i].f*d[i].s*(d[i].m+1)-d[i].p)/time;
    }
    for(i=0;i<n;i++){
      for(j=1;j<n;j++){
	if(d[j].l<d[j-1].l) swap(d[j],d[j-1]);
      }
    }
    for(i=0;i<n;i++){
      for(j=1;j<n;j++){
	if(d[j].cal>d[j-1].cal) swap(d[j],d[j-1]);
      }
    }
    for(i=0;i<n;i++) cout << d[i].l << endl;
    cout << '#' << endl;
  }
  return 0;
}