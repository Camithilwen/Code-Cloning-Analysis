#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define forn(i, k, n) for (int i = k+1; i < int(n); i++)
typedef long long LL;
typedef pair<int, int> PII;

int digit(long n){
	int dig = 1;
  	while(n / 10 > 0){
		n /= 10;
      	dig++;
    }  
  	return dig;
}

long search_mul(long small, long big, long n){
    long a,b;
    int i;
    for(i = small + 1; i < big; i++){
        if(n % i == 0){
            a = i;
            b = n/a;
            if(n % (a * small) == 0 && a*small < n/(a*small)){
                a = a * small;
                b = n/a;
                //cout << a << " * " << b << endl;
                return search_mul(a,b,n);
            }
            //cout << a << " * " << b << endl;
            //return min(digit(b), search_mul(a,b,n));
            return search_mul(a,b,n);
        }
    }
    //cout << small << " * " << big << " ,ans :";
    return big;
}
void f(long n) {
  int ans;
  long temp = sqrt(n)+1;
  long ret;

  ret = search_mul(1,temp,n);
  
  if(ret == temp)
    ans = digit(n);
  else
    ans = digit(ret);
  cout << ans << endl; 
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  long n;
  cin >> n;
  f(n);
  return 0;
}