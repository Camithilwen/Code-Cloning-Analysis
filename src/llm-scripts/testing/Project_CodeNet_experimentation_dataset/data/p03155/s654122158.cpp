#include <bits/stdc++.h>
using namespace std;


int main() {


    int64_t n,w,h;
    cin>>n>>h>>w;

    int cnt=0;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        if(n-i+1>=h&&n-j+1>=w)
          cnt++;
      }
    }

    cout<<cnt<<endl;

	return 0;
}