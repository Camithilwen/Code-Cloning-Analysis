#include <cstdio>
using namespace std;

typedef long long int LLI;

LLI d;

int main() {
  while (1) {
    if (scanf("%lld", &d) != 1) break;
    
    LLI ans = 0;
    for (LLI i=0; i<600; i+=d) {
      ans += i*i*d;
    }
    printf("%lld\n", ans);
  }
}