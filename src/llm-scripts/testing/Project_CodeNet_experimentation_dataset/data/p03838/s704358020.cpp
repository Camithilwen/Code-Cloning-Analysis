#include <bits/stdc++.h>
using namespace std;
int main(){
   long x,y;
   cin >> x >> y;
   if(x==y) cout << 0 << endl;
   else if(y-x==1||y==-x) cout << 1 << endl;
   else cout << min({abs(x-y),abs(x+y-1),abs(x+y+1),abs(x-y+2)})+2 << endl;
}
