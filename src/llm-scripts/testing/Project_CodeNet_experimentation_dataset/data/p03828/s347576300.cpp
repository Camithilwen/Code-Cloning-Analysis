#include <iostream>
#include <cmath>

using namespace std;

bool isprime(int n)	{
  for (int i = 2; i * i <= n; i++)	{
    if (n % i == 0)
      return false;
  }
  return true;
}

int log(int base, int num)	{
  int temp = 0;
  int base1 = base;
  while (num / base1 > 0)	{
	temp += num / base1;
    base1 *= base;
  }
  return temp;
}

int main()	{
  int n;
  cin >> n;
  long long result = 1;
  for (int i = 2; i <= n; i++)	{
    if (isprime(i))	{
	  result = (result * (log(i, n) + 1)) % 1000000007;
    }
  }
  cout << result << endl;
  return 0;
}