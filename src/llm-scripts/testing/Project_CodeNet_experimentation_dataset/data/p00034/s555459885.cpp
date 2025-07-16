#include<iostream>
#include<cstdio>
using namespace std;
int main(){
  int l[10],v1,v2;
  int result,ans;
  double total, time, distance;

  while(scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",&l[0],&l[1],&l[2],&l[3],&l[4],&l[5],&l[6],&l[7],&l[8],&l[9],&v1,&v2) != EOF){

    total=0;
    for(int i=0; i<10; i++)
      total += l[i];
    time = (double)total/(v1+v2);
    distance = v1 * time;
    result = 0;
    for(ans=0; result < distance; ans++)
      result += l[ans];
    cout << ans << endl;
  }
}