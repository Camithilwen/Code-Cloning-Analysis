#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
ll x;
cin >> x;
ll n=x%11;
ll m=x/11;
if(n==0)cout<< 2*m << endl;
else if(n<=6)cout << 2*m+1 << endl;
else cout << 2*m+2 << endl;

}

