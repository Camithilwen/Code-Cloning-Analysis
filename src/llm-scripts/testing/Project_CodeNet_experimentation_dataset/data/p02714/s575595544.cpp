#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int64_t gcd(int64_t a,int64_t b){return (a%b==0?b:gcd(b, a%b));}
int64_t lcm(int64_t a,int64_t b){return a/gcd(a, b)*b;}
int factorial(int a){int b=1;while(a){b*=a--;}return b;} //13以下対応
bool is_prime(int64_t a){if(a<=1)return false;for(int64_t i=2;(int64_t)i*i<=a;i++){if(a%i==0)return false;}return true;}
int get_adp(double x, int n){return (int)round((x-(int)x)*pow(10,n))%10;} // 小数点以下の指定桁の値を取得
int64_t sigma(int64_t s, int64_t n){return n*(2*s+n-1)/2;}

//順列の全列挙
// vector<int> v(N);
// iota(v.begin(), v.end(), 1);       // v に 1, 2, ... N を設定
// do {
//	for(auto x : v) cout << x << " "; cout << "\n";     // v の要素を表示
// } while( next_permutation(v.begin(), v.end()) ); 

//bit全探索
// for (int tmp = 0; tmp < (1 << ビット数); tmp++) {
//	bitset<ビット数> s(tmp);
//	// (ビット列sに対する処理)
// }



int main()
{
	int64_t ans = 0;
	int n, temp, r = 0, g = 0, b = 0;
	string s;

	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'R')
			r++;
		else if (s[i] == 'G')
			g++;
		else
			b++;
	}
	ans = (int64_t)r * g * b;
	for (int i = 1; i <= n / 2; i++)
	{
		for (int j = i; j < n - i; j++)
		{
			if (s[j] != s[j - i] && s[j] != s[j + i] && s[j - i] != s[j + i])
				ans--;
		}
	}
	ans = (ans < 0 ? 0 : ans);
	// cout << r << " " << g << " " << b << endl;
	// cout << r * g * b << endl;
	cout << ans << endl;
}
