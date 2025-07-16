#include <bits/stdc++.h>
using namespace std;

int main() {
   int N, K, x;
   x = 1;
   cin >> N >> K;
   int i=0;
   while (2*x < x+K){
        if (i>=N) {break;}
   		x*=2;
        i++;
   }
   for (int j=0; j<N-i; j++){
     	x+=K;
   }
   cout << x << endl;
}
