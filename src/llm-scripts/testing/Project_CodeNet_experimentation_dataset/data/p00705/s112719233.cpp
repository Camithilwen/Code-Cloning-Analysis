#include<iostream>
using namespace std;

int m[101];

int main(){
  int n,q;
  int i,j;
  int d,x;
  int max,a,f;
  
  while(1){
    f=0;
    max=-1;
    for(i=0;i<101;i++){
      m[i]=0;
    }
    cin >> n >> q;
    if(n==0 && q==0)break;
    q--;
    for(i=0;i<n;i++){
      cin >> d;
      if(d==0)f=1;
      for(j=0;j<d;j++){
	cin >> x;
	m[x]++;
      }
    }
    a=0;
    for(i=0;i<100;i++){
      if(q<m[i]){
	q=m[i];
	a=i;
      }
      m[i]=0;
    }
    cout << a << endl;
  }
}