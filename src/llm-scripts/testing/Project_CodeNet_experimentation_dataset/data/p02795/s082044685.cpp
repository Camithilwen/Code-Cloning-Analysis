#include <stdio.h>
 
int main() {
  int h, w, g, result;
  scanf("%d %d %d", &h, &w, &g);
  result = (h > w) ? (g+h-1)/h : (g+w-1)/w;
  printf("%d\n", result);
  return 0;
}