#include <iostream>
#include <string>

typedef long long ll;

void print()
{
  std::cout << std::endl;
}

template<class T>
void print(T param)
{
  std::cout << param << std::endl;
  return;
}

template<class T, class... S>
void print(T param1, S... param2)
{
  std::cout << param1 << " "; print(std::forward<S>(param2)...);
}

int main()
{
  ll A, B, K;
  std::cin >> A >> B >> K;

  for (ll i = 0; i < K; i++) {
    A /= 2;
    B += A;
    std::swap(A, B);
  }

  if (K % 2 == 1) {
    std::swap(A, B);
  }

  print(A, B);
  return 0;
}
