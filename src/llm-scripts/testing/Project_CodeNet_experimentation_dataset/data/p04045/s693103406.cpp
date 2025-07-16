/**
 * ABC042 C
 * 
 * @date 2020.05.03
 * @author 焼き鮭 <yaki-shake@up-tri.me>
 */

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int target;
bool *disallow;

bool is_ok(int target)
{
  int remain_size = std::to_string(target).length();
  while (remain_size != 0)
  {
    int d = target % 10;
    if (disallow[d])
    {
      return false;
    }

    target = target / 10;
    remain_size -= 1;
  }
  return true;
}

int main(int argc, char const *argv[])
{
  int k;

  std::cin >> target;
  std::cin >> k;
  disallow = (bool *)malloc(k * sizeof(bool));

  for (int i = 0; i < k; i++)
  {
    int tmp;
    std::cin >> tmp;
    disallow[tmp] = true;
  }

  int ans = target;
  while (true)
  {
    if (is_ok(ans))
    {
      break;
    }

    ans++;
  }

  cout << ans << endl;
  return 0;
}