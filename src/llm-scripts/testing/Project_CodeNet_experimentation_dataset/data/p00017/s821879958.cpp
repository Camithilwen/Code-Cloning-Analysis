#include <cstdio>
#include <bitset>
#include <cmath>
#include <complex>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
#include <sstream>
#define EPS 1e-6

using namespace std;
typedef complex<double> coor;

double cross(coor a, coor b)
{
  return a.real() * b.imag() - a.imag() * b.real();
}

double dot(coor a, coor b)
{
  return a.real() * b.real() + a.imag() * b.imag();
}

int main()
{
  string str;
  while (getline(cin, str)) {
    istringstream is(str);
    string token;
    int n;
    while (is >> token) {
      for (int i = 0; i < 26; i++) {
	string tmp;
	for (int j = 0; j < token.size(); j++) {
	  tmp += (token[j] - 'a' + i) % 26 + 'a';
	}
	//cout << "i = " << i << "tmp = " << tmp << endl;
	if (tmp == "the" || tmp == "this" || tmp == "that") {
	  n = i;
	  goto next;
	}
      }
    }
  next:
    //printf("n = %d\n", n);
    for (int i = 0; i < str.size(); i++) {
      printf("%c", ('a' <= str[i] && str[i] <= 'z') ?(str[i] - 'a' + n) % 26 + 'a' : str[i]);
    }
    printf("\n");
  }
}