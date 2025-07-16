#include <cstdio>

using namespace std;

int main() {
  int n;
  while (scanf("%d", &n), n!=0) {
    int k[100];
    char s[101];
    for (int i=0;i<n;i++) scanf("%d", &k[i]);
    scanf("%s", s);
    for (int i=0;s[i]!='\0';i++) {
      int c = s[i];
      for (int j=0;j<k[i%n];j++) {
        if (c == 'a') c = 'Z';
        else if (c == 'A') c = 'z';
        else c--;
      }
      putchar(c);
    }
    putchar('\n');
  }
  return 0;
}