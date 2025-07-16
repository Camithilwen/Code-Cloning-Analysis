#include<iostream>
using namespace std;

int main(){

  int a[1111], b[1111], c[1111], d[1111], p[333], n;
  
  while(cin >> a[0] >> b[0] >> c[0], *a+=*b+*c){
    for(int i=332;i;) p[i--] = 2;
    
    cin >> n;
    for(int i=0;i++<n;) cin >> a[i] >> b[i] >> c[i] >> d[i];
    
    for(int i=0;i++<n;){
      for(int j=0;j++<n;){
	if(d[j]) p[a[j]] = p[b[j]] = p[c[j]] = 1;
	else{
	  if(p[a[j]] == 1 && p[b[j]] == 1) p[c[j]] = 0;
	  if(p[a[j]] == 1 && p[c[j]] == 1) p[b[j]] = 0;
	  if(p[b[j]] == 1 && p[c[j]] == 1) p[a[j]] = 0;
	}
      }
    }
    for(int i=0;i<*a;) cout << p[++i] << endl;
  }
  
}