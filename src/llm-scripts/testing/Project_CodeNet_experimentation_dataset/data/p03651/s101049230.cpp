# include <iostream>
using namespace std;

int gcd(int a, int b){
  return (b==0) ? a : gcd(b, a%b);
}

int main(){

  int n, k;
  cin >> n >> k;
  
  int g = 0, m = 0;
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    g = gcd(x, g);
    m = max(x, m);
  }

  if(k <= m && k % g == 0) cout << "POSSIBLE";
  else cout << "IMPOSSIBLE";
  cout << endl;
  return 0;
}
