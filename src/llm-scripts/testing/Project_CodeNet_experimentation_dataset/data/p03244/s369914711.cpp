#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, v;
  cin >> n;
  int* ohash = (int*) calloc(100000, sizeof(int));
  int* ehash = (int*) calloc(100000, sizeof(int));
  for (int i = 0; i < n/2; i++) {
    cin >> v;
    ohash[v - 1]++;
    cin >> v;
    ehash[v - 1]++;
  }
  int omax = 0, emax = 0;
  for (int i = 0; i < 100000; i++) {
    if (ohash[i] > ohash[omax]) omax = i;
    if (ehash[i] > ehash[emax]) emax = i;
  }
  if (omax != emax) {
    cout << n - ohash[omax] - ehash[emax];
  }
  else {
    int omax2 = 0, emax2 = 0;
    for (int i = 0; i < 100000; i++) {
      if (ohash[i] > ohash[omax2] && i != omax) omax2 = i;
      if (ehash[i] > ehash[emax2] && i != emax) emax2 = i;
    }
    if (ohash[omax] == n/2 && ehash[emax] == n/2) {
      cout << n/2;
    }
    else if (ohash[omax] == n/2) {
      cout << n/2 - ehash[emax2];
    }
    else if (ehash[emax] == n/2) {
      cout << n/2 - ohash[omax2];
    }
    else {
      cout << min(n - ohash[omax] - ehash[emax2], n - ohash[omax2] - ehash[emax]);
    }
  }
  free(ohash);
  free(ehash);
  return 0;
}