/*
 * Author : Andrew J
*/
#include <bits/stdc++.h>
using namespace std;
#define rall(x) x.rbegin() , x.rend()
#define all(x) x.begin() , x.end()
#define fi first
#define se second
#define pb push_back
using ll = long long;
using ii = pair <int , int>;
void in(int &x);
const int N = 1050;
#define singleCase
// #define multipleCase
int n,m,a,b;
string grid[N];

void work() {
   cin >> n >> m >> a >> b;
   string s = "";
   for (int i = 1 ; i <= a ; i++) {
      s += "1";
   }
   for (int i = 1 ; i <= m - a ; i++) {
      s += "0";
   }
   for (int i = 1 ; i <= b ; i++) {
      grid[i] = s;
   }
   for (int i = 0 ; i < m ; i++) {
      s[i] = s[i] == '0' ? '1' : '0';
   }
   for (int i = b + 1 ; i <= n ; i++) {
      grid[i] = s;
   }
   for (int i = 1 ; i <= n ; i++) {
      for (int j = 0 ; j < m ; j++) {
         printf("%c" , grid[i][j]);
      } puts("");
   }
   return;
}

int main() {
   #ifdef multipleCase
      int nQ; in(nQ);
      while (nQ--)
         work();
   #endif
   #ifdef singleCase
      work();
   #endif
   return 0;
}

void in(int &x) {
	bool neg = false;
	register int c;
	x = 0;
	c = getchar();
	if(c == '-') {
		neg = true;
		c = getchar();
	}
	for (; c > 47 && c < 58; c = getchar())
	  x = (x << 1) + (x << 3) + c - 48;
	if (neg) x *= -1;
}
