#include <iostream>
#include <algorithm>

std::vector<size_t> gaps = {1};

template <typename T>
size_t insertion_sort(T a[], size_t n, size_t gap = 1){
  size_t count = 0;
  for(size_t i = gap; i < n; i++){
    T v = a[i];
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

void make_gap_table(size_t n){
  size_t h = 4;
  while(h < n){
    gaps.push_back(h);
    h = 3*h + 1;
  }
}

template <typename T>
void shell_sort(T a[], size_t n){
  make_gap_table(n);
  size_t count = 0;
  for(auto it = gaps.rbegin(); it != gaps.rend(); it++){
    count += insertion_sort(a,n,*it);
  }

  std::cout << gaps.size() << '\n';

  for(auto it = gaps.rbegin(); it != std::prev(gaps.rend()); it++){
    std::cout << *it << ' ';
  }
  std::cout << *(std::prev(gaps.rend())) << '\n';

  std::cout << count << '\n';
}

int main(){
  size_t n;
  size_t buf;
  std::vector<size_t> a;
  std::cin >> n;
  for(size_t i = 0; i < n; i++){
    std::cin >> buf;
    a.push_back(buf);
  }

  shell_sort(a.data(),a.size());
  for(auto &v : a){
    std::cout << v << '\n';
  }
}