#include<iostream>
#include<stdio.h>//printf("%.9f\n",*********);
#include<vector>//文字列.erase(n),vector
#include<algorithm>//next_permutation
#include<set>
#include<string>//char(小文字-32=大文字) to_string,string,char
#include<sstream>
#include<complex>
#include<time.h>
#include<random>
#include<cmath>//min,max
#include<math.h>
#include<queue>
#include<time.h>
#include<iomanip>
#include<locale>
#include<utility>//swap
#define rt "\n"
#define rep(i,n) for(int i=0;i<n;i++)
#define rop(i,n) for(int i=1;i<=n;i++)//start==1
#define drep(i,n) for(int i=n-1;0<=i;i--)
#define drop(i,n) for(int i=n;0<i;i--)//end==1
#define yes(ans) if(ans)cout<<"yes"<<rt;else cout<<"no"<<rt;
#define Yes(ans) if(ans)cout<<"Yes"<<rt;else cout<<"No"<<rt;
#define YES(ans) if(ans)cout<<"YES"<<rt;else cout<<"NO"<<rt;
#define Yay(ans) if(ans)cout<<"Yay!"<<rt;else cout<<":("<<rt;
#define sec(a,b,ans) if(ans)cout<<a<<rt;else cout<<b<<rt;
#define vcin(s,n) rep(i,n)cin>>s[i];//vcin(配列名),(繰り返し回数)
#define sort(s) sort(s.begin(),s.end())//標準=昇順
#define reve(s) reverse(s.begin(),s.end())//反転
#define str string
#define please return
#define AC 0
#define rapid_pleaseAC_fast cin.tie(0);ios::sync_with_stdio(false)
#define pi 3.1415926535897932384626//pi
#define nine 1000000000//10^9

using namespace std;
typedef vector<int> vint;
typedef long double ldouble;
typedef vector<string> vstr;
typedef vector<char> vchar;
typedef vector<double> vdou;
typedef vector<double> vdouble;
typedef long long int llint;
typedef pair<int, int> pint;
typedef pair<llint, llint> pllint;
typedef vector<llint> vllint;
typedef vector<pint> vpint;
typedef vector<pair<llint, llint>> vpllint;
typedef vector<vector<int>> vvint;
typedef vector<vector<char>> vvchar;
typedef vector<vector<double>> vvdouble;
typedef vector<vector<llint>> vvllint;
typedef vector<vector<string>> vvstr;
typedef vector<vector<bool>> vvbool;
typedef vector<vector<pint>> vvpint;
typedef vector<bool> vbool;

long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}

long long LCM(long long a, long long b) {
	return a * b / GCD(a, b);
}

unsigned GetDigit(unsigned num) {
	return std::to_string(num).length();
}

int tow(int n) {//2のn乗
	if (n == 0)return 1;
	int x = tow(n / 2);
	x *= x;
	if (n % 2 == 1)x *= 2;
	return x;//@domino
}

int SED(int n) { //Sum of Each Digit
	int sum = 0;
	while (n > 0) {
		sum += n % 10; n /= 10;
	}
	return sum;
}

unsigned ND(unsigned num) {//Number of Digits
	return std::to_string(num).length();//outmax=10
}//stringのほうが効率よくないか？

/*

 (char)toupper(a[n])=文字列のn文字目を大文字で出力

  pow(a,b)=aのb乗

  */


int main(void) {
	rapid_pleaseAC_fast;
	
	int n, h, w;
	cin >> n >> h >> w;

	int x = n - w + 1;
	int y = n - h + 1;
	
	cout << x * y << rt;

	please AC;
}