#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  long double n,m,d;
  cin>>n>>m>>d;
  if(d==0){
    cout<<fixed<<setprecision(10);
    cout<<(m-1)/n<<endl;
    return 0;
  }
  cout<<fixed<<setprecision(10);
  cout<<(2*(n-d)*(m-1))/(n*n)<<endl;
}