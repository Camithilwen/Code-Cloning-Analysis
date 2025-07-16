#include <bits/stdc++.h>
using namespace std;

long long mod = 1000000007;

class UnionFind
{
public:
   vector<int> parent;
   UnionFind(int N)
   {
      for (int i = 0; i < N; i++)
      {
         parent.push_back(-1);
      }
   }
   int root(int A)
   {
      if (parent[A] < 0)
         return A;
      return parent[A] = root(parent[A]);
   }
   int size(int A)
   {
      return -parent[root(A)];
   }

   bool unite(int A, int B)
   {
      A = root(A);
      B = root(B);
      if (A == B)
         return false;
      if (size(A) < size(B))
         swap(A, B);
      parent[A] += parent[B];
      parent[B] = A;
      return true;
   }
};
vector<pair<long long, long long>> prime(long long N)
{
   vector<pair<long long, long long>> res;
   for (long long i = 2; i * i <= N; i++)
   {
      if (N % i != 0)
         continue;
      long long ex = 0;
      while (N % i == 0)
      {
         ex++;
         N = N / i;
      }
      res.push_back({i, ex});
   }
   if (N != 1)
      res.push_back({N, 1});
   return res;
}
int main(void)
{
   long long A, B;
   cin >> A >> B;
   vector<pair<long long, long long>> PA = prime(A);
   vector<pair<long long, long long>> PB = prime(B);
   map<long long, long long> result;
   for (int i = 0; i < PA.size(); i++)
   {
      result[PA[i].first]++;
   }
   for (int i = 0; i < PB.size(); i++)
   {
      result[PB[i].first]++;
   }
   long long count = 1;
   for (auto ans : result)
   {
      if (ans.second == 2)
         count++;
   }
   cout << count << endl;
   return 0;
}
