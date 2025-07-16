#include <bits/stdc++.h>
using namespace std;
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0583

template<typename T>
vector< T > divisor(T n) {
  vector< T > ret;
  for(T i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}

template<typename T>
T gcd(T a, T b){
    if (b==0) return a;
    else return  gcd(b,a%b);
}




int main(){
    int n;
    int a,b,c;
    cin >> n;
    vector<int> ret;
    if (n==2){
        cin >> b >> c;
        int a = gcd<int>(b,c);
        ret = divisor<int>(a);
    }else if (n==3){
        cin >> a >> b >> c;
        int k = gcd<int>(a,gcd<int>(b,c));
        ret = divisor<int>(k);
    }
    for(const int &p :ret){
        printf("%d\n",p);
    }
    
}
