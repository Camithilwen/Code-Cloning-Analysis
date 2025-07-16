#include <bits/stdc++.h>

using namespace std;

#define TEMP_T template<typename T>
TEMP_T void sort(T& v){ sort(v.begin(), v.end()); }
TEMP_T void revs(T& v){ reverse(v.begin(), v.end()); }
TEMP_T void uniq(T& v){ sort(v); v.erase(unique(v.begin(), v.end())); }
TEMP_T void show(T& v, char delim=' ', char end='\n'){ for(int i=0; i<v.size()-1; i++) cout << v[i] << delim; cout << v[v.size()-1] << end; }
TEMP_T T    cums(T& v){ T r; r.push_back(v[0]); for(int i=1; i<v.size(); i++) r.push_back(r[i-1] + v[i]); return r; }
TEMP_T void maxe(T& v, T m){ v = max(v, m); }
TEMP_T void mine(T& v, T m){ v = min(v, m); }

static inline int in(){ int x; scanf("%d", &x); return x; }

int main()
{
  int n, m;
  while (n = in(), m = in()){
    vector<int> p;
    for (int i = 0; i < n; i++){
      p.push_back(in());
    }
    p.push_back(0);
    n++;

    vector<int> pp;
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        pp.push_back(p[i] + p[j]);
      }
    }
    int maxi = 0;
    sort(pp);
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        int s = p[i] + p[j];
        int v = *(upper_bound(pp.begin(), pp.end(), m - s) - 1);
        if (s + v <= m){
          maxe(maxi, s + v);
        }
      }
    }
    printf("%d\n", maxi);
  }

  return 0;
}