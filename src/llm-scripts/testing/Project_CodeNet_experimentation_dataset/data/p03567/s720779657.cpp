#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793




int main(){
   string s;
   cin >> s;
   int n=s.size();
   bool a=false;
   rep(i,n-1){
       if(s.at(i)=='A' && s.at(i+1)=='C')a=true;
   } 
   if(a)cout <<  "Yes" << endl;
   else cout << "No" << endl;
}
