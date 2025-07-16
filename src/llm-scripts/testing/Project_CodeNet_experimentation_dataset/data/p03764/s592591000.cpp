#include <iostream>
#include <vector>
#include<list>
#include <algorithm>
#include <string>
#include <math.h>
#include<map>
#include <utility>

#include<queue>
using namespace std;
#define REP(i,k,n) for(int i=k;i<n;i++)
 
#define INF 1844674407370955161
typedef long long unsigned int ll;
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
#define MOD 1000000007

template<typename T>
int vector_finder(std::vector<T> vec, T number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
}

template<typename T>
T gcd(T a,T b){
	if(b>0){
		return gcd(b, a % b);
	}else{
		return a;
	}
}

template<typename T>
T lcm(T a,T b){
	T g = gcd(a, b);
	return a * b / g;
}

void clear( std::queue<pair<int,int> > &q )
{
   std::queue<pair<int,int> > empty;
   std::swap( q, empty );
}
bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}
template<typename T>
std::vector<T> enum_div(T n)//nの約数を列挙
{
	std::vector<T> ret;
	for(T i=1 ; i*i<=n ; ++i)
	{
		if(n%i == 0)
		{
			ret.push_back(i);
			if(i!=1 && i*i!=n)
			{
				ret.push_back(n/i);
			}
		}
	}
	return ret;
}



int main()
{

  int n, m;
  long long xans=0;
  long long yans = 0;
  cin >> n >> m;
  REP(i,1,n+1){
    long long x;
    cin >> x;
    xans += (2 * i - n - 1) * x;
  }
  REP(i,1,m+1){
    long long y;
    cin >> y;
    yans += (2 * i - m - 1) * y;
  }
  xans %= MOD;
  yans %= MOD;
  ll ans = xans * yans % MOD;
  cout << ans << endl;

  return 0;
}