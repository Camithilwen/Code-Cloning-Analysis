#include <iostream>
#include <vector>

using namespace std;

void abc_150a();

void abc_151a();

void abc_152a();

void abc_154a();

void abc_156a();

int main()
{
  //abc_150a();
  //abc_151a();
  //abc_152a();
  //abc_154a();
  abc_156a();

}

void abc_150a()
{
  int K, X;
  cin >> K >> X;

  if (500 * K >= X) cout << "Yes\n";
  else cout << "No\n";
}

void abc_151a()
{
  char C;
  cin >> C;

  cout << (char)((int)C + 1) << "\n";
}

void abc_152a()
{
  int N, M;
  cin >> N >> M;
  if (N == M) cout << "Yes\n";
  else cout << "No\n";
}

void abc_154a()
{
  string S, T;
  cin >> S >> T;
  int a, b;
  cin >> a >> b;
  string U;
  cin >> U;

  if (S == U) cout << a - 1 << " " << b << "\n";
  else cout << a << " " << b - 1 << "\n";

}


void abc_156a()
{
  int N, R;
  cin >> N >> R;

  if (N >= 10) cout << R << "\n";
  else cout << R + 100 * (10 - N) << "\n";
}