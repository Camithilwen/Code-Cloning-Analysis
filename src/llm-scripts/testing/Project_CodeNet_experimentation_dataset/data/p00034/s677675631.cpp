#include <cstdio>
#include <cstdlib>
#include <numeric>

using namespace std;

int main() {
  char *line = NULL;
  size_t buffer_size = 0;
  while (getline(&line, &buffer_size, stdin) > 0) {
    int ls[10];
    int v1, v2;
    sscanf(line, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
           ls, ls+1, ls+2, ls+3, ls+4, ls+5, ls+6, ls+7, ls+8, ls+9,
           &v1, &v2);
    int total_len = accumulate(ls, ls + 10, 0);
    double x1 = v1 * static_cast<double>(total_len) / (v1 + v2);
    for (int i = 0, acc = 0; i < 10; ++i) {
      acc += ls[i];
      if (x1 <= acc) {
        printf("%d\n", i + 1);
        break;
      }
    }
  }
  free(line);

  return 0;
}