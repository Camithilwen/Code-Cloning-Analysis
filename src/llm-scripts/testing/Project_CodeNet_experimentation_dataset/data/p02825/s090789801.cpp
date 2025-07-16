#include<iostream>
#include<vector>
#include<algorithm>

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int N; std::cin >> N;
  char buf[1002];
  buf[N] = '\n';
  buf[N+1] = 0;
  if(N >= 4 && N%2 == 0) {
    char const* p[2] = {"abcc", 
                        "abdd"};
    for(int i = 0; i < N; ++i) {
      int x = (i/2)*2, y = i%2;
      std::fill_n(buf, N, '.');
      for(int j = 0; j < 4; ++j) buf[(x+j)%N] = p[y][j];
      std::cout << buf;
    }
  } else if(N%3 == 0) {
    char const* p[3] = {"aab",
                        "b.b",
                        "baa"};
    for(int i = 0; i < N; ++i) {
      int x = (i/3)*3, y = i%3;
      std::fill_n(buf, N, '.');
      for(int j = 0; j < 3; ++j) buf[(x+j)%N] = p[y][j];
      std::cout << buf;
    }
  } else if(N >= 9 || N==5) {
    char const* p[2] = {"abcc",
                        "abdd"};
    int n = N-5;
    for(int i = 0; i < n; ++i) {
      int x = (i/2)*2, y = i%2;
      std::fill_n(buf, N, '.');
      for(int j = 0; j < 4; ++j) buf[(x+j)%n] = p[y][j];
      std::cout << buf;
    }
    std::fill_n(buf, N, '.');
    char const *q[5] = {"aabba",
                        "cca.a",
                        "bbabb",
                        "..bca",
                        "..bca"};
    for(int i = 0; i < 5; ++i) {
      for(int j = 0; j < 5; ++j) buf[n+j] = q[i][j];
      std::cout << buf;
    }
  } else if(N==7) {
    std::cout << "aa.ab..\n"
                 "...aba.\n"
                 "a....ac\n"
                 "a.aa..c\n"
                 "bb..aab\n"
                 ".aa.b.b\n"
                 "..ccbaa\n";
  } else {
    std::cout << "-1\n";
  }
  return 0;
}


