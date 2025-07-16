#include <stdio.h>
#include <stdlib.h>

unsigned gaps[] = {1,8,23,77,281,1073,4193,16577,65921,262913,1050113};
// generated from pow(4,i)+3*pow(2,i-1)+1 (prefixed with 1)

unsigned insertion_sort(unsigned a[], unsigned n, unsigned gap){
  unsigned i,count = 0;
  for(i = gap; i < n; i++){
    unsigned v = a[i];
    int j = i - gap;
    while(j >= 0 && a[j] > v){
      a[j+gap] = a[j];
      j -= gap;
      count++;
    }
    a[j+gap] = v;
  }
  return count;
}

void shell_sort(unsigned a[], unsigned n){
  int i;
  unsigned gap_num = 0;
  while(gaps[++gap_num] < n);
  gap_num--;

  unsigned count = 0;
  for(i = gap_num; i >= 0; i--) count += insertion_sort(a,n,gaps[i]);

  printf("%u\n",(gap_num+1));

  for(i = gap_num; i; i--) printf("%u ",gaps[i]);
  printf("%u\n",gaps[0]);

  printf("%u\n",count);
}

int main(){
  unsigned n,i;
  scanf("%u",&n);
  unsigned* a = (unsigned*)malloc(sizeof(unsigned)*n);
  for(i = 0; i < n; i++) scanf("%u",&a[i]);
  shell_sort(a,n);
  for(i = 0; i < n; i++) printf("%u\n",a[i]);
  free(a);
  return 0;
}