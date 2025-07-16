#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int main(){

  int i;
  double x,sum,v1,v2,a[100];

  while(cin >> a[0]){

    sum = 0;

    for(i=1;i<9;i++) scanf(",%lf",&a[i]);
    scanf(",%lf,%lf,%lf",&a[9],&v1,&v2);

    for(i=0;i<10;i++) sum += a[i];
 
    x = sum/(v1+v2);

    sum = v1 * x;

    for(i=0;i<10;i++){
      if(sum - a[i] > 0) sum -= a[i];
      else{
	cout << i+1 << endl;
	break;
      }
    }

  }
}