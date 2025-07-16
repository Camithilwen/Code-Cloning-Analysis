#include <stdio.h>

int main() {
  char str[31], ctr = 0;
  scanf("%[^\n]", str);

  for(int i = 0; str[i] != '\0'; i++) {
    if(str[i] == ' ' && str[i-1] == str[i+1]) {
      ctr++;
    }
  }
  if(ctr == 2) {
    puts("YES");
  }
  else {
    puts("NO");
  }
  return 0;
}