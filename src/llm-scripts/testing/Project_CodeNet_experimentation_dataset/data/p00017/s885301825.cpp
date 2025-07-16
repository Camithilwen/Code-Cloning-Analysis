#include <cstdio>
#include <cstring>
using namespace std;

int main() {
  char s[100];
  while (fgets(s, sizeof(s), stdin)) {
    while (1) {
      for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'a' && s[i] < 'z') s[i]++;
        else if (s[i] == 'z') s[i] = 'a';
        else if (s[i] == '\n') s[i] = '\0';
      }
      if (strstr(s, "the") || strstr(s, "this") || strstr(s, "that")) break;
    }
    puts(s);
  }
}
