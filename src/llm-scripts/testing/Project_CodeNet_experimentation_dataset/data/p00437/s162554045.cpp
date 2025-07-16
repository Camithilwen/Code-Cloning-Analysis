#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int a, b, c;
  while (cin >> a >> b >> c) {
    if ((a|b|c) == 0)
      break;

    int N;
    cin >> N;

    vector<int> aa(N), bb(N), cc(N), r(N);
    for (int i = 0; i < N; ++i) {
      cin >> aa[i] >> bb[i] >> cc[i] >> r[i];
      --aa[i];
      --bb[i];
      --cc[i];
    }


    vector<int> ans(a+b+c, 2);
    for (int i = 0; i < N; ++i) {
      if (r[i] == 1)
	ans[aa[i]] = ans[bb[i]] = ans[cc[i]] = 1;
    }

    for (int i = 0; i < N; ++i) {
      if (r[i] == 0) {
	if (ans[aa[i]] == 1 && ans[bb[i]] == 1)
	  ans[cc[i]] = 0;
	else if (ans[aa[i]] == 1 && ans[cc[i]] == 1)
	  ans[bb[i]] = 0;
	else if (ans[bb[i]] == 1 && ans[cc[i]] == 1)
	  ans[aa[i]] = 0;
      }
    }

    for (int i = 0; i < a+b+c; ++i)
      cout << ans[i] << endl;
  }
  return 0;
}