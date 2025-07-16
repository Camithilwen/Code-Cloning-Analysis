#include <iostream>
#include <vector>

template<typename T>
void Dump(const std::vector<T>& xs)
{
  for (int i = 0; i < xs.size()-1; ++i)
  {
    std::cout << xs[i] << ' ';
  }
  std::cout << xs.back() << std::endl;
}

template<typename T>
int BubbleSort(std::vector<T>* src)
{
  std::vector<T>& xs = *src;
  bool change {true};
  int count = {0};
  while (change) {
    change = false;
    for (int i = xs.size()-1; i > 0; --i)
    {
      if (xs[i] < xs[i-1]) {
        T buf = xs[i];
        xs[i] = xs[i-1];
        xs[i-1] = buf;

        change = true;
        ++count;
      }
    }
  }
  return count;
}

int main()
{
  int n {};
  std::vector<int> xs {};
  std::cin >> n;
  xs.resize(n);
  for (int i = 0; i < n; ++i)
  {
    std::cin >> xs[i];
  }

  int cnt{BubbleSort(&xs)};

  Dump(xs);
  std::cout << cnt << std::endl;

  return 0;
}