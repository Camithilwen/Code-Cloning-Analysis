#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	string s, t;
	cin >> n >> s >> t;

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		string subs = s.substr(i, n - i); //後半を抽出
		string subt = t.substr(0, n - i); //前半を抽出
		if (subs == subt) //抽出した部分がもし重複したら
			cnt = max(cnt, n - i); //重複部分がながければ長いほど最小になるので、長いものをキープ
	}
	cout << 2 * n - cnt << endl; //最大のときは2n。2nから一番長い重複を引く
}