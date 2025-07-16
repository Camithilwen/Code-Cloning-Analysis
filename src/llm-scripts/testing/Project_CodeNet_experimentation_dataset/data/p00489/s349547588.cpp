#include<iostream>
using namespace std;

int main(){

  int a, b, c, d, i, j, cnt=1, n;
  int s[100]={ }, r[100];

  cin >> n;

  for (i=0; i<n*(n-1)/2; i++){
    cin >> a >> b >> c >> d;
    if (c>d){
      s[a-1]+=3;
    } else if (c<d){
      s[b-1]+=3;
    } else {
      s[a-1]+=1; s[b-1]+=1;
    }
  }

  for (i=0; i<n; i++){
    for (j=0; j<n; j++){
      if (s[i]<s[j]) cnt++;
    }
    cout << cnt << endl;
    cnt=1;
  }

  return 0;
}