#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

bool includes_keyword(const char *str) {
  const static char *keywords[] = { "the", "this", "that" };
  for (const auto keyword : keywords) {
    const char *pos = strstr(str, keyword);
    if (pos == NULL) { continue; }
    if (pos != str && isalpha(pos[-1])) { continue; }
    if (isalpha(pos[strlen(keyword)])) { continue; }
    return true;
  }
  return false;
}

int main() {
  char *cipher = NULL;
  size_t buffer_size = 0;
  ssize_t len;
  while ((len = getline(&cipher, &buffer_size, stdin)) > 0) {
    if (cipher[len - 1] == '\n') {
      cipher[len - 1] = '\0';
      len -= 1;
    }

    char decoded[81];
    for (int i = 0; i < 26; ++i) {
      strcpy(decoded, cipher);
      for (int j = 0; j < len; ++j) {
        if (islower(decoded[j])) {
          decoded[j] += i;
          if (!islower(decoded[j])) { decoded[j] -= 26; }
        }
      }
      if (includes_keyword(decoded)) { break; }
    }
    puts(decoded);
  }

  free(cipher);

  return 0;
}