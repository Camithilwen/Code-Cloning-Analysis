#include <stdio.h>
#define MAXN 105

typedef struct _pair {
  int id, score;
} pair;

int N;
pair arr[MAXN];
int rank[MAXN];

void bubleSort() {
  int i, j;
  pair p;
  for(i = 0; i < N; ++i) {
    for(j = 1; j < N-i; ++j) {
      if(arr[j-1].score < arr[j].score) {
        p = arr[j-1];
        arr[j-1] = arr[j];
        arr[j] = p;
      }
    }
  }
}

int main() {
  int i, j;
  int A, B, C, D;
  scanf("%d", &N);
  for(i = 0; i < N; ++i) {
    arr[i].id = i;
    arr[i].score = 0;
  }
  for(i = 0; i < N*(N-1)/2; ++i) {
    scanf("%d %d %d %d", &A, &B, &C, &D);
    --A; --B;
    if(C == D) {
      arr[A].score += 1;
      arr[B].score += 1;
    } else if(C > D) {
      arr[A].score += 3;
    } else if(C < D) {
      arr[B].score += 3;
    }
  }

  bubleSort();
  for(i = 0, j = 1; i < N; ++i) {
    if(i-1 >= 0 && arr[i].score == arr[i-1].score) {
    } else {
      j = i+1;
    }
    rank[arr[i].id] = j;
  }

  for(i = 0; i < N; ++i) {
    printf("%d\n", rank[i]);
  }

  return 0;
}