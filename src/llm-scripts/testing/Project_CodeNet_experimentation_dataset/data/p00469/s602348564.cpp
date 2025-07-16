#include<cstdio>
#include<set>
using namespace std;

set<int> numbers;
int n, k, cards[10], used[10];

void addcard(int x, int y){
  if(x == 0){
    numbers.insert(y);
  }
  for(int i = 0;i < n;i++){
    if(used[i] == 0){
      int shift = 10;
      if(cards[i] >= 10)shift *= 10;
      used[i] = 1;
      addcard(x - 1, y * shift + cards[i]);
      used[i] = 0;
    }
  }
}

int main(){
  while(1){
    numbers.clear();
    scanf("%d%d", &n, &k);
    if(n == 0 && k == 0)return 0;
    for(int i = 0;i < n;i++){
      used[i] = 0;
      scanf("%d", cards + i);
    }
    addcard(k, 0);
    printf("%d\n", numbers.size());
  }
}