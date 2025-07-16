#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long i64;

int D, len = 0;
i64 pw[20], result = 0;

void work(int x, int L, i64 rest, i64 way) {
  if (x == L / 2) {
    if (rest == 0) result += way * ((L & 1) ? 10 : 1);
    
    return;
  }

  if ((L & 1) && x == L / 2) {
    work(x + 1, L, rest, way * 9);
  } else {
    if (pw[L - x - 1] - pw[x] > 0) {
      for (int i = -9; i <= 10; ++i) {
	if ((pw[L - x - 1] - pw[x]) * i > rest) {
	  if (i != 10) work(x + 1, L, rest - (pw[L - x - 1] - pw[x]) * i, way * (9 - abs(i) + (x != 0)));
	  if (i > -9) work(x + 1, L, rest - (pw[L - x - 1] - pw[x]) * (i - 1), way * (9 - abs(i - 1) + (x != 0)));
	  break;
	}
      }
    } else {
      for (int i = 9; i >= -10; --i) {
	if ((pw[L - x - 1] - pw[x]) * i > rest) {
	  if (i != -10) work(x + 1, L, rest - (pw[L - x - 1] - pw[x]) * i, way * (9 - abs(i) + (x != 0)));
	  if (i < 9) work(x + 1, L, rest - (pw[L - x - 1] - pw[x]) * (i + 1), way * (9 - abs(i + 1) + (x != 0)));
	  break;
	}
      }
    }
  }
  
}

int main() {
  scanf("%d", &D);
  
  pw[0] = 1;

  for (int i = 1; i < 20; ++i) pw[i] = pw[i - 1] * 10;

  for (int i = 18; i; --i)
    work(0, i, D, 1);

  printf("%lld\n", result);
  return 0;
}
