#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9;

void insertion_sort(vector<int>& A, int n, int g, int& cnt)
{
  for (int i = g; i < n; ++i) {
    int key = A[i];
    int j = i - g;
    while (j >= 0 && A[j] > key) {
      A[j + g] = A[j];
      j -= g;
      ++cnt;
    }
    A[j + g] = key;
  }
}

void shell_sort(vector<int>& A, int n, int& cnt)
{
  vector<int> G;
  int h = 1;
  G.push_back(h);
  int upper = n / 2;
  // if (n >= 1000) { upper = n / 9; }
  // else if (n >= 100) { upper = n / 7; }
  for (int i = 3 * h + 1; i < upper; i = 3 * i + 1) {
    G.push_back(i);
  }
  reverse(G.begin(), G.end());
  int m = G.size();
  fprintf(stdout, "%d\n", m);
  for (int i = 0; i < m; ++i) {
    if (i) { fprintf(stdout, " "); }
    fprintf(stdout, "%d", G[i]);
  }
  fprintf(stdout, "\n");
  for (int i = 0; i < m; ++i) {
    insertion_sort(A, n, G[i], cnt);
  }
}

int main()
{
  int n = 0;
  fscanf(stdin, "%d", &n);
  vector<int> A(n);
  for (int i = 0; i < n; ++i) {
    fscanf(stdin, "%d", &A[i]);
  }
  int cnt = 0;
  shell_sort(A, n, cnt);
  fprintf(stdout, "%d\n", cnt);
  for (int i = 0; i < n; ++i) {
    fprintf(stdout, "%d\n", A[i]);
  }
  return 0;
}