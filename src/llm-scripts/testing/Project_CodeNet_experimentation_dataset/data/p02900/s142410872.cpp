#include <bits/stdc++.h>
using namespace std;
#define int long long
using vec_int = vector<int>;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

static long Gcd(long m, long n)
{
	long temp;
	while (m % n != 0)
	{
		temp = n;
		n = m % n;
		m = temp;
	}
	return n;
}

int charToInt(char c){
    char zero_num = '0';
    return (int)c - (int)zero_num;
}


map< int, int > prime_factor(int n) {
  map< int, int > ret;
  for(int64_t i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}


signed main(){
    int A, B;cin>>A>>B;

    int gcd = Gcd(A,B);

/*    vec_int factors;

    for(int i=1;i*i<=gcd;i++){
        if(gcd%i==0){
            factors.push_back(i);
            factors.push_back(gcd/i);
        }
    }
    sort(factors.begin(), factors.end());
    */

   map<int, int> pfs = prime_factor(gcd);

   cout<<pfs.size()+1<<endl;




    

    return 0;
}